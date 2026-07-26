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

            cout << "[1] Sign In\n\n";

            Console::lightblue();
            cout << "Exit\n";
            Console::yellow();
            cout << "---------------------------\n"
                << "[2] Exit\n\n";

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
                return -1;
                break;

            default:
                Console::error("Invalid Choice.");

            }
        }


        static bool start()
        {
            while (true) {

                int c = getMainMenuChoice();

                if (c == -1) {

                    return false;

                }

                else if (c == 1) {

                    return true;
                }

                
            }
        }


};

