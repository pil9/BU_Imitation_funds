#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
	double ins;
	int age;
	int price;

	cout << "����: "
		cin >> age;

		cout << "�����: "
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

	cout << "������: " << price;

	return 0;

}
