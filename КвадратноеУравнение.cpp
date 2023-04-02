#include "ÊâàäðàòíîåÓðàâíåíèå.h"
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <random>

eq2::eq2() {
	a = 0;
	b = 0;
	c = 0;
	D = 0;
}

eq2::eq2(double a1) {
	a = a1;
	b = 0;
	c = 0;
	D = 0;
}

eq2::eq2(double a1, double b1) {
	a = a1;
	b = b1;
	c = 0;
	D = b * b;
}

eq2::eq2(double a1, double b1, double c1) {
	a = a1;
	b = b1;
	c = c1;
	D = b * b - 4 * a * c;
}

void eq2::set_a(double a1) {
	a = a1;
	D = b * b - 4 * a * c;
}

void eq2::set_b(double b1) {
	b = b1;
	D = b * b - 4 * a * c;
}

void eq2::set_c(double c1) {
	c = c1;
	D = b * b - 4 * a * c;
}

void eq2::set_ab(double a1, double b1) {
	a = a1;
	b = b1;
	D = b * b - 4 * a * c;
}

void eq2::set_ac(double a1, double c1) {
	a = a1;
	c = c1;
	D = b * b - 4 * a * c;
}

void eq2::set_bc(double b1, double c1) {
	b = b1;
	c = c1;
	D = b * b - 4 * a * c;
}

void eq2::set_abc(double a1, double b1, double c1) {
	a = a1;
	b = b1;
	c = c1;
	D = b * b - 4 * a * c;
}

double eq2::find_x() {
	if (D == 0) {
		std::cout << 1 * b / (2 * a);
		return 0;
	}else if (D < 0) {
		std::cout << "Ïàðàáîëà íå ïåðåñåêàåò îñü oX, Èìåþòñÿ òîëüêî êîìïëåêñíûå êîðíè: ";
		std::cout << a / 2 << " +/- " << sqrt(abs(D)) << "i" << std::endl;
		return 0;
	}else {
		std::cout << "x1= " << (-1 * b + sqrt(D) / 2 * a) << "x2= " << (-1 * b - sqrt(D) / 2 * a);
		return 0;
	}
}

double eq2::find_y(double x1) {
	std::cout << a * x1 * x1 + x1 * b + c << std::endl;
	return 0;
}

double eq2::get_a() {
	std::cout << a << std::endl;
	return 0;
}
double eq2::get_b() {
	std::cout << b << std::endl;
	return 0;
}
double eq2::get_c() {
	std::cout << c << std::endl;
	return 0;
}

double eq2::find_ys(double n, double m) {
	if (n == m) {
		std::cout << a * n * n + b * n + c << " " << std::endl;
		return 0;
	}
	else {
		std::cout << a * n * n + b * n + c << " ";
		return find_ys(n + 1, m);
	}
}

void eq2::build_rand_abc(int n, int m) {
	a = rand()%m + n;
	b = rand()%m + n;
	c = rand()%m + n;
	D = b * b - 4 * a * c;
}
