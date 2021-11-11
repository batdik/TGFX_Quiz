#include "gui/utils/RampCfg.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

#include <gui/containers/RampWidget.hpp>
#include <gui/utils/Geometry.hpp>

RampCfg::RampCfg(RampWidget &wiget) : _Wiget(wiget) {
}

void RampCfg::setAngle(double ang, const touchgfx::Point & rot_point) {
	const auto width = _Wiget.getWidth();
	ang = Geometry::deg2rad(ang);
	auto height = std::tan(ang)*width;
	height = std::abs(height);
	if (rot_point.y < height) {
		height = rot_point.y;
	}
	const auto sin_val = std::sin(ang);
	const auto line_width = width * sin_val;
	const bool left_side = M_PI_2 < ang;
	const int32_t h = static_cast<int32_t>(std::round(height));
	const int32_t l_w = static_cast<int32_t>(std::round(line_width)) & ~1;
	Point start_p { -width - l_w, 0 };
	Point end_p { width, 0 };
	start_p = Geometry::transformRotataion(start_p, ang);
	end_p   = Geometry::transformRotataion(end_p,   ang);
	const int32_t delta_x = width / 2;
	const int32_t x_move = left_side ? delta_x : width - delta_x;
	const int32_t y_move = h;
	start_p = Geometry::transformMove(start_p, x_move, y_move);
	end_p = Geometry::transformMove(end_p, x_move, y_move);
	_Wiget.config(start_p, end_p, l_w, h);
	_Wiget.setY(rot_point.y - h);
}
