//
// Created by coolsyn on 2021/10/17.
//

#include "student.h"
#include "fstream"
#include "globalFile.h"

Student::Student() {}

Student::Student(int id, string name, string pwd) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_Maxium) {
        vCom.push_back(c);
    }
    ifs.close();
}

void Student::openMenu() {
    cout << "name: " << this->m_Name << endl;
    cout << "1.apply order\n";
    cout << "2.check my order\n";
    cout << "3.check all order\n";
    cout << "4.cancel my order\n";
    cout << "0.logout\n";
    cout << "enter you choice\n";
}

void Student::applyOrder() {
    cout << "Computer room open from monday to friday\n";
    cout << "enter the day\n";
    cout << "1.Mon  2.Tue y 3.Wen 4.Thur 5.Fri\n";
    int date = 0;

    int interval = 0;
    int room = 0;
    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "enter wrong\n";

    }
    cout << "please enter the time\n";
    cout << "1--am 2--pm\n";
    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "enter wrong\n";
    }
    cout << "choose room\n";
    cout << "No1 space:" << vCom[0].m_Maxium << endl;
    cout << "No2 space:" << vCom[1].m_Maxium << endl;
    cout << "No3 space:" << vCom[2].m_Maxium << endl;
    while (true) {
        cin >> room;
        if (room >= 1 && room <= 3) {
            break;
        }
        cout << "enter wrong\n";
    }
    cout << "reserve successfully\n";
    ofstream ofs(ORDER_FILE, ios::app);

    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;
    ofs.close();
    system("pause");
    system("cls");
}

void Student::showOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "no reservation" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < of.m_Size; i++) {
        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
            cout << "reservation week:" << of.m_orderData[i]["date"];
            cout << " time:" << (of.m_orderData[i]["interval"] == "1" ? "am" : "pm");
            cout << " Room:" << of.m_orderData[i]["roomId"];
            string status = "status:";

            if (of.m_orderData[i]["status"] == "1") {
                status += "checking";
            } else if (of.m_orderData[i]["status"] == "2") {
                status += "success";
            } else if (of.m_orderData[i]["status"] == "-1") {
                status += "failed";
            } else {
                status += "cancelled";
            }
            cout << " " + status << endl;
        }
    }
    system("pause");
    system("cls");
}

void Student::showAllOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout<<"no reservation record\n";
        system("pause");
        system("cls");
        return;
    }
    for(int i=0;i<of.m_Size;i++)
    {
        cout<<i+1<<".";
        cout << "reservation week:" << of.m_orderData[i]["date"];
        cout << " time:" << (of.m_orderData[i]["interval"] == "1" ? "am" : "pm");
        cout<<" id:"<<of.m_orderData[i]["stuId"];
        cout<<" name:"<<of.m_orderData[i]["stuName"];
        cout << " Room:" << of.m_orderData[i]["roomId"];
        string status = "status:";
        if (of.m_orderData[i]["status"] == "1") {
            status += "checking";
        } else if (of.m_orderData[i]["status"] == "2") {
            status += "success";
        } else if (of.m_orderData[i]["status"] == "-1") {
            status += "failed";
        } else {
            status += "cancelled";
        }
        cout << " " + status << endl;
    }
    system("pause");
    system("cls");
}

void Student::cancelOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout<<"no reservation record\n";
        system("pause");
        system("cls");
        return;
    }
    cout<<"you can cancel the reservation in checking and success\n";
    vector<int>v;
    int index=1;
    for(int i=0;i<of.m_Size;i++)
    {
        if(atoi(of.m_orderData[i]["stuId"].c_str())==this->m_Id)
        {
            if(of.m_orderData[i]["status"]=="1"||of.m_orderData[i]["status"]=="2")
            {
                v.push_back(i);
                cout<<index++<<".";
                cout << "reservation week:" << of.m_orderData[i]["date"];
                cout << " time:" << (of.m_orderData[i]["interval"] == "1" ? "am" : "pm");
                cout << " Room:" << of.m_orderData[i]["roomId"];
                string status="status:";
                if (of.m_orderData[i]["status"] == "1") {
                    status += "checking";
                } else if (of.m_orderData[i]["status"] == "2") {
                    status += "success";
                } else if (of.m_orderData[i]["status"] == "-1") {
                    status += "failed";
                } else {
                    status += "cancelled";
                }
                cout << " " + status << endl;
            }
        }
    }
    cout<<"enter the record to cancel 0---return\n";
    int select=0;
    while (true)
    {
        cin>>select;
        if(select>=0&&select<=v.size())
        {
            if(select==0)
            {break;}
            else
            {
                of.m_orderData[v[select-1]]["status"]="0";
                of.updateOrder();
                cout<<"canceled\n";
                break;
            }
        }
        cout<<"wrong enter\n";
    }
    system("pause");
    system("cls");
}