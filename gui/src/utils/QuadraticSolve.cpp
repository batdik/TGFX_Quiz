#include "gui/utils/QuadraticSolve.hpp"
#include "gui/utils/LinearSolve.hpp"

#include <cmath>
#include <limits>
#include <cassert>

QuadraticSolve::Value_t QuadraticSolve::solver(double a, double b, double c, bool force_valid) {
	if (!a) {
		return{ LinearSolve::solver(b, c), std::numeric_limits<double>::quiet_NaN() };
	}
	const auto _1_2a = 1.0 / (2.0 * a);
	auto term0 = b*b - 4.0 * a * c;
	if (0 > term0) {
		if (!force_valid) {
			return{ std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN() };
		}
		term0 = -term0;
	}
	const auto term1 = std::sqrt(term0)*_1_2a;
	const auto term_b = -b*_1_2a;
	return{ term_b + term1, term_b - term1 };
}

bool QuadraticSolve::isSolution(const Value_t & val) {
	return !(  std::isnan(val.x1) 
			|| std::isnan(val.x2) 
			|| std::isinf(val.x1) 
			|| std::isinf(val.x2));
}
