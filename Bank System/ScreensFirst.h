#pragma once
#include <windows.h>
#include "AdminManager.h"
class ScreensFirst
{
public:

    static void showMainMenu() {
        cout << "\n=========================================\n"
            << "         BANK MANAGEMENT SYSTEM\n"
            << "=========================================\n\n"

            << "[1] Sign In\n"
            << "[2] Create New Account\n"
            << "[3] Exit\n";

    }

    static int getMainMenuChoice() {
        showMainMenu();
        int choice;
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        default:
            cout << "Invalid Choice.\n";
            return -1;
        }
    }

    static void processMainMenuChoice(int c) {
        if (c == -1) {
            return;
        }
        if (c == 1) {
            return;
        }

        else if (c == 2) {
            handleAccountCreation(selectAccountType());
        }



    }


    static void showAccountTypeMenu() {
        cout << "\n=========================================\n"
           << "           CREATE NEW ACCOUNT\n"
           << "=========================================\n\n"

           << "[1] Client Account\n"
           << "[2] Employee Account\n"
           << "[3] Administrator Account\n";

        
    }

    static int selectAccountType() {
        showAccountTypeMenu();
        int choice;
        cout << "Select account type: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            cout << "Invalid Choice.\n";
            break;
        }
    }


    static void handleAccountCreation(int c) {
       
        if (c == 1) {
            int id = FilesHelper::getLast(LAST_ID_FILE_CLIENT) + 1;
            string name = DataEntry::enterName();
            string password = DataEntry::enterPassword();
            double balance = DataEntry::enterBalance();
            Client c(id, name, password, balance);
                Client::addClientToVector(c);
                FileManager::UpdateClient();

                cout << "\n===========================================\n";
                Console::green();
                cout << "    -> Client account created successfully!";
                Console::yellow();
                cout << "\n===========================================\n\n";

                c.display();
        }

        else if (c == 2) {
            int id = FilesHelper::getLast(LAST_ID_FILE_EMPLOYEE) + 1;
            string name = DataEntry::enterName();
            string password = DataEntry::enterPassword();
            double salary = DataEntry::enterSalary();
            Employee e(id, name, password, salary);
            Employee::addEmployeeToVector(e);
            FileManager::UpdateEmployee();

            cout << "\n===========================================\n";
            Console::green();
            cout << "     -> Employee account created successfully!";
            Console::yellow();
            cout << "\n===========================================\n\n";

            e.display();
        }

        else if (c == 3) {
            int id = FilesHelper::getLast(LAST_ID_FILE_ADMIN) + 1;
            string name = DataEntry::enterName();
            string password = DataEntry::enterPassword();
            double salary = DataEntry::enterSalary();
            Admin a(id, name, password, salary);
            Admin::addAdminToVector(a);
            FileManager::UpdteAdmin();

            cout << "\n===============================================\n";
            Console::green();
            cout << "  ->Administrator account created successfully!";
            Console::yellow();
            cout << "\n===============================================\n\n";

            a.display();
        }



    }

    static void start()
    {
        processMainMenuChoice(getMainMenuChoice());
    }

};

