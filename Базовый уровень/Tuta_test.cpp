#include <iostream>
#include "�������������������.h"

int main() {
	setlocale(LC_ALL, "Russian");

	eq2 h;
	eq2 t(6, 2);
	eq2 f(2, 4, 5);

	std::cout << "��� ��������� �������� ������ ���������� ���������." << std::endl;

	std::cout << "������� ��������� ����������� ��� ���������� h:" << std::endl;
	int n, m;
	std::cout << "������� ������� ���������: " << std::endl;
	std::cin >> n >> m;
	h.build_rand_abc(n, m);
	std::cout << h << std::endl;
	std::cout << t << std::endl;
	std::cout << f << std::endl;
	std::cout << "� ��������� t ��� ����������� C, ������ ���: " << std::endl;

	double c;
	std::cin >> c;
	t.set_c(c);

	std::cout << t << std::endl;

	std::cout << "������ ����� ���������. ��������, ��� ���� D < 0, �� ����� �������� ����������� �����: " << std::endl;
	h.find_x(); t.find_x(); f.find_x();

	std::cout << "������ Y� ��������� ��� ����� � ��� �� X��: " << std::endl;
	std::cout << "������� x:" << std::endl;
	double x;
	std::cin >> x;
	h.find_y(x); t.find_y(x); f.find_y(x);

	std::cout << "������ Y� � ��������� �� n �� m, ������ �������: " << std::endl;
	double l, k;
	std::cin >> k >> l;
	h.find_ys(k, l); t.find_ys(k, l); f.find_ys(k, l);

	std::cout << "������� ....... ���� .... ����.   ������� ...... ����............. �������!!!!!!!" << std::endl;
	return 0;
}