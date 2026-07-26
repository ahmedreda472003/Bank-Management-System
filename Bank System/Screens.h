#pragma once
#include "AdminManager.h"
#include "WelcomeScreen.h"
class Screens
{
public:
   
	static void welcome() {
        Console::lightblue();
		
        cout << R"( 
         





            @@      @@    @@@@@@@@@    @@@        @@@@@@@     @@@@@@      @@@@    @@@@     @@@@@@@
            @@      @@    @@           @@@       @@          @@    @@     @@  @  @  @@     @@  
            @@  @@  @@    @@@@@@       @@@       @@          @@    @@     @@   @@   @@     @@@@@@
            @@ @@@@ @@    @@           @@@       @@          @@    @@     @@        @@     @@ 
            @@@@  @@@@    @@@@@@@@@    @@@@@@@    @@@@@@@     @@@@@@      @@        @@     @@@@@@@
)";
Console::white();
        cout << R"( 


                                         @@@@@@@@@@     @@@@@@
                                             @@        @@    @@
                                             @@        @@    @@
                                             @@        @@    @@
                                             @@         @@@@@@
)";
        Console::lightblue();
        cout << R"( 

                               @@@@@@   @@     @@    @@@@@      @@@@@@@    @@@@@@@
                              @@        @@@   @@@   @@   @@     @@    @@     @@
                              @@@@@@    @@ @ @ @@   @@@@@@@     @@@@@@@      @@
                                   @@   @@  @  @@   @@   @@     @@   @@      @@
                              @@@@@@    @@     @@   @@   @@     @@    @@     @@
)";

Console::white();
		
        cout << R"( 

                                @@@@@@       @@@@@       @@   @@      @@   @@
                                @@   @@     @@   @@      @@@  @@      @@  @@ 
                                @@@@@@      @@@@@@@      @@ @ @@      @@ @@  
                                @@   @@     @@   @@      @@  @@@      @@  @@ 
                                @@@@@@      @@   @@      @@   @@      @@   @@

)";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        Console::yellow();
	}




    static void loginOptions() {
        cout << "\n=========================================\n";
        Console::lightblue();
        cout << "              SELECT YOUR ROLE\n";
        Console::yellow();
        cout << "=========================================\n\n";

        Console::lightblue();
        cout << "Available Roles\n";
        Console::yellow();
        cout << "------------------------\n" 
            
            << "[1] Administrator\n\n"
            << "[2] Employee\n\n"
            << "[3] Client\n\n";

        Console::lightblue();
        cout << "Exit\n";
        Console::yellow();
        cout<< "------------------------\n"
            << "[4] Exit\n\n";

    }

	static int loginAs() {

        loginOptions();

        int choice;
        cout << "Your choice: ";

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
            return 3;
            break;

        case 4: 
            return -1;
            break;

        default:

            Console::error("Invalid Choice.");

        }

	}


    static void welcomeUser(const string& name)
    {
        cout << "\n-----------------------------------------\n";
        Console::green();
        cout << "       Welcome back, " << name << "!";
        Console::yellow();
        cout << "\n-----------------------------------------\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }


	static void loginScreen(int c) {

        if (c == -1) {
            return;
        }
        int id;
        cout << "\nEnter id: ";

        Console::white();
        cin >> id;
        cin.ignore();
        Console::yellow();

        cout << "\nEnter password: ";

        Console::white();
        string pass = Validation::inputPassword();
        Console::yellow();

        if (c == 1) {
            Admin *a = AdminManager::login(id, pass);

            if (a != nullptr) {

                welcomeUser(a->getName());

                while (AdminManager::adminOptions(a));

                logout();

            }
            else {
                invalid(1);
            }
        }
        else if (c == 2) {

            Employee*e = EmployeeManager::login(id, pass);

            if (e != nullptr) {

                welcomeUser(e->getName());
               
                while (EmployeeManager::employeeOptions(e));

                logout();

            }
            else {
                invalid(2);
            }
        }
        else if (c == 3) {

            Client *c = ClientManager::login(id, pass);

            if (c != nullptr) {

                welcomeUser(c->getName());

                while (ClientManager::clientOptions(c));

                logout();

            }
            else {
                invalid(3);
            }
        }
	}

	static void invalid(int c){

        Console::error("Wrong id or password!");
     
         loginScreen(c);

	}


	static void logout() {
        loginScreen(loginAs());
	}



    static void runApp() {

        FileManager::fetchAllData();

        Screens::welcome();

        if (WelcomeScreen::start()) {
          loginScreen(loginAs());
        }
       

	}



};

