#include "gui/utils/BallMechanic.hpp"

#include <cmath>
#include <cassert>

#include <touchgfx/Drawable.hpp>

#include "gui/common/Configuration.hpp"
#include "gui/utils/Geometry.hpp"
#include "gui/utils/BallGeometry.hpp"
#include "gui/utils/QuadraticSolve.hpp"
#include "gui/utils/LinearSolve.hpp"

const double BallMechanic::BALL_K = 3.0/5.0;

void BallMechanic::init(const Config::PhysicsCofig_t &cfg, touchgfx::Drawable * widget) {
	assert(widget);
	_GravityAcc = cfg.GravityAcceleration;
	_Scale = cfg.Scale;
	_Widget = widget;
}

void BallMechanic::setTrajectory(touchgfx::Point * data, std::size_t points_numb) {
	assert(_Widget);
	const double r = _Widget->getWidth() / 2.0;
	BallGeometry::correction(data, points_numb, r);
	_Trajectory = data;
	_DataSize = points_numb;
	reset();
}

void BallMechanic::processing(double sec) {
	while (sec) {
		// TODO:: the algorithm is too complex try to simplify.
		// Note: it is possible to have large delta in time (ten or more seconds), 
		// the algorithm should handle this correctly.
		const auto sin_slope = std::sin(Geometry::getSlopeAngle(_Trajectory[_Step], _Trajectory[_Step + 1]));
		const auto acc = BALL_K * _GravityAcc * sin_slope;
		double time_to_end = calculateBoundary(sec, acc);
		if (sec < time_to_end) {
			time_to_end = sec;
		} 
		sec -= time_to_end;
		const auto delta_v = acc * time_to_end;
		const auto delta_s = (_Speed + delta_v * 0.5) * time_to_end *_Scale;
		_Speed += delta_v;
		_S += delta_s;
		if (sec) {
			processingTrajectoryState();
		}
	}
	_Current = Geometry::getLinePoint(_Trajectory[_Step], _Trajectory[_Step + 1], _S);
	_Widget->moveTo(_Current.x, _Current.y);
}

double BallMechanic::calculateBoundary(double t, double acc) {
	const auto dist_to_end = (_Backward ? _S : (_StepLenght - _S)) / _Scale;
	double time_to_end = t;
	if (dist_to_end) {
		if (acc) {
			acc *= _Backward ? -1 : 1;
			const QuadraticSolve::Value_t t_to_s0 = QuadraticSolve::solver(acc*0.5, std::abs(_Speed), -dist_to_end, true);
			if (QuadraticSolve::isSolution(t_to_s0)) {
				if (time_to_end > t_to_s0.x1) {
					time_to_end = t_to_s0.x1;
				}
			}
		} else {
			const auto t_to_s0 = LinearSolve::solver(std::abs(_Speed), -dist_to_end);
			if (LinearSolve::isSolution(t_to_s0) && t_to_s0) {
				if (time_to_end > t_to_s0) {
					time_to_end = t_to_s0;
				}
			}
		}
	}
	return time_to_end;
}

void BallMechanic::processingTrajectoryState() {
	if (_Backward) {
		if (0 < _Step) {
			--_Step;
			_StepLenght = Geometry::getDistance(_Trajectory[_Step], _Trajectory[_Step + 1]);
			_S = _StepLenght;
		} else {
			_Backward = false;
			// reset errors from double resolution
			_S = 0;
			_Speed = 0;
		}
	} else {
		if ((_DataSize - 2) > _Step) {
			++_Step;
			_StepLenght = Geometry::getDistance(_Trajectory[_Step], _Trajectory[_Step + 1]);
			_S = 0;
		} else {
			_Backward = true;
			// reset errors from double resolution
			_S = _StepLenght;
			_Speed = 0;
		}
	}
}

void BallMechanic::reset() {
	_Step = 0;
	_S = 0;
	_Speed = 0;
	_Backward = false;
	_StepLenght = Geometry::getDistance(_Trajectory[_Step], _Trajectory[_Step + 1]);
	_Current = *_Trajectory;
	_Widget->setXY(_Current.x, _Current.y);
	_Widget->invalidate();
}

double BallMechanic::getSpeed() const {
	return std::abs(_Speed);
}
