#pragma once

class controller {
private:
	int order;
public:
	char give_order() {
		if (order == 0) {
			return '0';
		}
		else {
			return '1';
		}
	}

	void set_order(int ord) {
		order = ord;
	}

	controller() {
		order = 0;
	}
};