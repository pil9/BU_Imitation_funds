#pragma once
#include<iostream>
#include<math.h>
using namespace std;

class Zuk {
private:
    int money;
    int month;
    int percent;
public:
    Zuk(int zero);
    void set(int money, int month, int percent);
    void show();
};

Zuk::Zuk(int zero) {
    this->money = zero;
}

void Zuk::set(int money, int month, int percent) {
    this->money += money;
    this->month = month;
    this->percent = percent;
}
void Zuk::show() {
    int i;
    for (i = 0; i < month; i++) {
        money = money * (1 + ((double)percent / 100.0));
    }
    cout << "결과 (원금 + 이자) : ";
    cout << money << endl;
}