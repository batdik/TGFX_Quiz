#ifndef BALL_GEOMETRY_HPP
#define BALL_GEOMETRY_HPP

#include <cstddef>

#include <touchgfx/hal/Types.hpp>

namespace BallGeometry {
	void correction(touchgfx::Point * data, std::size_t size, double r);
}

#endif
