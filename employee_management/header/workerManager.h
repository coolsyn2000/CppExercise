//
// Created by coolsyn on 2021/10/7.
//

#ifndef EMPLOYEE_MANAGEMENT_WORKERMANAGER_H
#define EMPLOYEE_MANAGEMENT_WORKERMANAGER_H

#endif //EMPLOYEE_MANAGEMENT_WORKERMANAGER_H

#pragma once
#include <iostream>
#include <fstream>
#define  FILENAME "empFile.txt"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
class WorkerManager
{
public:
    WorkerManager();
    void Show_Menu();
    void Exit_Menu();
    int m_EmpNum;
    int get_EmpNum();
    bool m_FileIsEmpty;
    Worker ** m_EmpArray;
    void Add_Emp();
    void save();
    void init_emp();
    void Show_Emp();
    void Del_Emp();
    void Mod_Emp();
    void Find_Emp();
    int IsExist(int id);
    ~WorkerManager();
};
