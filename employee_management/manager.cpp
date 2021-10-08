//
// Created by coolsyn on 2021/10/7.
//
#include "./header/manager.h"
Manager::Manager(int id, string name, int dId) {
    this->m_Id=id;
    this->m_Name=name;
    this->m_DeptId=dId;
}
void Manager::showInfo() {
    cout<<"manager id :"<< this->m_Id<<"\t name:"<<this->m_Name
        <<"\tdepartment:"<<this->getDeptName()
        <<"\tJob: finish the task from boss and hand out task to employees\n";
}
string Manager::getDeptName() {
    return string("manager");
}