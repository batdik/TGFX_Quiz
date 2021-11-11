#include "gui/utils/Geometry.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>

#include <touchgfx/hal/Types.hpp>

using namespace touchgfx;

Point Geometry::subPoint(const Point &ls, const Point &rs) {
	return{ ls.x - rs.x, ls.y - rs.y };
}

Point Geometry::addPoint(const Point &ls, const Point &rs) {
	return{ ls.x + rs.x, ls.y + rs.y };
}

Point Geometry::getPoint(double x, double y) {
	return{ static_cast<int32_t>(std::round(x)), static_cast<int32_t>(std::round(y)) };
}

double Geometry::deg2rad(double val) {
	val *= M_PI / 180.0;
	return val;
}

double Geometry::rad2deg(double val) {
	val *= 180.0 * M_1_PI;
	return val;
}

double Geometry::getDistance(const Point & curr_pos, const Point & new_pos) {
	Point delta = subPoint(new_pos, curr_pos);
	if (0 == delta.x) {
		return 0;
	}
	double rc = std::sqrt(delta.x*delta.x + delta.y*delta.y);
	return rc;
}

double Geometry::getRotationAngle(double distance, double r) {
	return distance/r;
}

Point Geometry::getTangentToCircle(double angle, double r) {
	angle = M_PI_2 - angle;
	auto const x = r*std::cos(angle);
	auto const y = r*std::sin(angle);
	return getPoint(x,y);
}

double Geometry::getSlopeAngle(const touchgfx::Point &p1, const touchgfx::Point &p2) {
	const auto delta = subPoint(p2, p1);
	return std::atan2(delta.y, delta.x);
}

int32_t Geometry::getLineY(const touchgfx::Point &p1, const touchgfx::Point &p2, int32_t x) {
	auto p_delta = subPoint(p1, p2);
	if (0 == p_delta.x) {
		return p2.y;
	}
	double a = p_delta.y;
	a /= p_delta.x;
	double b = p2.y - a*p2.x;
	double y = a*x + b;
	return static_cast<int32_t>(std::round(y));
}

Point Geometry::getLinePoint(const Point &p1, const Point &p2, double s) {
	const auto lenght = getDistance(p1, p2);
	double ratio = s / lenght ;
	const auto delta = subPoint(p2, p1);
	const double x = delta.x * ratio + p1.x;
	const double y = delta.y * ratio + p1.y;
	return getPoint(x, y);
}

Point Geometry::getCrossPoint(const Point &l11, const Point &l12,
							  const Point & l21, const Point & l22) {
	const auto d = (l11.x - l12.x) * (l21.y - l22.y) - (l11.y - l12.y) * (l21.x - l22.x);
	if (!d) {
		// XXX: parallel or coincident
		return l12;
	}
	const double _1_d = 1.0 / d;
	const double x = ((l11.x * l12.y - l11.y * l12.x) * (l21.x - l22.x) - (l11.x - l12.x)*(l21.x * l22.y - l22.x * l21.y)) * _1_d;
	const double y = ((l11.x * l12.y - l11.y * l12.x) * (l21.y - l22.y) - (l11.y - l12.y)*(l21.x * l22.y - l22.x * l21.y)) * _1_d;
	return getPoint(x, y);
}

Point Geometry::transformRotataion(const Point &p, double angle) {
	const auto sin_val = std::sin(angle);
	const auto con_val = std::cos(angle);
	double  x = p.x*con_val - p.y*sin_val;
	double  y = p.x*sin_val + p.y*con_val;
	return getPoint(x, y);
}

Point Geometry::transformMove(Point p, int32_t x, int32_t y) {
	p.x += x;
	p.y += y;
	return p;
}
