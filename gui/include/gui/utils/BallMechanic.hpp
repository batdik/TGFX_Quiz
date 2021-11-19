#ifndef BALL_MECHANIC_HPP
#define BALL_MECHANIC_HPP

#include <cstdint>

#include <cstddef>

#include <touchgfx/hal/Types.hpp>

namespace Config {
	struct PhysicsCofig_t;
}
namespace touchgfx {
	class Drawable;
}

class BallMechanic {
public:
	void init(const Config::PhysicsCofig_t &cfg, touchgfx::Drawable * widget);
	void setTrajectory(touchgfx::Point * data, std::size_t size);
	void processing(double sec);
	void reset();
	double getSpeed() const;
	const touchgfx::Point& getCurrentPoint() const{
		return _Current;
	}
	bool getBackward() { return _Backward; }
private:
	static const double BALL_K;
	double _GravityAcc = 0;
	double _Scale = 0;
	touchgfx::Drawable *_Widget = nullptr;
	const touchgfx::Point * _Trajectory = nullptr;
	std::size_t _DataSize = 0;
	std::size_t _Step = 0;
	touchgfx::Point _Current{};
	double _S = 0;
	double _Speed = 0;
	bool _Backward = false;
	double _StepLenght = 0;
	
	double calculateBoundary(double t, double acc);
	void processingTrajectoryState();
};

#endif
