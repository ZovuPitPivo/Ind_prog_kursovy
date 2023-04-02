#include "sensor.h"
#include <iostream>

void sensor::set_signal(int value) {
	signal = value;
}

void sensor::result_signal() {
	std::cout << "Значение датчика: " << signal << std::endl;
}