#include <stdio.h>
#include <iostream>
using namespace std;


int main(void)
{

	float rate;
	float usd;
	int krw;



	cout << "�޷������ѿ�ȭȯ�����Է��Ͻÿ�: "
		cin >> rate;

	cout << "��ȭ�ݾ����Է��Ͻÿ�: "
		cin >> krw;

	usd = krw / rate;

	cout << usd << "�޷��Դϴ�.\n"


		return 0;



}