#pragma once
#include <iostream>
#include "sensor.h"
#include "controller.h"
#include <vector>
#include <string>
#include "work_with_txt.h"
#include "container.h"

class PLK {
private:
	std::vector <container> containers;
	std::vector <sensor> senses;
	std::vector <controller> control;

	void stop_all() {
		for (int i = 0; i < control.size(); i++) {
			control[i].set_order(0);
		}
	}

	char revers_signal(char sig) {
		if (sig == '0')	return '1';
		else return '0';
	}

	void creat_plk(int ports_s, int ports_c) {
		for (int i = 0; i < ports_s; i++) {
			sensor se;
			senses.push_back(se);
		}
		for (int i = 0; i < ports_c; i++) {
			controller co;
			control.push_back(co);
		}
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				container cont(100);
				containers.push_back(cont);
			}
			else {
				container cont(45);
				containers.push_back(cont);
			}
		}
	}

	void input_data(std::string data) {
		for (int j = 0; j < data.length(); j++) {
			char dt = data[j];
			senses[j].set_signal(dt);
		}
	}

	std::string output_data() {
		std::string out;
		for (int i = 0; i < control.size(); i++) {
			char ut = control[i].give_order();
			out += ut;
		}
		return out;
	}

	void show_items() {
		for (int i = 0; i < size(senses); i++) {
			std::cout << senses[i].result_signal() << " ";
		}

		std::cout << "\n";

		for (int i = 0; i < size(control); i++) {
			std::cout << control[i].give_order() << " ";
		}

		std::cout << "\n-------\n";
	}

public:

	PLK() {}

	PLK(int ports_s, int ports_c) {
		creat_plk(ports_s, ports_c);
	}

	void work(std::vector <std::string> in, int test) {
		if (test == 1) {
			containers[0].addProduct(1);
		}
		else if (test == 2) {
			containers[0].addProduct(10);
		}
		else if (test == 3) {
			containers[0].addProduct(100);
		}
		std::vector <std::string> out;
		int kol_cont = 1;
		control[0].set_order(1); control[2].set_order(1); control[1].set_order(1);
		out.push_back(output_data());
		control[1].set_order(0);
		out.push_back(output_data());
		for (int i = 1; i < in.size(); i++) {
			input_data(in[i]);
			if (senses[0].result_signal() == 1) {
				control[0].set_order(0); control[3].set_order(1);
				out.push_back(output_data());
				control[0].set_order(1); control[3].set_order(0);
				out.push_back(output_data());
			}
			if (senses[1].result_signal() == 1 || senses[2].result_signal() == 1) {
				if (senses[1].result_signal() == 1) {
					control[2].set_order(0); control[4].set_order(1);
					out.push_back(output_data());
					control[2].set_order(0); control[4].set_order(1);
					out.push_back(output_data());
				}
				if (senses[2].result_signal() == 1) {
					control[2].set_order(0); control[5].set_order(1);
					out.push_back(output_data());
					control[2].set_order(1); control[5].set_order(0);
					out.push_back(output_data());
					if (containers[1].addProduct(1) != false) {
						containers[1].addProduct(1);
					}
					else {
						containers[1].clean();
						kol_cont += 1;
						if (containers[0].retProduct(1) != false) {
							containers[0].retProduct(1);
							control[1].set_order(1);
							containers[0].retProduct(1);
						}
						else {
							break;
						}
					}
				}
			}
		}
		containers[1].show();
		std::cout << kol_cont << "\n";
		stop_all();
		out.push_back(output_data());
		write(out);
	}

};