//
// Created by coolsyn on 2021/10/14.
//
#include "speechManager.h"
#include "algorithm"
#include "deque"
#include "functional"
#include "numeric"
#include "string"
#include "fstream"

SpeechManager::SpeechManager() {
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
}

void SpeechManager::clearRecord()
{
    cout<<"sure to clear\n";
    cout<<"1---yes\t2---no\n";
    int select=0;
    cin>>select;
    if(select==1)
    {
        ofstream ofs("speech.csv",ios::trunc);
        ofs.close();
        this->initSpeech();
        this->createSpeaker();
        this->loadRecord();
        cout<<"clear successfully!\n";
    }
}

void SpeechManager::show_Menu() {
    cout << "WELCOME TO SPEECH MANAGE SYSTEM\n";
    cout << "1.Start\n";
    cout << "2.Check old files\n";
    cout << "3.Clear records\n";
    cout << "0.Exit system\n";

}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++) {
        string name = "speaker";
        name += nameSeed[i];
        Speaker sp;
        sp.m_name = name;
        for (int j = 0; j < 2; j++) {
            sp.m_score[j] = 0;
        }
        this->v1.push_back(i + 10001);
        this->m_speaker.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::startSpeech() {
    this->speechDraw();
    this->speechContest();
    this->showScore();
    this->m_index++;
    this->speechDraw();
    this->speechContest();
    this->showScore();
    this->saveRecord();
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
    cout << "this competition is over\n";
    system("pause");
    system("cls");

}

void SpeechManager::speechContest() {
    cout << "no:" << this->m_index << "competition begin\n";
    vector<int> v_src;
    multimap<double, int, greater<double>> groupScore;
    int num = 0;
    if (this->m_index == 1) {
        v_src = v1;
    } else {
        v_src = v2;
    }
    for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++) {
        num++;
        deque<double> d;
        for (int i = 0; i < 10; i++) {
            double score = (rand() % 401 + 600) / 10.f;
            //cout<<score<<'\t';
            d.push_back(score);
        }
        //cout<<endl;
        sort(d.begin(), d.end(), greater<double>());
        d.pop_front();
        d.pop_back();
        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double) d.size();
        this->m_speaker[*it].m_score[this->m_index - 1] = avg;
        groupScore.insert(make_pair(avg, *it));
        //cout<<"no:"<<*it<<"\tname:"<<this->m_speaker[*it].m_name<<"\tavg:"<<avg<<endl;
        if (num % 6 == 0) {
            cout << "no:" << num / 6 << "result:\n";
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end(); it++) {
                cout << "no:" << it->second << "\tname:"
                     << this->m_speaker[it->second].m_name
                     << "\tscore:" << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
            }
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end() && count < 3; it++, count++) {
                if (this->m_index == 1) {
                    v2.push_back((*it).second);
                } else {
                    vVictory.push_back(((*it).second));
                }
            }
            groupScore.clear();
        }
    }
    cout << "no:" << this->m_index << "epoch is over" << endl;
    system("pause");
}

void SpeechManager::speechDraw() {
    cout << "NO:" << this->m_index << " is drawing\n";
    cout << "sequence:\n";
    if (this->m_index == 1) {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    } else {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    system("pause");
    cout << endl;

}

void SpeechManager::exit_Menu() {
    cout << "Existing system\n";
    system("pause");
    exit(0);
}

void SpeechManager::initSpeech() {
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_speaker.clear();
    this->m_index = 1;
    this->m_Record.clear();
}

void SpeechManager::showScore() {
    cout << "no:" << this->m_index << "epoch winner-speaker:\n";
    vector<int> v;
    if (this->m_index == 1) {
        v = v2;
        //cout<<this->v2.size()<<endl;
    } else {
        v = vVictory;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "speaker no:" << *it << "name:" << this->m_speaker[*it].m_name << "\tScore:"
             << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
    this->show_Menu();
}

void SpeechManager::saveRecord() {
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);

    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
        ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "file is saved\n";
    fileIsEmpty = false;
}

void SpeechManager::loadRecord() {
    ifstream ifs("speech.csv", ios::in);
    if (!ifs.is_open()) {
        this->fileIsEmpty = true;
        //cout<<"file does not exist\n";
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "file is empty\n";
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    this->fileIsEmpty = false;
    ifs.putback(ch);
    string data;
    int index = 0;
    while (ifs >> data) {
        //cout<<data<<endl;
        vector<string> v;
        int pos = -1;
        int start = 0;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                break;
            }
            string temp = data.substr(start, pos - start);
            //cout<<temp<<endl;
            v.push_back(temp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
    for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != m_Record.end(); it++) {
        cout << it->first << "winner" << it->second[0] << "score:" << it->second[1] << endl;
    }
}

void SpeechManager::showRecord() {
    if (this->fileIsEmpty) {
        cout << "file does not exist or is empty\n";
    }
    for (int i = 0; i < this->m_Record.size(); i++) {
        cout << "no:" << i + 1 << " epoch"
             << "1st id:" << this->m_Record[i][0] << "score:" << this->m_Record[i][1] << "\t"
             << "2nd id:" << this->m_Record[i][2] << "score:" << this->m_Record[i][3] << "\t"
             << "3rd id:" << this->m_Record[i][4] << "score:" << this->m_Record[i][5] << "\n";
    }
    system("pause");
    system("cls");
}

SpeechManager::~SpeechManager() {

}