#include "./header/workerManager.h"

WorkerManager::WorkerManager() {
this->m_EmpNum=0;
this->m_EmpArray=NULL;

}

WorkerManager::~WorkerManager() {

}

void WorkerManager::Show_Menu() {
    cout << "WELCOME TO WORK MANAGEMENT SYSTEM!\n";
    cout << "0.EXIT SYSTEM\n";
    cout << "1.ADD WORKER INFOS\n";
    cout << "2.SHOW WORKER INFOS\n";
    cout << "3.DELETE WORKER\n";
    cout << "4.MODIFY WORKER INFOS\n";
    cout << "5.SEARCH WORKER\n";
    cout << "6.REORDER WORKERS\n";
    cout << "7.EMPTY SYSTEM\n" << endl;
}

void WorkerManager::Exit_Menu() {
cout<<"EXITING\n";
system("pause");
exit(0);
}
void WorkerManager::Add_Emp() {
    cout<<"enter number of employees\n";
    int addNum=0;
    cin>>addNum;
    if(addNum>0)
    {
        int newSize= this->m_EmpNum+addNum;
        Worker ** newSpace = new Worker*[newSize];
        if(this->m_EmpArray!=NULL)
        {
            for(int i =0;i<this->m_EmpNum;i++)
            {
                newSpace[i]=this->m_EmpArray[i];
            }
        }
        for(int i=0;i<addNum;i++)
        {
            int id;
            string name;
            int dSelect;
            cout<<"enter NO."<<i+1<<" id"<<endl;
            cin>>id;
            cout<<"enter NO."<<i+1<<" name"<<endl;
            cin>>name;
            cout<<"enter Department\n1.employee\n2.manager\n3.boss"<<endl;
            cin>>dSelect;
            Worker*worker=NULL;
            switch(dSelect)
            {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker= new Manager(id,name,2);
                    break;
                case 3:
                    worker= new Boss(id,name,3);
                    break;
                default:
                    break;
            }
            newSpace[this->m_EmpNum+i]=worker;
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray=newSpace;
        this->m_EmpNum=newSize;
        cout<<"add "<<addNum<< "person successfully\n";
        system("pause");
        system("cls");
    }
    else
    {
        cout<<"wrong number\n";
    }
}