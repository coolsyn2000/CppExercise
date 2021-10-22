//
// Created by coolsyn on 2021/10/17.
//

#ifndef COMPUTER_ROOM_RESERVE_STUDENT_H
#define COMPUTER_ROOM_RESERVE_STUDENT_H

#endif //COMPUTER_ROOM_RESERVE_STUDENT_H
#pragma once
#include "iostream"
#include "Identity.h"
#include "string"
#include "computerRoom.h"
#include "orderFile.h"
using namespace std;
class Student:public Identity{
public:
    Student();
    Student(int id,string name,string pwd);
    virtual void openMenu();
    void applyOrder();
    void showOrder();
    void showAllOrder();
    void cancelOrder();
    int m_Id;
    vector<ComputerRoom>vCom;
};