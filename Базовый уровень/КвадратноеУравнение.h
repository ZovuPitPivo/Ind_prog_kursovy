#pragma once
#include <cmath>
#include <ostream>

class eq2 {
private:
	double a, b, c;
	double D;
public:
	eq2();
	eq2(double a1);
	eq2(double a1, double b1);
	eq2(double a1, double b1, double c1);
	double get_a();
	double get_b();
	double get_c();
	void set_a(double a1);
	void set_ab(double a1, double b1);
	void set_abc(double a1, double b1, double c1);
	void set_b(double b1);
	void set_c(double c1);
	void set_ac(double a1, double c1);
	void set_bc(double b1, double c1);
	double find_x();
	double find_y(double x);
	double find_ys(double n, double m);
	friend std::ostream& operator<<(std::ostream& stream, eq2& obj) {
		if (obj.a != 0) {
			if (obj.b < 0 && obj.c < 0) {
				stream << obj.a << "x^2" << " - " << abs(obj.b) << "x" << " - " << abs(obj.c) << " = 0" << std::endl;
			}
			else if (obj.b > 0 && obj.c > 0) {
				stream << obj.a << "x^2" << " + " << obj.b << "x" << " + " << obj.c << " = 0" << std::endl;
			}
			else if (obj.b > 0 && obj.c < 0) {
				stream << obj.a << "x^2" << " + " << abs(obj.b) << "x" << " - " << obj.c << " = 0" << std::endl;
			}
			else if (obj.b < 0 && obj.c > 0) {
				stream << obj.a << "x^2" << " - " << abs(obj.b) << "x" << " + " << obj.c << " = 0" << std::endl;
			}
			else if (obj.b == 0) {
				if (obj.c > 0) {
					stream << obj.a << "x^2" << " + " << obj.c << " = 0" << std::endl;
				}
				else if (obj.c < 0) {
					stream << obj.a << "x^2" << " - " << abs(obj.c) << " = 0" << std::endl;
				}
				else {
					stream << obj.a << "x^2 = 0" << std::endl;
				}
			}
			else if (obj.c == 0) {
				if (obj.b > 0) {
					stream << obj.a << "x^2" << " + " << obj.b << "x = 0" << std::endl;
				}
				else if (obj.b < 0) {
					stream << obj.a << "x^2" << " - " << abs(obj.b) << "x = 0" << std::endl;
				}
			}
		}
		else {
			if (obj.b < 0 && obj.c < 0) {
				stream << " - " << abs(obj.b) << "x" << " - " << abs(obj.c) << " = 0" << std::endl;
			}
			else if (obj.b > 0 && obj.c > 0) {
				stream << obj.b << "x" << " + " << obj.c << " = 0" << std::endl;
			}
			else if (obj.b > 0 && obj.c < 0) {
				stream << abs(obj.b) << "x" << " - " << obj.c << " = 0" << std::endl;
			}
			else if (obj.b < 0 && obj.c > 0) {
				stream << " - " << abs(obj.b) << "x" << " + " << obj.c << " = 0" << std::endl;
			}
			else if (obj.b == 0) {
				stream << "График функции прямая, параллельня оси Ox и находящаяся на расстоинии: " << abs(obj.c) << std::endl;
			}
			else if (obj.c == 0) {
				stream << obj.b << "x = 0" << std::endl;
			}
		}
		return stream;
	}
	void build_rand_abc(int n, int m);
};