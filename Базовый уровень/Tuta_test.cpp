#include <iostream>
#include "КвадратноеУравнение.h"

int main() {
	setlocale(LC_ALL, "Russian");

	eq2 h;
	eq2 t(6, 2);
	eq2 f(2, 4, 5);

	std::cout << "Эта прогдамма помогает решать квадратные уравнения." << std::endl;

	std::cout << "Зададим случайные коэффиценты для переменной h:" << std::endl;
	int n, m;
	std::cout << "Введите границы диапозона: " << std::endl;
	std::cin >> n >> m;
	h.build_rand_abc(n, m);
	std::cout << h << std::endl;
	std::cout << t << std::endl;
	std::cout << f << std::endl;
	std::cout << "У уравнения t нет коэффицента C, введем его: " << std::endl;

	double c;
	std::cin >> c;
	t.set_c(c);

	std::cout << t << std::endl;

	std::cout << "Найдем корни уравнений. Напомним, что если D < 0, то будут выведены компдексные корни: " << std::endl;
	h.find_x(); t.find_x(); f.find_x();

	std::cout << "Найдем Yи уравнений при одних и тех же Xах: " << std::endl;
	std::cout << "Введите x:" << std::endl;
	double x;
	std::cin >> x;
	h.find_y(x); t.find_y(x); f.find_y(x);

	std::cout << "Найдем Yы в диапазоне от n до m, введем границы: " << std::endl;
	double l, k;
	std::cin >> k >> l;
	h.find_ys(k, l); t.find_ys(k, l); f.find_ys(k, l);

	std::cout << "Всегооо ....... Хоро .... Шэго.   Русские ...... едут............. Домоййй!!!!!!!" << std::endl;
	return 0;
}