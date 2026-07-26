#pragma once
#include "ClientManager.h"
#include "Console.h"
class EmployeeManager
{
public:


	static void printEmployeeMenu() {
		cout << "\n=========================================\n";
		Console::lightblue();
		cout << "           EMPLOYEE CONTROL PANEL\n";
		Console::yellow();
		cout << "=========================================\n\n";
		
		Console::lightblue();
		cout << "Management\n";
		Console::yellow();
		cout << "------------------------\n";
		cout << "[1] Client Management\n\n";

		Console::lightblue();
		cout << "Account\n";
		Console::yellow();
		cout << "------------------------\n";

		cout << "[2] My Account\n\n";

		Console::lightblue();
		cout << "Session\n";
		Console::yellow();

		cout << "[3] Logout\n\n";
			
				
	}


	static void printClientManagementMenu() {

		cout << "\n=========================================\n";
		Console::lightblue();
		cout << "            CLIENT MANAGEMENT";
		Console::yellow();
		cout << "\n=========================================\n\n";

		Console::lightblue();
		cout << "Client Records\n";
		Console::yellow();

		cout << "---------------------------------\n";

		cout<< "[1] Add New Client\n\n"
			<< "[2] Update Client Information\n\n"
			<< "[3] Search for Client\n\n"
			<< "[4] View All Clients\n\n"
			<< "[5] Delete Client\n\n";

		Console::lightblue();
		cout << "Bank Transactions\n";
		Console::yellow();

		cout << "---------------------------------\n"

			<< "[6] Deposit\n\n"
			<< "[7] Withdraw\n\n"
			<< "[8] Transfer\n\n";

		Console::lightblue();
		cout << "Return\n";
		Console::yellow();
		cout << "----------------------------------\n"
			<< "[0] Back\n\n";

	}





	static void addNewClient(Employee* employee) {

	    int id  = FilesHelper::getLast(LAST_ID_FILE_CLIENT)+ 1;

		string name  = DataEntry::enterName();

		string password = DataEntry::enterPassword();

		double balance  = DataEntry::enterBalance();

		Client c(id, name, password, balance);

		employee->addClient(c);

		FilesHelper::saveLast(LAST_ID_FILE_CLIENT , id);

		FileManager::updateClient();

		cout << "\n-------------------------------------------\n";
		 Console::green();
		cout << "    -> Client account created successfully!";
		 Console::yellow();
		cout << "\n-------------------------------------------\n\n";

		c.display("NEW CLIENT ACCOUNT");

	}


	static void viewAllClients(Employee* employee) {
		employee->listAllClient();
	}


	static void searchClient(Employee* employee) {

		int id = DataEntry::enterId();

		Client* client = employee->searchClient(id);

		if (client != nullptr) {

			client->display();

		}
		else {

			Console::red();
			cout << "->Client Not Found.\n";
			Console::yellow();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}


	
	static bool performClientTransaction(Employee* employee, int choice) {

		int id, amount;

		id = DataEntry::enterId();

		Client* c = employee->searchClient(id);

		if (c == nullptr) {
			Console::error("Client not found \n");
			return false;
		}

		cout << "\nEnter the amount: ";
		Console::white();
		cin >> amount;
		cin.ignore();
		Console::yellow();

		bool success = false;

		if (choice == 6) {
			success = c->deposit(amount);
		}
		else if (choice == 7) {
			success = c->withdraw(amount);
		}
		else if (choice == 8) {

			int targetId;
			cout << "\nEnter the account ID you want to transfer to: ";

			Console::white();
			cin >> targetId;
			cin.ignore();
			Console::yellow();

			Client* target = employee->searchClient(targetId);

			if (target == nullptr) {
				Console::error("Account not found \n");
				return false;
			}

			success = c->transferTo(amount, *target);
		}

		if (success) {

			if (choice == 6) {

				Console::success("Deposit Successfully");

			}
			else if (choice == 7) {

				Console::success("Withdraw Successfully");

			}
				
			else{

				Console::success("Transfer Successfully");

				}

			FileManager::updateClient();
			return true;
		}

		return false;
	}


	static Employee* login(int id, string password) {

		Employee* e = Admin::searchEmployee(id);

		if (e != nullptr && e->getPassword() == password)
		{
			return e;
		}

		return nullptr;

	}





	static bool clientManagementOptions(Employee* employee) {


		printClientManagementMenu();

		int choice;
		cout << "Enter your choice: ";

		Console::white();
		cin >> choice;
		cin.ignore();
		Console::yellow();

		switch (choice) {

		case 0: return false;

		case 1:
			addNewClient(employee);
			break;

		case 2:
		{
			int id = DataEntry::enterId();


			Client* clientToEdit = employee->searchClient(id);

			if (clientToEdit == nullptr) {
				Console::error("Client not found \n");
				break;
			}

			if (DataEntry::editInfo(clientToEdit)) {

				FileManager::updateClient();

			}

			break;
		}

		case 3:
			searchClient(employee);
			break;

		case 4:
			viewAllClients(employee);
			break;

		case 5:
		{
			int idRemove = DataEntry::enterId();

			if (employee->removeClient(idRemove)) {

				Console::success("Client Removed Successfully\n");

				FileManager::updateClient();
				break;

			}
			else {
				Console::error("Client not found \n");
			}
			break;
		}

		case 6:
		case 7:
		case 8:

			performClientTransaction(employee, choice);

			break;

		default:

			Console::error("Invalid Choice.");

		}
		return true;
	}

	
	static bool accountOptions(Employee* employee) {

		ClientManager::printAccountMenu();

		int choice;
		cout << "Enter your choice: ";

		Console::white();
		cin >> choice;
		cin.ignore();
		Console::yellow();

		switch (choice) {

		case 0: return false;

		case 1:

			employee->display("MY PROFILE");

			break;

		case 2:
			if (DataEntry::editInfo(employee)) {

				FileManager::updateEmployee();

			}
			break;

		default:

			Console::error("Invalid Choice.");

		}

		return true;

	}


	static bool employeeOptions(Employee* employee) {

		if (employee == nullptr) {
			return false;
		}

		printEmployeeMenu();

		int choice;
		cout << "Enter your choice: ";

		Console::white();
		cin >> choice;
		cin.ignore();
		Console::yellow();

		switch (choice) {
		case 1:
			while (clientManagementOptions(employee));
			break;

		case 2:
			while (accountOptions(employee));
			break;


		case 3: return false;

		default:

			Console::error("Invalid Choice.");

		}
		return true;
	}


};

