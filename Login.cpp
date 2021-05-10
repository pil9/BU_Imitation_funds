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
        cout << "ȸ�������� ���� ȸ������ ����,���̵�,��й�ȣ,��ȭ��ȣ�� ������ּ���." << endl;
        cout << "����:";
        cin >> u.Name;
        cout << "ID:";
        cin >> u.ID;
        cout << "PASSWORD(���� 4�ڸ� �Է�):";
        cin >> u.Password;
        cout << "PASSWORDȮ��:";
        cin >> PWCheck;
        if (u.Password == PWCheck) {
            cout << "�н����尡 ��ġ�մϴ�." << endl;
            cout << u.Name << "���� ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
        }
        else {
            cout << "��й�ȣ�� Ȯ���� ȸ�������� �ٽ� ���ֽñ� �ٶ��ϴ�." << endl;
            
        };
        
        return u;
    }
    void login() {
       
        int Password1;
        cout << "��й�ȣ �Է�:";
        cin >> Password1;
        if (Password == Password1) {  
            cout << Name << " ȸ������ �湮�� ȯ���մϴ�.";  
        }
        else {
            cout << "���̵�� ��й�ȣ�� Ȯ���� �ٽ� �α��� �Ͻñ� �ٶ��ϴ�.";
           
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

        throw exception("ID�� ã�� ���߽��ϴ�.");
    }
};

int main()
{
    my_container members;
    User u;

    char choice = '0'; 
    int menu = 0; 

    cout << "�޴��� ������ �ּ���.(a.ȸ������ �� �α��� b.����)" << endl;
    cin >> choice;

    switch (choice) {
    case'a':
        while (true) {
         
            cout << "�޴��� �������ּ���.(1.ȸ������ 2.�α��� 3.��������)" << endl;
            cin >> menu;
            switch (menu) {
            case 1:
                members.add(u.join_membership());
                break;
            case 2:
            {
                string ID1; 
                cout << "�α����� ���� ���̵�� ��й�ȣ�� �Է����ּ���." << endl;
                cout << "���̵� �Է�:";
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