//
// Created by coolsyn on 2021/10/7.
//

#ifndef EMPLOYEE_MANAGEMENT_MANAGER_H
#define EMPLOYEE_MANAGEMENT_MANAGER_H

#endif //EMPLOYEE_MANAGEMENT_MANAGER_H
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Manager:public Worker{
public:

    Manager(int id, string name,int dId);
    virtual void showInfo();
    virtual string getDeptName();

};