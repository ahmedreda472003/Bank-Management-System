#pragma once
#include "ClientManager.h"
#include "Console.h"
class DashboardManager
{
public:

	static void dashBoard() {

		double totalBalance = 0;
		double HighestBalance = INT_MIN;
		double LowestBalance = INT_MAX;


		for (Client& client : Client::getVectorClient()) {


			totalBalance += client.getBalance();

			if (HighestBalance < client.getBalance()) {

				HighestBalance = client.getBalance();

			}
			if (LowestBalance > client.getBalance()) {

				LowestBalance = client.getBalance();

			}


		}

		if (HighestBalance == INT_MIN) {
			HighestBalance = 0;
		}

		if (LowestBalance == INT_MAX) {
			LowestBalance = 0;
		}


		cout << "\n==============================\n";
		Console::lightblue();
		cout << "        DASHBOARD";
		Console::yellow();
		cout << "\n==============================\n";

		Console::lightblue();
		cout << "\nAccount Statistics \n";
		Console::yellow();

		cout << "------------------------------\n";

		cout << "\nClients         : ";
		Console::white();
		cout << Client::getVectorClient().size();


		Console::yellow();
		cout << "\nEmployees       : ";
		Console::white();
		cout << Employee::getVectorEmployee().size();


		Console::yellow();
		cout << "\nAdministrators  : ";
		Console::white();
		cout << Admin::getVectorAdmin().size();




		Console::lightblue();
		cout << "\n\nFinancial Statistics \n";
		Console::yellow();
		cout << "------------------------------\n";


		cout << "\nTotal Balance   : ";
		Console::white();
		cout << totalBalance;

		Console::yellow();
		cout << " EGP";


		cout << "\nHighest Balance : ";
		Console::white();
		cout << HighestBalance;


		Console::yellow();
		cout << " EGP";

		cout << "\nLowest Balance  : ";
		Console::white();
		cout << LowestBalance;

		Console::yellow();
		cout << " EGP";



		cout << "\n\n==============================\n\n";

		std::this_thread::sleep_for(std::chrono::seconds(2));

	}

};

