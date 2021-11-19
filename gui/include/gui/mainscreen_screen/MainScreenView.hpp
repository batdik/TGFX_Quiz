#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <chrono>

#include <touchgfx/Unicode.hpp>

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>
#include "gui/utils/RampCfg.hpp"
#include "gui/utils/BallMechanic.hpp"

class MainScreenView : public MainScreenViewBase
{
public:
    MainScreenView();
    void setupScreen() final;
	void tearDownScreen() final;

protected:
	enum TrajectoryPointsId_t {
		FIRST_POINT = 0,
		SECOND_POINT,
		THIRD_POINT,
		FOURTH_POINT,
		POINT_NUMB
	};

	bool _Animation = false;
	int32_t _Ball_S_Offset = 0;
	int32_t _LineWidht = 0;
	int32_t _ScreenWidth = 0;
	int32_t _ScreenHeight = 0;
	Point _RampRotLeftCenter{};
	Point _RampRotRightCenter{};
	RampCfg _RampCfgLeft;
	RampCfg _RampCfgRight;
	BallMechanic _Mechanic;
	Point _Trajectory[POINT_NUMB];
	std::chrono::system_clock::time_point _TS;

	double _rotationBall = 0.0;

	void handleTickEvent() final;
	void startAnimation() final;
	void prepareTrajectory();

private:
	touchgfx::Point _CurrentBallPoint{};
	static constexpr uint8_t _SpeedStrSize = 10;
	touchgfx::Unicode::UnicodeChar _speedStr[_SpeedStrSize];

	int tickUpdateInterval;
	void updateSpeedTxt();
};

#endif // MAINSCREENVIEW_HPP
