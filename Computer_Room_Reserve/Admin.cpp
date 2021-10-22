//
// Created by coolsyn on 2021/10/17.
//

#include "Admin.h"
#include "fstream"
#include "globalFile.h"
void printStudent(Student &s)
{
    cout<<"id:"<<s.m_Id<<"\tname:"<<s.m_Name<<"\tpassword:"<<s.m_Pwd<<endl;
}
void printTeacher(Teacher &t)
{
    cout<<"id:"<<t.m_EmpId<<"\tname:"<<t.m_Name<<"\tpassword:"<<t.m_Pwd<<endl;
}
Admin::Admin(){}
Admin::Admin(string name,string pwd){
    this->m_Name=name;
    this->m_Pwd=pwd;
    this->initVector();
    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);
    ComputerRoom c;
    while(ifs>>c.m_ComId&&ifs>>c.m_Maxium)
    {
        vCom.push_back(c);
    }
    cout<<"Number of computer room :"<<vCom.size()<<endl;
    ifs.close();
}
void Admin::openMenu(){
    cout<<"name:\t"<<this->m_Name<<endl;
    cout<<"1.add account\n";
    cout<<"2.view account\n";
    cout<<"3.view computer\n";
    cout<<"4.clear order\n";
    cout<<"0.logout\n";
    cout<<"enter your select\n";
}
void Admin::addPerson(){
    cout<<"enter type of account\n";
    cout<<"1.add student account\t2.add teacher account\n";
    string fileName;
    string tip;
    ofstream ofs;
    string errorTip;
    int select;
    cin>>select;
    if(select==1)
    {
        fileName=STUDENT_FILE;
        tip="enter the Student id\n";
        errorTip="student id already exist";
    }
    else
    {
        fileName=TEACHER_FILE;
        tip="enter the employee id\n";
        errorTip="teacher id already exist";
    }
    ofs.open(fileName,ios::out|ios::app);
    int id;
    string name;
    string pwd;
    cout<<tip<<endl;
    while(true) {
        cin >> id;
        bool ret=this->checkRepeat(id,1);
        if(ret) {
            cout<<errorTip<<endl;
        }
        else {
            break;
        }
    }
    cout<<"enter name\n";
    cin>>name;
    cout<<"enter password\n";
    cin>>pwd;
    ofs<<id<<" "<<name<<" "<<pwd<<endl;
    cout<<"add successfully\n";
    system("pause");
    system("cls");
    ofs.close();
    this->initVector();
}
void Admin::showPerson(){
    cout<<"select the content\n";
    cout<<"1---student\t2---teacher\n";
    int select;
    cin>>select;
    if(select==1)
    {
        cout<<"all student info:\n";
        for_each(vStu.begin(),vStu.end(), printStudent);
    }
    else
    {
        cout<<"all teacher info:\n";
        for_each(vTea.begin(),vTea.end(), printTeacher);
    }
    system("pause");
    system("cls");
}
void Admin::showComputer(){
    cout<<"computer info:\n";
    for(vector<ComputerRoom>::iterator it=vCom.begin();it!=vCom.end();it++)
    {
     cout<<"computer room id: "<<it->m_ComId<<"\tMAXIUM: "<<it->m_Maxium<<endl;
    }
    system("pause");
    system("cls");
}
void Admin::cleanFile(){
    ofstream ofs;
    ofs.open(ORDER_FILE,ios::trunc);
    ofs.close();
    cout<<"clear successfully\n";
    system("pause");
    system("cls");
}

void Admin::initVector() {
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if(!ifs.is_open())
    {
        cout<<"student file read failed\n";
        return;
    }
    vStu.clear();
    vTea.clear();
    Student S;
    while(ifs>>S.m_Id&&ifs>>S.m_Name&&ifs>>S.m_Pwd)
    {
        vStu.push_back(S);
    }
    cout<<"Number of students: "<<vStu.size()<<endl;
    ifs.close();
    ifs.open(TEACHER_FILE,ios::in);
    Teacher T;
    if(!ifs.is_open())
    {
        cout<<"teacher file read failed\n";
        return;
    }
    while (ifs>>T.m_EmpId&&ifs>>T.m_Name&&ifs>>T.m_Pwd)
    {
        vTea.push_back(T);
    }
    cout<<"Number of teacher: "<<vTea.size()<<endl;
    ifs.close();
}

bool Admin::checkRepeat(int id,int type) {
    if (type == 1) {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
            if (id == it->m_Id) {
                return true;
            }
        }
    } else {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
            if (id == it->m_EmpId) {
                return true;
            }
        }
    }
    return false;
}
