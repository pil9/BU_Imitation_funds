#include <iostream>
#include <string>

using namespace std;

class User
{
    //ȸ�� ����
    string Name;
    string ID;
    int Password = 0;
    int Phone_Number = 0;

public:  // ����: �ܺο��� �����ϴ� �Լ��� public �κп� ����Ǿ�� �մϴ�.
    User join_membership() {
        User u;
        //ȸ������
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
            cout << "���̵�,��й�ȣ �нǽ� ã�⸦ ���� ��ȭ��ȣ�� �Է����ּ���." << endl;
            cout << "�ڵ��� ��ȣ(-�� �����ϰ� �Է�):";
            cin >> u.Phone_Number;
            cout << u.Name << "���� ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
        }
        else {
            cout << "��й�ȣ�� Ȯ���� ȸ�������� �ٽ� ���ֽñ� �ٶ��ϴ�." << endl;
            // ���: ��й�ȣ�� �߸��Ǿ��ٸ� �ٽ� �Է��� �� �ֵ��� ���ִ� ���� �����ϴ�.
        };
        // ����: ���⼭���� ������ �κ��Դϴ�. join_membership �Լ��� ���� ��ȯ�ؾ� �մϴ�.
        // cout << "����� �Ϸ�Ǿ����ϴ�." << endl;
        return u;
    }
    void login() {
        // ����: User u => �ʿ����� ���� �����Դϴ�.
        int Password1;
        cout << "��й�ȣ �Է�:";
        cin >> Password1;
        if (Password == Password1) {  // ����: u.Password ��� this->Password�� ����մϴ�.
            cout << Name << " ȸ������ �湮�� ȯ���մϴ�.";  // ����: u.Name ��� this->Name�� ����մϴ�.
        }
        else {
            cout << "���̵�� ��й�ȣ�� Ȯ���� �ٽ� �α��� �Ͻñ� �ٶ��ϴ�.";
            cout << "���̵�� ��й�ȣ�� ������ ���� �ʴ´ٸ� �ڵ��� ��ȣ��" << endl;
            cout << "���� ���̵�,��й�ȣ ã�⸦ �Ҽ� �ֽ��ϴ�.";
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
                // �ߺ��� ID. �߰� ó���� ��ȯ ���� �̿��ؼ� �����ϼ���.
                return false;
            }
        }

        // ���� �����͸� �߰��մϴ�.
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
                // ID�� ã�ҽ��ϴ�. �ش� �����͸� ��ȯ�մϴ�.
                return _data[i];
            }
        }

        // ID�� ã�� ���߽��ϴ�. ������ ��ȯ�մϴ�.
        throw exception("ID�� ã�� ���߽��ϴ�.");
    }
};

int main()
{
    my_container members;
    User u;

    char choice = '0'; //�޴� ����
    int menu = 0; //�̿��� ��� �޴� ����

    cout << "�޴��� ������ �ּ���.(a.ȸ������ �� �α��� b.����)" << endl;
    cin >> choice;

    switch (choice) {
    case'a':
        while (true) {
            cout << "�̿��ڵ�� �޴��� �����ϼ̽��ϴ�." << endl;
            cout << "ó������ �е��� ȸ�������� �������ּ���." << endl;
            cout << "�޴��� �������ּ���.(1.ȸ������ 2.�α��� 3.���̵�,��� ã�� 0.����)" << endl;
            cin >> menu;
            switch (menu) {
            case 1:
                members.add(u.join_membership());
                break;
            case 2:
            {
                string ID1;  // ����: ID�� ���� ã�Ƽ� ������ ��Ͽ��� �ĺ��մϴ�.
                cout << "�α����� ���� ���̵�� ��й�ȣ�� �Է����ּ���." << endl;
                cout << "���̵� �Է�:";
                cin >> ID1;
                User find = members.find_from_id(ID1);  // ���: ID�� �ݵ�� ã�Ҵٰ� �����մϴ�. ���� ã�� ������ ����� ó���� �ϰ� �ʹٸ� try-catch ������ �̿��Ͽ� ���ܸ� �����մϴ�.
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