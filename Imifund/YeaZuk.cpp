#include<iostream>
#include"deposit.h"
#include"ins_savings.h"
using namespace std;

class YeaZuk() {
    int i, select, input[3] = { 0 };
    char string[3][20] = { "��", "�Ⱓ(��)", "����(%)" };
    Yea yea(0);
    Zuk zuk(0);
    while (1) {
        //cout << "1.����, 2.����, 3.���� : ";
        cin >> select;
        if (select == 1) {
            for (i = 0; i < 3; i++) {
                //cout << string[i] << " : ";
                cin >> input[i];
                if (input[i] < 0) {
                    //cout << endl << "������ �Է��ϽǼ������ϴ�";
                    //cout << endl << "�ٽ� �Է��ϼ���" << endl << endl;
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
                    //cout << endl << "������ �Է��ϽǼ������ϴ�";
                    //cout << endl << "�ٽ� �Է��ϼ���" << endl << endl;
                    i = i - 1;
                }
            }
            zuk.set(input[0], input[1], input[2]);
            zuk.show();
        }
        else if (select == 3) {
            //cout << "���α׷��� �����մϴ�" << endl;
            break;
        }
        else {
            //cout << "�߸��Է��ϼ̽��ϴ�" << endl;
        }
    }
}

