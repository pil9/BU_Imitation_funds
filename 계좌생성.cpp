#include<iostream> 
#include<cstring> 
using namespace std;

int idx = 0;

typedef struct Account {

    int AccId;
    int money;

}Acc;

//계좌 개설 함수 

void CrtAcc(Acc* usr) {

    int id;
    int money;

 cout << "[계좌개설]\n";
 cout << "계좌 ID:";

 cin >> id;
 cout << "이 름:";

  cin >> name;
 cout << "입금액:";

 cin >> money;
 usr->AccId = id;

    usr->money = money;

    strcpy(usr->name, name);

}


void OuputAccInquiry(Acc* usr) {

    cout << "idx=" << idx << endl;

    for (int i = 0; i < idx; i++) {

        cout << "계좌ID:" << usr[i].AccId << endl;
        cout << "이 름:" << usr[i].name << endl;
        cout << "잔 액:" << usr[i].money << endl;

    }

}

int main() {

    Acc Account[100];

    while (1) {

        cout << "------Menu---------\n";

        cout << "1.계좌개설\n";

        cout << "2.출 금\n";

        cout << "3.입 금\n";

        cout << "4.프로그램 종료\n";

        cout << "선택 : ";

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

            cout << "잘못된 입력입니다.\n";

            break;

        }

        if (choice == 4) {

            cout << "프로그램을 종료합니다.\n";

            break;

        }
    }
}
