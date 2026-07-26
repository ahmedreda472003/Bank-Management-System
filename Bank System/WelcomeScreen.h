#pragma once
#include <windows.h>
#include "AdminManager.h"
class WelcomeScreen
{
    public:

        static void showMainMenu() {
            cout << "\n=========================================\n";
            Console::lightblue();
            cout << "         BANK MANAGEMENT SYSTEM\n";
            Console::yellow();
            cout << "=========================================\n\n";

            Console::lightblue();
            cout << "Main Menu\n";
            Console::yellow();
            cout << "---------------------------\n";

            cout<< "[1] Sign In\n\n"
                << "[2] Create New Account\n\n";

            Console::lightblue();
            cout << "Exit\n";
            Console::yellow();
            cout << "---------------------------\n"
                << "[3] Exit\n\n";

        }

        static int getMainMenuChoice() {

            showMainMenu();

            int choice;
            cout << "Select an option: ";

            Console::white();
            cin >> choice;
            cin.ignore();
            Console::yellow();


            switch (choice) {
            case 1:
                return 1;
                break;

            case 2:
                return 2;
                break;

            case 3:
                return -1;
                break;

            default:
                Console::error("Invalid Choice.");

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
                handleAccountCreation(selectAccountType() );
            }



        }


        static void showAccountTypeMenu() {
            cout << "\n=========================================\n";
            Console::lightblue();
            cout << "           CREATE NEW ACCOUNT\n";
            Console::yellow();
            cout << "=========================================\n\n"

                << "[1] Client Account\n\n";
            Console::lightblue();
           cout << "----------- Developer Options -----------\n\n";
           Console::yellow();
           cout << "[2] Employee Account\n\n"
                << "[3] Administrator Account\n\n";


        }

        static int selectAccountType() {

            showAccountTypeMenu();

            int choice;
            cout << "Select account type: ";

            Console::white();
            cin >> choice;
            cin.ignore();
            Console::yellow();
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

                Console::error("Invalid Choice.");

            }
        }


        static void handleAccountCreation(int c ) {

            if (c == 1) {

                int id = FilesHelper::getLast(LAST_ID_FILE_CLIENT) + 1;

                string name = DataEntry::enterName();

                string password = DataEntry::enterPassword();

                double balance = DataEntry::enterBalance();

                Client c(id, name, password, balance);

                Client::addClientToVector(c);

                FilesHelper::saveLast(LAST_ID_FILE_CLIENT, id);

                FileManager::updateClient();

                cout << "\n-------------------------------------------\n";
                Console::green();
                cout << "  -> Client account created successfully!";
                Console::yellow();
                cout << "\n-------------------------------------------\n\n";

                c.display("NEW CLIENT ACCOUNT");
            }

            else if (c == 2) {

                int id = FilesHelper::getLast(LAST_ID_FILE_EMPLOYEE) + 1;

                string name = DataEntry::enterName();

                string password = DataEntry::enterPassword();

                double salary = DataEntry::enterSalary();

                Employee e(id, name, password, salary);

                Employee::addEmployeeToVector(e);

                FilesHelper::saveLast(LAST_ID_FILE_EMPLOYEE, id);

                FileManager::updateEmployee();

                cout << "\n-------------------------------------------\n";
                Console::green();
                cout << "  -> Employee account created successfully!";
                Console::yellow();
                cout << "\n-------------------------------------------\n\n";

                e.display("NEW EMPLOYEE ACCOUNT");
            }


            else if (c == 3) {

                int id = FilesHelper::getLast(LAST_ID_FILE_ADMIN) + 1;

                string name = DataEntry::enterName();

                string password = DataEntry::enterPassword();

                double salary = DataEntry::enterSalary();

                Admin a(id, name, password, salary);

                Admin::addAdminToVector(a);

                FilesHelper::saveLast(LAST_ID_FILE_ADMIN ,id) ;

                FileManager::updateAdmin();

                cout << "\n-------------------------------------------\n";
                Console::green();
                cout << "  ->Administrator account created successfully!";
                Console::yellow();
                cout << "\n-------------------------------------------\n\n";

                a.display("NEW ADMIN ACCOUNT");
            }



        }

        static bool start()
        {
            while (true) {

                int c = getMainMenuChoice();

                processMainMenuChoice(c);

                if (c == -1) {

                    return false;

                }

                else if (c == 1) {

                    return true;
                }

                
            }
        }


};

