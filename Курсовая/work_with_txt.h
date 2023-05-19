#pragma once
#include <vector>
#include <fstream>
#include <string>


std::vector <std::string> read() {

	std::vector <std::string> out;
	std::string line;

	std::ifstream in("input1.txt");
	if (in.is_open()) {
		while (getline(in, line)) {
			out.push_back(line);
		}
	}
	in.close();
	return out;
}

void write(std::vector <std::string> put) {
	std::ofstream out;
	out.open("output1.txt");
	if (out.is_open()) {
		for (int i = 0; i < put.size(); i++) {
			out << put[i] << std::endl;
		}
	}
	out.close();
}

void write_int1(int kol) {
	std::ofstream out;
	out.open("output1.txt");
	if (out.is_open()) {
		out << kol;
	}
	out.close();
}

void write_for_test_1() {
	std::ofstream test;
	test.open("input1.txt");
	if (test.is_open()) {
		
		test << "000\n" << "100\n" << "000\n";
		for (int i = 0; i < 45; i++) {
			test << "010\n" << "000\n" << "001\n";
		}
		test << "000";
	}
	test.close();
}

void write_for_test_2() {
	std::ofstream test;
	test.open("input1.txt");
	if (test.is_open()) {
		for (int i = 0; i < 10; i++) {
			test << "000\n" << "100\n" << "000\n";
			for (int i = 0; i < 45; i++) {
				test << "010\n" << "000\n" << "001\n";
			}
			test << "000\n";
		}
	}
	test.close();
}

void write_for_test_3() {
	std::ofstream test;
	test.open("input1.txt");
	if (test.is_open()) {
		for (int i = 0; i < 100; i++) {
			test << "000\n" << "100\n" << "000\n";
			for (int i = 0; i < 45; i++) {
				test << "010\n" << "000\n" << "001\n";
			}
			test << "000\n";
		}
	}
	test.close();
}