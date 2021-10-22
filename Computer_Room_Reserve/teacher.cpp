//
// Created by coolsyn on 2021/10/17.
//

#include "teacher.h"
#include "orderFile.h"
Teacher::Teacher()
{}
Teacher::Teacher(int empId,string name,string pwd)
{
    this->m_EmpId=empId;
    this->m_Name=name;
    this->m_Pwd=pwd;
}
void Teacher::openMenu()
{
    cout<<"welcome: "<<this->m_Name<<endl;
    cout<<"1.show all order\n";
    cout<<"2.check order\n";
    cout<<"logout\n";
    cout<<"enter select\n";
}
void Teacher::showAllOrder()
{
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
void Teacher::validOrder()
{
    OrderFile of;
    if (of.m_Size == 0) {
        cout<<"no reservation record\n";
        system("pause");
        system("cls");
        return;
    }
    cout<<"record waiting to check\n";
    vector<int>v;
    int index=0;
    for(int i=0;i<of.m_Size;i++) {
        if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "1") {
            v.push_back(i);
            cout << ++index << ".";
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
        cout<<"select the record 0---return\n";
        int select=0;
        int ret=0;
        while(true)
        {
            cin>>select;
            if(select>=0&&select<=v.size())
            {
                if(select==0)
                {break;}
                else
                {
                    cout<<"enter the result\n"<<endl;
                    cout<<"1.pass\n";
                    cout<<"2.failed\n";
                    cin>>ret;
                    if(ret==1)
                    {
                        of.m_orderData[v[select-1]]["status"]="2";
                    }
                    else
                    {
                        of.m_orderData[v[select-1]]["status"]="-1";
                    }
                    of.updateOrder();
                    cout<<"check finished\n";
                    break;
                }
            }
        }
    system("pause");
    system("cls");
}