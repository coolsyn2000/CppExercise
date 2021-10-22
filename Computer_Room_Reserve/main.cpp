#include <iostream>
#include "globalFile.h"
#include "fstream"
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"
using namespace std;

void studentMenu(Identity * &student)
{
    while(true)
    {
        student->openMenu();
        Student* stu=(Student*)student;
        int select=0;
        cin>>select;
        if(select==1)
        {
            stu->applyOrder();

        }
        else if(select==2)
        {
            stu->showOrder();
        }
        else if(select==3)
        {
            stu->showAllOrder();
        }
        else if(select==4)
        {
            stu->cancelOrder();
        }
        else
        {
            delete student;
            cout<<"logout successfully\n";
            system("pause");
            system("cls");
            return;
        }
    }
}

void adminMenu(Identity * &admin){
    while(true)
    {
        admin->openMenu();
        Admin* man=(Admin*)admin;
        int select=0;
        cin>>select;
        if(select==1)
        {
            cout<<"add account\n";
            man->addPerson();

        }
        else if(select==2)
        {
            cout<<"view account\n";
            man->showPerson();
        }
        else if(select==3)
        {
            cout<<"view computer\n";
            man->showComputer();
        }
        else if(select==4)
        {
            cout<<"clear order\n";
            man->cleanFile();
        }
        else
        {
            delete admin;
            cout<<"logout successfully\n";
            system("pause");
            system("cls");
            return;
        }
    }
}

void teacherMenu(Identity * teacher){
    while(true)
    {
        teacher->openMenu();
        Teacher* tea=(Teacher*)teacher;
        int select=0;
        cin>>select;
        if(select==1)
        {
            tea->showAllOrder();

        }
        else if(select==2)
        {
            tea->validOrder();
        }
        else
        {
            delete teacher;
            cout<<"logout successfully\n";
            system("pause");
            system("cls");
            return;
        }
    }
}

void LoginIn(string fileName,int type)
{
    Identity *person=NULL;
    ifstream ifs;
    ifs.open(fileName,ios::in);
    if(!ifs.is_open())
    {
        cout<<"file does not exist\n";
        ifs.close();
        return;
    }

    int id=0;
    string name;
    string pwd;
    if(type==1)
    {
        cout<<"enter you student id\n";
        cin>>id;
    }
    else if(type==2)
    {
        cout<<"enter you employee id\n";
        cin>>id;
    }
    cout<<"enter user name\n";
    cin>>name;
    cout<<"enter passoword\n";
    cin>>pwd;
    if(type==1)
    {
        int fId;
        string fName;
        string fPwd;
        while(ifs>>fId&&ifs>>fName&&ifs>>fPwd)
        {
            if(id==fId&&name==fName&&pwd==fPwd)
            {
                cout<<"student verify successfully\n";
                system("pause");
                system("cls");
                person =new Student (id,name,pwd);
                studentMenu(person);
                return;
            }
        }
    }
    else if(type==2)
    {
        int fId;
        string fName;
        string fPwd;
        while(ifs>>fId&&ifs>>fName&&ifs>>fPwd)
        {
            if(id==fId&&name==fName&&pwd==fPwd)
            {
                cout<<"teacher verify successfully\n";
                system("pause");
                system("cls");
                person =new Teacher (id,name,pwd);
                teacherMenu(person);
                return;
            }
        }
    }
    else if(type==3)
    {
        string fName;
        string fPwd;
        while(ifs>>fName&&ifs>>fPwd)
        {
            if(name==fName&&pwd==fPwd)
            {
                cout<<"admin verify successfully\n";
                system("pause");
                system("cls");
                person =new Admin (name,pwd);
                adminMenu(person);

                return;
            }
        }
    }
    cout<<"verify failed\n";
    system("pause");
    system("cls");


}


int main() {
    int select;
    while(true) {
        cout << "enter your identify\n";
        cout << "1.Student\n";
        cout << "2.Teacher\n";
        cout << "3.Admin\n";
        cout << "0.Exit\n";
        cout << "Select\n";
        cin>>select;
        switch(select)
        {
            case 1:
                LoginIn(STUDENT_FILE,1);
                break;
            case 2:
                LoginIn(TEACHER_FILE,2);
                break;
            case 3:
                LoginIn(ADMIN_FILE,3);
                break;
            case 0:
                cout<<"exiting\n";
                system("pause");
                return 0;
                break;
            default:
                cout<<"invalid select!\tenter the select again!\n";
                system("pause");
                system("cls");
                break;
        }
    }
    system("pause:");
    return 0;
}
