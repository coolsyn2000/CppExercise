//
// Created by coolsyn on 2021/10/7.
//

#ifndef EMPLOYEE_MANAGEMENT_WORKER_H
#define EMPLOYEE_MANAGEMENT_WORKER_H

#endif //EMPLOYEE_MANAGEMENT_WORKER_H
#pragma once
#include <iostream>
#include "string"
using namespace std;
class Worker{
public:
    virtual void showInfo()=0;
    virtual string getDeptName()=0;
    int m_Id;
    string m_Name;
    int m_DeptId;
};