#pragma once
#include<iostream>
using namespace std;

class Yea {
private:
    int money;
    int month;
    int percent;
public:
    Yea(int zero);
    void set(int money, int month, int percent);
    void show();
};

Yea::Yea(int zero) {
    this->money = zero;
}

void Yea::set(int money, int month, int percent) {
    this->money += money;
    this->month = month;
    this->percent = percent;
}
void Yea::show() {
    int i;
    for (i = 0; i < month; i++) {
        money += (double)money * ((double)percent / 100.0);
    }
    cout << "결과 (원금 + 이자) : ";
    cout << money << endl;
}
