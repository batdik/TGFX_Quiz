#include "gui/utils/BallGeometry.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

#include "gui/utils/Geometry.hpp"

using namespace touchgfx;

namespace {
	Point getBallGeometry(const Point &start, const Point &end, double r) {
		auto const ang = Geometry::getSlopeAngle(start, end);
		auto pos_offset = Geometry::getTangentToCircle(ang, r);
		// fix offset, because of Ball widget is 4 pix bigger, than ball image.
		// When widget size is correct, moveTo create some artifacts.
		if (0 < pos_offset.x) {
			pos_offset.x -= 4;
		} else {
			//pos_offset.x -= 1;
		}
		double x =  pos_offset.x - r;
		double y = -pos_offset.y - r;
		return Geometry::getPoint(x, y);
	}
}

void BallGeometry::correction(touchgfx::Point * data, std::size_t size, double r) {
	assert(data);
	assert(1 < size);
	Point data_1_src = data[0];
	for (std::size_t i = 0; (size - 1) > i; ++i) {
		auto prev_data = data[0];
		data[0] = data_1_src;
		data_1_src = data[1];
		const auto ball_geometry = getBallGeometry(data[0], data[1], r);
		data[0] = Geometry::addPoint(data[0], ball_geometry);
		data[1] = Geometry::addPoint(data[1], ball_geometry);
		if (i) {
			data[0] = Geometry::getCrossPoint(data[0], data[1], data[-1], prev_data);
		}
		++data;
	}
}

