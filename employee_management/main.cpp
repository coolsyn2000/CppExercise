#include <iostream>
#include <string>
#include "./header/worker.h"
#include "./header/workerManager.h"
#include "./header/employee.h"
#include "./header/manager.h"
#include "./header/boss.h"
using namespace std;

int main() {
    WorkerManager wm;
    int choice;
    while(true) {
        wm.Show_Menu();
        cout << "enter the choice:\n";
        cin >> choice;
        switch (choice) {
            case 0:
                wm.Exit_Menu();
                break;
            case 1:
                wm.Add_Emp();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                system("cls");
                break;
        }
    }

    system("pause");
    return 0;
}
