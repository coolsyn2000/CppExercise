//
// Created by coolsyn on 2021/10/7.
//

#ifndef EMPLOYEE_MANAGEMENT_BOSS_H
#define EMPLOYEE_MANAGEMENT_BOSS_H

#endif //EMPLOYEE_MANAGEMENT_BOSS_H
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Boss:public Worker
{
public:
Boss(int id, string name,int dId);
virtual void showInfo();
virtual string getDeptName();
};