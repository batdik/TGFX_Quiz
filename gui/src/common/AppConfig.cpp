#include "gui/common/AppConfig.hpp"

#include "gui/common/Configuration.hpp"

#include <gui_generated/common/SimConstants.hpp>

using namespace Config;
using namespace touchgfx;

namespace {
	const auto MIN_ANGLE = 1;
	const auto MAX_ANGLE = 55;

	const auto LINE_WIDHT = 10;

	const Point RAMP_ROTATION_CENTER_LEFT = { 300, SIM_HEIGHT - LINE_WIDHT };
	const Point RAMP_ROTATION_CENTER_RIGHT = { SIM_WIDTH - 300, SIM_HEIGHT - LINE_WIDHT };

	const auto EARTH_G = 9.8;		// m/s^2
	const auto SCALE = 50 / 0.3;	// pix/m

	const auto BALL_S_OFFSET = 30;

	const auto SPEED_UPDATE_INTERVAL = 4;

	void populateConfig(ConfigConfig_t& cfg);
	void populateMain(MainConfig_t& cfg);
	void populateGeometry(GeometryCfg_t& cfg);
	void populatePhysics(PhysicsCofig_t& cfg);
	void populateSpeedUpdateInterval(SpeedUpdateIntervalCfg_t& cfg);

	void populateGeometry(GeometryCfg_t& cfg) {
		cfg.LineWidht = LINE_WIDHT;
		cfg.RampRotationCenterLeft = RAMP_ROTATION_CENTER_LEFT;
		cfg.RampRotationCenterRight = RAMP_ROTATION_CENTER_RIGHT;
		cfg.Ball_S_Offset = BALL_S_OFFSET;
		cfg.ScreenWidth = SIM_WIDTH;
		cfg.ScreenHeight = SIM_HEIGHT;
	}

	void populatePhysics(PhysicsCofig_t& cfg) {
		cfg.GravityAcceleration = EARTH_G;
		cfg.Scale = SCALE;
	}

	void populateSpeedUpdateInterval(SpeedUpdateIntervalCfg_t& cfg) {
		cfg.SpeedInterval = SPEED_UPDATE_INTERVAL;
	}
	
	void populateMain(MainConfig_t& cfg) {
		populatePhysics(cfg.Physics);
		populateGeometry(cfg.Geometry);

	}

	void populateConfig(ConfigConfig_t& cfg) {
		cfg.MinAngle = MIN_ANGLE;
		cfg.MaxAngle = MAX_ANGLE;
	}
}

void AppConfig::populateConfiguration(AppCfg_t& cfg) {
	populateMain(cfg.Main);
	populateConfig(cfg.Config);
	populateSpeedUpdateInterval(cfg.SpeedUpdateInterval);
}
