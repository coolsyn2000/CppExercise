//
// Created by coolsyn on 2021/10/17.
//

#ifndef COMPUTER_ROOM_RESERVE_ADMIN_H
#define COMPUTER_ROOM_RESERVE_ADMIN_H

#endif //COMPUTER_ROOM_RESERVE_ADMIN_H
#pragma once
#include "Identity.h"
#include "string"
#include "student.h"
#include "teacher.h"
#include "algorithm"
#include "computerRoom.h"
using namespace std;
class Admin:public Identity{
public:
    Admin();
    Admin(string name,string pwd);
    virtual void openMenu();
    void addPerson();
    void showPerson();
    void showComputer();
    void cleanFile();
    void initVector();
    bool checkRepeat(int id,int type);
    vector<Student>vStu;
    vector<Teacher>vTea;
    vector<ComputerRoom> vCom;
};