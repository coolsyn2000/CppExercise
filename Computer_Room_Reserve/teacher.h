//
// Created by coolsyn on 2021/10/17.
//

#ifndef COMPUTER_ROOM_RESERVE_TEACHER_H
#define COMPUTER_ROOM_RESERVE_TEACHER_H

#endif //COMPUTER_ROOM_RESERVE_TEACHER_H
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "Identity.h"
using namespace std;
class Teacher:public Identity{
public:
    Teacher();
    Teacher(int empId,string name,string pwd);
    virtual void openMenu();
    void showAllOrder();
    void validOrder();
    int m_EmpId;

};