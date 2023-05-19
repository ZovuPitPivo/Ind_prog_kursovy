#pragma once

class sensor {
private:
	int signal;
public:
	sensor() {
		signal = 0;
	}

	void set_signal(char value) {
		if (value == '0') signal = 0;
		else signal = 1;
	}

	int result_signal() {
		return signal;
	}
};