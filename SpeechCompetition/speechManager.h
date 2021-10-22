//
// Created by coolsyn on 2021/10/14.
//

#ifndef SPEECHCOMPETITION_SPEECHMANAGER_H
#define SPEECHCOMPETITION_SPEECHMANAGER_H

#endif //SPEECHCOMPETITION_SPEECHMANAGER_H
#pragma once
#include "iostream"
#include "vector"
#include "map"
#include "speaker.h"
#include "string"
using namespace std;
class SpeechManager{
public:
    SpeechManager();

    void showRecord();

    void clearRecord();

    void show_Menu();

    void exit_Menu();

    void initSpeech();

    void startSpeech();

    void speechDraw();

    void speechContest();

    void createSpeaker();

    void showScore();

    void saveRecord();

    void loadRecord();

    ~SpeechManager();
    bool fileIsEmpty;
    map<int,vector<string>> m_Record;
    vector<int>v1;
    vector<int>v2;
    vector<int>vVictory;
    map<int,Speaker>m_speaker;
    int m_index;
};