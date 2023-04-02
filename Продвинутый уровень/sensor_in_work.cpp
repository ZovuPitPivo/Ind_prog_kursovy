#include <iostream>
#include "sensor.h"
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");

	sensor analogSensor;
	std::string answer;
	bool b;

	std::cout << "Дошла ли деталь до конца (yes or no): " << std::endl;
	std::cin >> answer;

	b = answer[0] == 'y';

	if (b == true) {
		analogSensor.set_signal(1);
	}else {
		analogSensor.set_signal(0);
	}

	analogSensor.result_signal();

	return 0;
}