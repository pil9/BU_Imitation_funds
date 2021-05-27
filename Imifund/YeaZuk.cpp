#include<iostream>
#include"deposit.h"
#include"ins_savings.h"
using namespace std;

class YeaZuk() {
    int i, select, input[3] = { 0 };
    char string[3][20] = { "돈", "기간(월)", "이율(%)" };
    Yea yea(0);
    Zuk zuk(0);
    while (1) {
        //cout << "1.예금, 2.적금, 3.종료 : ";
        cin >> select;
        if (select == 1) {
            for (i = 0; i < 3; i++) {
                //cout << string[i] << " : ";
                cin >> input[i];
                if (input[i] < 0) {
                    //cout << endl << "음수는 입력하실수없습니다";
                    //cout << endl << "다시 입력하세요" << endl << endl;
                    i = i - 1;
                }
            }
            yea.set(input[0], input[1], input[2]);
            yea.show();
        }
        else if (select == 2) {
            for (i = 0; i < 3; i++) {
               // cout << string[i] << " : ";
                cin >> input[i];
                if (input[i] < 0) {
                    //cout << endl << "음수는 입력하실수없습니다";
                    //cout << endl << "다시 입력하세요" << endl << endl;
                    i = i - 1;
                }
            }
            zuk.set(input[0], input[1], input[2]);
            zuk.show();
        }
        else if (select == 3) {
            //cout << "프로그램을 종료합니다" << endl;
            break;
        }
        else {
            //cout << "잘못입력하셨습니다" << endl;
        }
    }
}

