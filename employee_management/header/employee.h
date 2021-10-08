//
// Created by coolsyn on 2021/10/7.
//

#ifndef EMPLOYEE_MANAGEMENT_EMPLOYEE_H
#define EMPLOYEE_MANAGEMENT_EMPLOYEE_H

#endif //EMPLOYEE_MANAGEMENT_EMPLOYEE_H
#pragma once
#include <iostream>
#include "worker.h"
using namespace std;
class Employee:public Worker{
public:
    Employee(int id,string name,int dId);
    virtual void showInfo();
    virtual string getDeptName();
};
