#include <iostream>
#include "speechManager.h"
#include "string"
#include "ctime"
using namespace std;
int main() {
    srand((unsigned int)time(NULL));
    SpeechManager sm;
    sm.show_Menu();
    /*for(map<int,Speaker>::iterator it=sm.m_speaker.begin();it!=sm.m_speaker.end();it++)
    {
        cout<<"speak no:"<<it->first<<'\t'<<"speak name: "<<it->second.m_name<<"\tspeak score:"<<it->second.m_score[0]<<endl;
    }
     */
    int select;
    while(true) {
        cout << "enter choice\n";
        cin >> select;
        switch (select)
        {
            case 0:
                sm.exit_Menu();
                break;
            case 1:
                sm.startSpeech();
                break;
            case 2:
                sm.showRecord();
                break;
            case 3:
                sm.clearRecord();
                break;
            default:
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
