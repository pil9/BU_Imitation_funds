#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
	double ins;
	int age;
	int price;

	cout << "나이: "
		cin >> age;

		cout << "보험비: "
		cin >> ins;

	if (age < 8) {
		price = ins - ins * 0.05;
	}
	else if (8 <= age < 20) {
		price = ins - ins * 0.03;
	}
	else if (20 <= age < 40) {
		price = ins;
	}
	else {
		price = ins + ins * 0.05;
	}

	cout << "보험료는: " << price;

	return 0;

}
