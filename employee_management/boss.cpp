//
// Created by coolsyn on 2021/10/7.
//
#include "./header/boss.h"
Boss::Boss(int id, string name, int dId) {
    this->m_Id=id;
    this->m_Name=name;
    this->m_DeptId=dId;
}
void Boss::showInfo() {
    cout<<"id :"<< this->m_Id<<"\t name:"<<this->m_Name
        <<"\tdepartment:"<<this->getDeptName()
        <<"\t\tJob: manage all the affairs of company\n";
}
string Boss::getDeptName() {
    return string("boss");
}