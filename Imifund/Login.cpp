#include <iostream>
#include <string>

using namespace std;

class User
{
  
    string Name;
    string ID;
    int Password = 0;
    

public:  
    User join_membership() {
        User u;
       
        int PWCheck;
        cout << "회원가입을 위해 회원님의 성명,아이디,비밀번호,전화번호를 등록해주세요." << endl;
        cout << "성명:";
        cin >> u.Name;
        cout << "ID:";
        cin >> u.ID;
        cout << "PASSWORD(숫자 4자리 입력):";
        cin >> u.Password;
        cout << "PASSWORD확인:";
        cin >> PWCheck;
        if (u.Password == PWCheck) {
            cout << "패스워드가 일치합니다." << endl;
            cout << u.Name << "님의 회원가입이 완료되었습니다." << endl;
        }
        else {
            cout << "비밀번호를 확인후 회원가입을 다시 해주시기 바랍니다." << endl;
            
        };
        
        return u;
    }
    void login() {
       
        int Password1;
        cout << "비밀번호 입력:";
        cin >> Password1;
        if (Password == Password1) {  
            cout << Name << " 회원님의 방문을 환영합니다.";  
        }
        else {
            cout << "아이디와 비밀번호를 확인후 다시 로그인 하시기 바랍니다.";
           
        }
    }

    string get_id() const
    {
        return ID;
    }
};

class my_container
{
    User _data[100];
    size_t _count;

public:
    my_container() : _data{ }, _count(0)
    {

    }

    bool add(const User& user)
    {
        for (size_t i = 0; i < _count; ++i)
        {
            if (_data[i].get_id() == user.get_id())
            {
               
                return false;
            }
        }

     
        _data[_count++] = user;

        return true;
    }

    User& get(size_t index)
    {
        return _data[index];
    }

    User& find_from_id(const string& id)
    {
        for (size_t i = 0; i < _count; ++i)
        {
            if (_data[i].get_id() == id)
            {
             
                return _data[i];
            }
        }

        throw exception("ID를 찾지 못했습니다.");
    }
};

int main()
{
    my_container members;
    User u;

    char choice = '0'; 
    int menu = 0; 

    cout << "메뉴를 선택해 주세요.(a.회원가입 및 로그인 b.종료)" << endl;
    cin >> choice;

    switch (choice) {
    case'a':
        while (true) {
         
            cout << "메뉴를 선택해주세요.(1.회원가입 2.로그인 3.계좌접속)" << endl;
            cin >> menu;
            switch (menu) {
            case 1:
                members.add(u.join_membership());
                break;
            case 2:
            {
                string ID1; 
                cout << "로그인을 위해 아이디와 비밀번호를 입력해주세요." << endl;
                cout << "아이디 입력:";
                cin >> ID1;
                User find = members.find_from_id(ID1); 
                find.login();
                break;
            }
            case 0:
                break;
            }
        }
    }
    return 0;
}