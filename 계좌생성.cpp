#include<iostream> 
#include<cstring> 
using namespace std;

int idx = 0;

typedef struct Account {

    int AccId;
    int money;

}Acc;

//���� ���� �Լ� 

void CrtAcc(Acc* usr) {

    int id;
    int money;

 cout << "[���°���]\n";
 cout << "���� ID:";

 cin >> id;
 cout << "�� ��:";

  cin >> name;
 cout << "�Աݾ�:";

 cin >> money;
 usr->AccId = id;

    usr->money = money;

    strcpy(usr->name, name);

}


void OuputAccInquiry(Acc* usr) {

    cout << "idx=" << idx << endl;

    for (int i = 0; i < idx; i++) {

        cout << "����ID:" << usr[i].AccId << endl;
        cout << "�� ��:" << usr[i].name << endl;
        cout << "�� ��:" << usr[i].money << endl;

    }

}

int main() {

    Acc Account[100];

    while (1) {

        cout << "------Menu---------\n";

        cout << "1.���°���\n";

        cout << "2.�� ��\n";

        cout << "3.�� ��\n";

        cout << "4.���α׷� ����\n";

        cout << "���� : ";

        int choice;

        cin >> choice;

        switch (choice) {

        case 1:

            CrtAcc(&Account[idx]);

            idx++;

            break;

        case 2:

            break;

        case 3:

         break;

        case 4:

            break;

 
        default:

            cout << "�߸��� �Է��Դϴ�.\n";

            break;

        }

        if (choice == 4) {

            cout << "���α׷��� �����մϴ�.\n";

            break;

        }
    }
}
