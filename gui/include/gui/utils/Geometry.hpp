#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <cstdint>

namespace touchgfx {
	struct Point;
}
namespace Geometry {
	double deg2rad(double val);
	double rad2deg(double val);
	touchgfx::Point subPoint(const touchgfx::Point &ls, const touchgfx::Point &rs);
	touchgfx::Point addPoint(const touchgfx::Point &ls, const touchgfx::Point &rs);
	touchgfx::Point getPoint(double x, double y);
	double getDistance(const touchgfx::Point &curr_pos, const touchgfx::Point &new_pos);
	double getRotationAngle(double distance, double r);
	touchgfx::Point getTangentToCircle(double angle, double r);
	double getSlopeAngle(const touchgfx::Point &p1, const touchgfx::Point &p2);
	int32_t getLineY(const touchgfx::Point &p1, const touchgfx::Point &p2, int32_t x);
	touchgfx::Point getLinePoint(const touchgfx::Point &p1, const touchgfx::Point &p2, double s);
	touchgfx::Point getCrossPoint(const touchgfx::Point &l11, const touchgfx::Point &l12,
								  const touchgfx::Point & l21, const touchgfx::Point & l22);
	touchgfx::Point transformRotataion(const touchgfx::Point &p, double angle);
	touchgfx::Point transformMove(touchgfx::Point p, int32_t x, int32_t y);
}

#endif