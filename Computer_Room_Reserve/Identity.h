//
// Created by coolsyn on 2021/10/17.
//

#ifndef COMPUTER_ROOM_RESERVE_IDENTITY_H
#define COMPUTER_ROOM_RESERVE_IDENTITY_H

#endif //COMPUTER_ROOM_RESERVE_IDENTITY_H
#pragma once
#include "iostream"
#include "string"
#include "vector"
using namespace std;
class Identity
{
public:
    virtual void openMenu()=0;
    string m_Name;
    string m_Pwd;
};