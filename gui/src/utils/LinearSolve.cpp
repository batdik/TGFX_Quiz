#include "gui/utils/LinearSolve.hpp"

#include <cmath>
#include <limits>

double LinearSolve::solver(double a, double b) {
	if (!a) {
		return std::numeric_limits<double>::quiet_NaN();
	}
	return -b / a;
}

bool LinearSolve::isSolution(double res) {
	return !(std::isnan(res)
	      || std::isinf(res));
}
