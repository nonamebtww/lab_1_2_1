#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <stdexcept>

#define EPS 1e-3

// f1
double f1(double a, double b) {
	double result = 
		(std::sin(std::pow(a, 2)) + std::cos(b)) /
		std::sqrt(
			1 + (M_E / (std::pow(a, 3) + 3.4 * b))
		)
	;

	if (result <= 0) {
		throw std::invalid_argument("Аргумент логарифма должен быть больше 0. Значение для вычисления логарифма: " + std::to_string(result));
	}

	return std::log(result);
}

// f2
double a(double term, double x, int n) {
	return term * (-x) * (n + 1) / n;
}

double f2(double x) {
	if (x >= 1) {
		throw std::invalid_argument("x должен быть меньше 1");
	}

	double sum = 0;
	double term = 1;
	int n = 1;

	do
	{
		sum += (term = a(term, x, n++));
	} while (std::abs(term) > EPS);

	return sum;
}

// f4
bool f4(double x) {
	return -2 < x && x < 2;
}