#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "PLK.h"
#include "work_with_txt.h"


class pult {
private:
	int button;
	std::vector <std::string> buttons;

	void creat_pult() {
		button = 0;
		buttons.push_back("");
		buttons.push_back("start"); buttons.push_back("stop"); buttons.push_back("restart");
		buttons.push_back("--1--"); buttons.push_back("--2--"); buttons.push_back("--3--");
	}

	void push_button(int butt) {
		if (butt >= buttons.size()) {
			std::cout << "ERROR: OUT OF BUTTON, PRESS ANOTHER BUTTON";
			std::cin >> butt;
			push_button(butt);
		}
		else button = butt;
	}

	void show_buttons() {
		std::cout << " --------------------------------\n";
		for (int i = 0; i < 4; i++) {
			if (i != 0) {
				std::cout << " | " << buttons[i] << " | ";
			}
		}
		std::cout << "\n";
		std::cout << " --------------------------------\n";
	}

	void show_tests() {
		std::cout << " -------------------------------\n";
		for (int i = 4; i < 7; i++) {
			std::cout << " | " << buttons[i] << " | ";
		}
		std::cout << "\n";
		std::cout << " -------------------------------\n";
	}

public:

	pult() {
		creat_pult();
	}

	void pult_in_work() {
		while (button != 2) {
			PLK plk(3, 7);
			int butt = 0;
			std::cout << "PRESS BUTTON\n";
			show_buttons();
			std::cin >> butt;
			if (butt == 1) {
				show_tests();
				int butt_test;
				std::cin >> butt_test;
				if (butt_test == 1) {
					write_for_test_1();
					std::vector <std::string> in = read();
					plk.work(in, butt_test);
				}else if (butt_test == 2){
					write_for_test_2();
					std::vector <std::string> in = read();
					plk.work(in, butt_test);
				}else if (butt_test == 3) {
					write_for_test_3();
					std::vector <std::string> in = read();
					plk.work(in, butt_test);
				}
			}
			else if (butt == 2) break;
		}
	}

};