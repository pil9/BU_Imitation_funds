#include <stdio.h>
#include <iostream>
using namespace std;


int main(void)
{

	float rate;
	float usd;
	int krw;



	cout << "달러에대한원화환율을입력하시오: "
		cin >> rate;

	cout << "원화금액을입력하시오: "
		cin >> krw;

	usd = krw / rate;

	cout << usd << "달러입니다.\n"


		return 0;



}