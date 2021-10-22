//
// Created by coolsyn on 2021/10/21.
//

#ifndef COMPUTER_ROOM_RESERVE_ORDERFILE_H
#define COMPUTER_ROOM_RESERVE_ORDERFILE_H

#endif //COMPUTER_ROOM_RESERVE_ORDERFILE_H
#pragma once
#include "iostream"
using namespace std;
#include "map"
#include "globalFile.h"
class OrderFile
{
public:
    OrderFile();
    void updateOrder();
    map<int,map<string,string>> m_orderData;
    int m_Size;
};