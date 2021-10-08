//
// Created by coolsyn on 2021/10/7.
//
#include <iostream>
#include <string>
#include "./header/employee.h"

Employee::Employee(int id,string name,int dId)
{
    this->m_Id=id;
    this->m_Name=name;
    this->m_DeptId=dId;
}
void Employee::showInfo() {
    cout<<"employee id :"<< this->m_Id<<"\t name:"<<this->m_Name
    <<"\tdepartment:"<<this->getDeptName()
    <<"\tJob: finish the task\n";
}
string Employee::getDeptName() {
    return string("employee");
}