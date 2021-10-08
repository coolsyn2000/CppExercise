/*
Simple CPP AddressBook in memory
Functions：
1.Add person
2.Show person
3.Delete person
4.Search person
5.Modify person
6.Empty Addressbook
0.Exit 
Link : https://www.bilibili.com/video/BV1et411b73Z?p=73  p73-83
*/

#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct Addressbooks
{
    struct Person personArray[MAX];
    int m_Size;
};

void showDetails(Addressbooks *abs, int i)
{
    cout << "name: " << abs->personArray[i].m_Name << '\t';
    cout << "sex: " << (abs->personArray[i].m_Sex == 1 ? "male" : "female") << '\t';
    cout << "age: " << abs->personArray[i].m_Age << '\t';
    cout << "phone: " << abs->personArray[i].m_Phone << '\t';
    cout << "addr: " << abs->personArray[i].m_Addr << '\n';
}
void showPerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "List is empty\n";
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            showDetails(abs, i);
        }
    }
    system("pause");
    system("cls");
}

int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
            return i;
    }
    return -1;
}

void findPerson(Addressbooks *abs)
{
    cout << "enter the name you want find\n";
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        showDetails(abs, ret);
    }
    else
    {
        cout << "not founded\n";
    }
    system("pause");
    system("cls");
}

void deletePerson(Addressbooks *abs)
{
    cout << "enter the name of person you want to delete:\n";
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "delete successfully\n";
    }
    else
    {
        cout << "person not founded\n";
    }
    system("pause");
    system("cls");
}

void modifyPerson(Addressbooks *abs)
{
    cout << "enter the name you want to modify:\n";
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        string name;
        int sex;
        int age;
        string phone;
        string addr;
        cout << "enter name:\n";
        cin >> name;
        abs->personArray[ret].m_Name = name;
        cout << "enter gender:\n(1--male  2--female)\n";
        while (true)
        {
            cin >> sex;
            if (sex != 1 && sex != 2)
            {
                cout << "enter the right gender!\n";
            }
            else
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
        }
        cout << "enter age:\n";
        cin >> age;
        abs->personArray[ret].m_Age = age;
        cout << "enter phone number\n";
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;
        cout << "enter the address:\n";
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;
        cout << "modify successfully\n";
    }
    else
    {
        cout << "not founded\n";
    }
    system("pause");
    system("cls");
}

void cleanPerson(Addressbooks *abs)
{
    abs->m_Size = 0;
    cout << "Addressbooks cleaned\n";
    system("pause");
    system("cls");
}

void showMenu()
{
    cout << "1.Add contact" << '\n';
    cout << "2.Show contact" << '\n';
    cout << "3.Delete contact" << '\n';
    cout << "4.Search contact" << '\n';
    cout << "5.Modify contact" << '\n';
    cout << "6.Empty contact" << '\n';
    cout << "0.Exit" << endl;
}

void addPerson(Addressbooks *abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "List is full!\n";

        return;
    }
    else
    {
        string name;
        int sex;
        int age;
        string phone;
        string addr;
        cout << "enter name:\n";
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        cout << "enter gender:\n(1--male  2--female)\n";
        while (true)
        {
            cin >> sex;
            if (sex != 1 && sex != 2)
            {
                cout << "enter the right gender!\n";
            }
            else
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
        }
        cout << "enter age:\n";
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;
        cout << "enter phone number\n";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        cout << "enter the address:\n";
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        abs->m_Size++;
        cout << "Add successfully\n";
        system("pause");
        system("cls");
    }
}
int main()
{
    Addressbooks abs;
    abs.m_Size = 0;

    int select;
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:
            addPerson(&abs);
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
            deletePerson(&abs);
            break;
        case 4:
            findPerson(&abs);
            break;
        case 5:
            modifyPerson(&abs);
            break;
        case 6:
            cleanPerson(&abs);
            break;
        case 0:
            cout << "SEE YOU NEXT TIME\n";
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
