#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "touchgfx/hal/types.hpp"

namespace Config {
	struct PhysicsCofig_t {
		double GravityAcceleration = -1;
		double Scale = 0;
	};

	struct GeometryCfg_t {
		touchgfx::Point RampRotationCenterLeft;
		touchgfx::Point RampRotationCenterRight;
		int32_t LineWidht = -1;
		int32_t Ball_S_Offset = 0;
		int32_t ScreenWidth = -1;
		int32_t ScreenHeight = -1;
	};

	struct MainConfig_t {
		PhysicsCofig_t Physics;
		GeometryCfg_t Geometry;
	};

	struct ConfigConfig_t {
		int32_t MinAngle = -1;
		int32_t MaxAngle = -1;
	};

	struct AppCfg_t {
		MainConfig_t Main;
		ConfigConfig_t Config;
	};
}

#endif
