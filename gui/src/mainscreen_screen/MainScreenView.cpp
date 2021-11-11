#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <cmath>
#include <cassert>

#include "gui/common/Configuration.hpp"
#include <gui/utils/Geometry.hpp>

MainScreenView::MainScreenView() : _RampCfgLeft(RampLeft), _RampCfgRight(RampRight) {
	_RampRotLeftCenter.x = -1;
	_RampRotLeftCenter.y = -1;
	_RampRotRightCenter.x = -1;
	_RampRotRightCenter.y = -1;
}

void MainScreenView::setupScreen() {	
	auto & cfg = presenter->getConfig();
	_Ball_S_Offset = cfg.Geometry.Ball_S_Offset;
	_LineWidht = cfg.Geometry.LineWidht;
	_RampRotLeftCenter = cfg.Geometry.RampRotationCenterLeft;
	_RampRotRightCenter = cfg.Geometry.RampRotationCenterRight;
	_ScreenWidth = cfg.Geometry.ScreenWidth;
	_ScreenHeight = cfg.Geometry.ScreenHeight;

	_Mechanic.init(cfg.Physics, &BallWidget);
	
	MainScreenViewBase::setupScreen();

	BallWidget.setVisible(true);
	BallWidget.setTouchable(false);
}

void MainScreenView::tearDownScreen() {
    MainScreenViewBase::tearDownScreen();
}

void MainScreenView::handleTickEvent() {
	if (_Animation) {

		auto now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed_sec = now - _TS;
#ifdef NDEBUG
		_TS = now;
#endif
		_Mechanic.processing(elapsed_sec.count());
#if !defined(NDEBUG)
		_TS = std::chrono::high_resolution_clock::now();
#endif
	}
}

void MainScreenView::startAnimation() {
	_Animation = !_Animation;
	if (_Animation) {
		_TS = std::chrono::high_resolution_clock::now();
	}	
}

void MainScreenView::prepareTrajectory() {
	const Point left_ramp { RampLeft.getX(), RampLeft.getY() };
	double s = _Ball_S_Offset;
	Point p = Geometry::getLinePoint(left_ramp, _RampRotLeftCenter, s);
	auto indx = 0;
	_Trajectory[indx++] = p;
	_Trajectory[indx++]  = _RampRotLeftCenter;
	const Point right_ramp{ RampRight.getRect().right(), RampRight.getY() };
	s = _Ball_S_Offset;
	p = Geometry::getLinePoint(right_ramp, _RampRotRightCenter, s);
	_Trajectory[indx++] = _RampRotRightCenter;
	_Trajectory[indx++] = p;
	assert(POINT_NUMB == indx);
	_Mechanic.setTrajectory(_Trajectory, POINT_NUMB);
}
