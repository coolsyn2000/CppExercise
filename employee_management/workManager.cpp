#include "./header/workerManager.h"

//#define FILENAME "C:\Users\coolsyn\CLionProjects\CppExercise\employee_management\empFile.txt"
WorkerManager::WorkerManager() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        cout << "file does not exist\n";
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "file is empty\n";
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    int num = this->get_EmpNum();
    //cout << "number of workers: " << num << endl;
    this->m_EmpNum = num;
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    this->init_emp();
    /*
    for (int i = 0; i < this->m_EmpNum; i++) {
        cout << "worker no.: \n" << this->m_EmpArray[i]->m_Id
             << "name: " << this->m_EmpArray[i]->m_Name
             << "Department id: " << this->m_EmpArray[i]->m_DeptId << endl;
    }
     */
}

void WorkerManager::Show_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "file does not exist or is empty\n";
    } else {
        for (int i = 0; i < this->m_EmpNum; i++) {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::init_emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker *worker = NULL;
        if (dId == 1) {
            worker = new Employee(id, name, dId);
        } else if (dId == 2) {
            worker = new Manager(id, name, dId);
        } else {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {

        num++;
    }
    return num;
}

int WorkerManager::IsExist(int id) {
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::Del_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "file does not exist\n";
    } else {
        cout << "enter id you want to delete\n";
        int id;
        cin >> id;
        int index = this->IsExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_EmpNum - 1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->save();
            cout << "delete successfully\n";
        } else {
            cout << "delete unsuccessfully: can not find id\n";
        }
        system("pause");
        system("cls");
    }
}

void WorkerManager::Mod_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "file does not exist\n";
    } else {
        cout << "enter id you want to modify\n";
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if (ret != -1) {
            delete this->m_EmpArray[ret];
            int new_id = 0;
            string new_name;
            int dSelect = 0;
            cout << "founded : please enter new id:\n";
            cin >> new_id;
            cout << "enter new name:\n";
            cin >> new_name;
            cout << "enter new department:\n1---employee\t2---manager\t3---boss\n";
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(new_id, new_name, dSelect);
                    break;
                case 2:
                    worker = new Manager(new_id, new_name, dSelect);
                    break;
                case 3:
                    worker = new Boss(new_id, new_name, dSelect);
                    break;
                default:
                    break;
            }
            this->m_EmpArray[ret] = worker;
            this->save();
            cout << "modify successfully\n";
        } else {
            cout << "modify unsuccessfully: can not find id\n";
        }
        system("pause");
        system("cls");
    }
}

void WorkerManager::Find_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "file does not exist\n";
    } else {
        cout << "enter find method\n1---by No:\t2---by name\n";
        int select;
        cin >> select;
        if (select == 1) {
            int id;
            cout << "enter id\n";
            cin >> id;
            int ret = IsExist(id);
            if (ret != -1) {
                cout << "Find successfully!\n" << endl;
                this->m_EmpArray[ret]->showInfo();
            } else {
                cout << "id can not be founded\n";
            }
        } else if (select == 2) {
            string name;
            cout << "enter name\n";
            cin >> name;
            bool flag = false;
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i]->m_Name == name) {
                    cout << "find successfully:\n";
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
                if (flag == false) {
                    cout << "can not found\n";
                }
            }
        } else {
            cout << "error\n";
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    cout << "file is saved\n";
    ofs.close();
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
    cout << "EXITING\n";
    system("pause");
    exit(0);
}

void WorkerManager::Sort_Emp() {
    if(this->m_FileIsEmpty)
    {
        cout<<"file does not exist or empty\n";
        system("pause");
        system("cls");
    }
    else
    {
        cout<<"rank method:\n1---up\t2---down\n";
        int select=0;
        cin>>select;
        for(int i=0;i<this->m_EmpNum;i++)
        {
            int minORmax=i;
            for(int j=i+1;j<this->m_EmpNum;j++)
            if(select==1)
            {
                if(this->m_EmpArray[minORmax]->m_Id>this->m_EmpArray[j]->m_Id)
                {
                    minORmax=j;
                }
            }
            else
            {
                if(this->m_EmpArray[minORmax]->m_Id<this->m_EmpArray[j]->m_Id)
                {
                    minORmax=j;
                }
            }
            if(i!=minORmax)
            {
                Worker*temp=this->m_EmpArray[i];
                this->m_EmpArray[i]=this->m_EmpArray[minORmax];
                this->m_EmpArray[minORmax]=temp;
            }
        }
        cout<<"rank successfully\n";
        this->save();
        this->Show_Emp();
    }
}

void WorkerManager::Add_Emp() {
    cout << "enter number of employees\n";
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0) {
        int newSize = this->m_EmpNum + addNum;
        Worker **newSpace = new Worker *[newSize];
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for (int i = 0; i < addNum; i++) {
            int id;
            bool flag=false;
            int ret=0;
            string name;
            int dSelect = 0;

            while(ret!=-1) {
                if(flag==false){
                    cout << "enter NO." << i + 1 << " id" << endl;
                }
                else
                {
                    cout<<"id has already existed! enter a new id\n";
                }
                cin >> id;
                ret=this->IsExist(id);
                if(ret!=-1)
                {
                    flag=true;
                }
            }


            cout << "enter NO." << i + 1 << " name" << endl;
            cin >> name;
            cout << "enter Department\n1.employee\n2.manager\n3.boss" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            newSpace[this->m_EmpNum + i] = worker;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->m_FileIsEmpty = false;
        cout << "add " << addNum << " person successfully\n";
        this->save();
    }

    else {
        cout << "wrong number\n";
    }

    system("pause");
    system("cls");

}

void WorkerManager::Clean_File() {
    cout<<"clean?\n";
    cout<<"1---yes\t2---no\n";
    int select=0;
    cin>>select;
    if(select==1)
    {
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();
        if(this->m_EmpArray!=NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i]=NULL;
            }
            delete[] this->m_EmpArray;
            this->m_EmpArray=NULL;
            this->m_EmpNum=0;
            this->m_FileIsEmpty=true;
        }
        cout<<"clean successfully\n";
    }

    system("pause");
    system("cls");

}
