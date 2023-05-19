#pragma once

class container {
private:
	float product;
	int maxProd;
public:

	container() {
		product = 0;
		maxProd = 0;
	}

	container(int max) {
		maxProd = max;
		product = 0;
	}

	container(int max, int prod) {
		maxProd = max;
		product = prod;
	}

	bool retProduct(float prod) {
		if (product - prod >= 0) {
			product -= prod;
		}else return false;
	}

	bool addProduct(float prod) {
		if (product + prod <= maxProd) {
			product += prod;
		}
		else {
			return false;
		}
	}

	void show() {
		std::cout << product << "/" << maxProd << "\n";
	}

	float retProduct() {
		return product;
	}

	void clean() {
		product = 0;
	}
};
