#include <iostream>
#include <string>

using namespace std;

class User
{
    //회원 정보
    string Name;
    string ID;
    int Password = 0;
    int Phone_Number = 0;

public:  // 수정: 외부에서 접근하는 함수는 public 부분에 선언되어야 합니다.
    User join_membership() {
        User u;
        //회원가입
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
            cout << "아이디,비밀번호 분실시 찾기를 위해 전화번호를 입력해주세요." << endl;
            cout << "핸드폰 번호(-을 제외하고 입력):";
            cin >> u.Phone_Number;
            cout << u.Name << "님의 회원가입이 완료되었습니다." << endl;
        }
        else {
            cout << "비밀번호를 확인후 회원가입을 다시 해주시기 바랍니다." << endl;
            // 경고: 비밀번호가 잘못되었다면 다시 입력할 수 있도록 해주는 것이 좋습니다.
        };
        // 수정: 여기서부터 누락된 부분입니다. join_membership 함수는 값을 반환해야 합니다.
        // cout << "등록이 완료되었습니다." << endl;
        return u;
    }
    void login() {
        // 수정: User u => 필요하지 않은 구문입니다.
        int Password1;
        cout << "비밀번호 입력:";
        cin >> Password1;
        if (Password == Password1) {  // 수정: u.Password 대신 this->Password를 사용합니다.
            cout << Name << " 회원님의 방문을 환영합니다.";  // 수정: u.Name 대신 this->Name를 사용합니다.
        }
        else {
            cout << "아이디와 비밀번호를 확인후 다시 로그인 하시기 바랍니다.";
            cout << "아이디와 비밀번호가 생각이 나지 않는다면 핸드폰 번호를" << endl;
            cout << "통해 아이디,비밀번호 찾기를 할수 있습니다.";
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
                // 중복된 ID. 추가 처리를 반환 값을 이용해서 구분하세요.
                return false;
            }
        }

        // 유저 데이터를 추가합니다.
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
                // ID를 찾았습니다. 해당 데이터를 반환합니다.
                return _data[i];
            }
        }

        // ID를 찾지 못했습니다. 오류를 반환합니다.
        throw exception("ID를 찾지 못했습니다.");
    }
};

int main()
{
    my_container members;
    User u;

    char choice = '0'; //메뉴 선택
    int menu = 0; //이용자 등록 메뉴 선택

    cout << "메뉴를 선택해 주세요.(a.회원가입 및 로그인 b.종료)" << endl;
    cin >> choice;

    switch (choice) {
    case'a':
        while (true) {
            cout << "이용자등록 메뉴를 선택하셨습니다." << endl;
            cout << "처음오신 분들은 회원가입을 선택해주세요." << endl;
            cout << "메뉴를 선택해주세요.(1.회원가입 2.로그인 3.아이디,비번 찾기 0.종료)" << endl;
            cin >> menu;
            switch (menu) {
            case 1:
                members.add(u.join_membership());
                break;
            case 2:
            {
                string ID1;  // 수정: ID를 먼저 찾아서 데이터 목록에서 식별합니다.
                cout << "로그인을 위해 아이디와 비밀번호를 입력해주세요." << endl;
                cout << "아이디 입력:";
                cin >> ID1;
                User find = members.find_from_id(ID1);  // 경고: ID는 반드시 찾았다고 가정합니다. 만약 찾지 못했을 경우의 처리를 하고 싶다면 try-catch 구문을 이용하여 예외를 수집합니다.
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