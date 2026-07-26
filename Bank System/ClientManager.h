#pragma once
#include "DataEntry.h"
#include"FileManager.h"
class ClientManager
{
public:

	static void printClientMenu() {
		cout << "\n=========================================\n";
		Console::lightblue();
		cout << "             CLIENT MENU\n";
		Console::yellow();
		cout << "=========================================\n\n";

		Console::lightblue();
		cout << "Banking\n";
		Console::yellow();
		cout << "-----------------------\n";

		cout << "[1] Transactions\n\n";

		Console::lightblue();
		cout << "Account\n";
		Console::yellow();
		cout << "-----------------------\n";

		cout << "[2] My Account\n\n";

		Console::lightblue();
		cout << "Session\n";
		Console::yellow();
		cout << "-----------------------\n";
		cout << "[3] Logout\n\n";
	}

	static void printTransactionMenu() {
		cout << "\n=========================================\n";
		Console::lightblue();
		cout << "             TRANSACTIONS\n";
		Console::yellow();
		cout << "=========================================\n\n";

		Console::lightblue();
		cout << "Banking Operations\n";
		Console::yellow();
		cout << "-----------------------\n";

		cout << "[1] Deposit Money\n\n";
		cout << "[2] Withdraw Money\n\n";
		cout << "[3] Transfer Money\n\n";

		Console::lightblue();
		cout << "Return\n";
		Console::yellow();
		cout << "-----------------------\n"

		     << "[0] Back\n\n";
	}

	static void printAccountMenu() {

		cout << "\n=========================================\n";
		Console::lightblue();
		cout << "             MY ACCOUNT";
		Console::yellow();
		cout << "\n=========================================\n\n";

		Console::lightblue();
		cout << "Profile\n";
		Console::yellow();
		cout << "-------------------------\n";

		cout << "[1] View Profile\n\n"
			 << "[2] Update My Information\n\n";

		Console::lightblue();
		cout << "Return\n";
		Console::yellow();
		cout << "-------------------------\n"		
			<< "[0] Back\n\n";
	}





	static Client* login(int id, string password)
	{
		Client* c = Employee::searchClient(id);

		if (c != nullptr && c->getPassword() == password)
		{
			return c;
		}

		return nullptr;
	}




	static bool transactionMenu(Client* client) {

		printTransactionMenu();

		int choice, amount;
		
		cout << "Enter your choice: ";

		Console::white();
		cin >> choice;
		Console::yellow();

		switch (choice) {
		case 1:
		{
			cout << "\nEnter the amount: ";

			Console::white();
			cin >> amount;
			cin.ignore();
			Console::yellow();

			if (client->deposit(amount)) {

				Console::success("Deposit completed successfully.");

				FileManager::updateClient();

			}
			break;
		}

		case 2:
		{
			cout << "\nEnter the amount: ";

			Console::white();
			cin >> amount;
			cin.ignore();
			Console::yellow();

			if (client->withdraw(amount)) {

				Console::success("Money withdrawn successfully. ");

				FileManager::updateClient();

			}
			break;

		}
		case 3:
		{
			int  accountId;

			cout << "\nEnter the account ID you want to transfer to: ";

			Console::white();
			cin >> accountId;
			cin.ignore();
			Console::yellow();

			Client* target = Employee::searchClient(accountId);

			if (target != nullptr)
			{

				cout << "\nEnter the amount: ";
				Console::white();
				cin >> amount;
				cin.ignore();
				Console::yellow();


				if (client->transferTo(amount, *target)) {

					Console::success("Transfer completed successfully. \n");

					FileManager::updateClient();
				}
			}
			else
			{
				Console::error("Account not found. \n");			

			}
			break;
		}

		return true;
		}
	}

	static bool accountOptions(Client* client) {

		   printAccountMenu();

		   int choice;
		   cout << "Enter your choice: ";

		   Console::white();
		   cin >> choice;
		   cin.ignore();
		   Console::yellow();

		   switch (choice) {

		   case 0: return false;

		   case 1:

			   client->display("MY PROFILE");

			   break;

		   case 2:
			   if (DataEntry::editInfo(client)) {

				   FileManager::updateClient();

			   }
			   break;

		   default:

			   Console::error("Invalid Choice. \n");

		   }

		   return true;

	}

	static bool clientOptions(Client* client) {

		if (client == nullptr) {
			return false;
		}

		printClientMenu();

		int choice ;
		

		cout << "Enter your choice: ";

		Console::white();
		cin >> choice;
		cin.ignore();
		Console::yellow();

		switch (choice) {
		case 1:
			while (transactionMenu(client));
			break;

		case 2:
			while (accountOptions(client));
			break;

		case 3: return false;

		}

		return true;
	}


};

