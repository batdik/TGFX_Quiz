#ifndef QUADRATIC_SOLVE_HPP
#define QUADRATIC_SOLVE_HPP

namespace QuadraticSolve {
	struct Value_t {
		double x1;
		double x2;
	};

	Value_t solver(double a, double b, double c, bool force_valid = false);
	bool isSolution(const Value_t & val);
}

#endif