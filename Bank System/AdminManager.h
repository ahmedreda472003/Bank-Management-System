#pragma once
#include "EmployeeManager.h"
#include "DashboardManager.h"
class AdminManager
{
public:

	static void printAdminMenu() {
		cout << "\n=========================================\n";
		Console::lightblue();
		cout << "           ADMIN CONTROL PANEL\n";
		Console::yellow();
		cout << "=========================================\n\n";


		cout << "[0] Dashboard \n\n";

		Console::lightblue();
		cout << "Management\n";
		Console::yellow();
		cout << "--------------\n";

		cout << "[1] Clients\n\n";

		cout << "[2] Employees\n\n";

		cout << "[3] Administrators\n\n";

		Console::lightblue();
		cout << "Account\n";
		Console::yellow();
		cout << "--------------\n";
		
		cout << "[4] My Account\n\n";

		Console::lightblue();
		cout << "Session\n";
		Console::yellow();
		cout << "--------------\n";
		
		cout << "[5] Logout\n\n";



	}


	static void printAdminEmployeeMenu() {

		cout << "\n=========================================\n";
		Console::lightblue();
		cout << "            EMPLOYEE MANAGEMENT";
		Console::yellow();
		cout << "\n=========================================\n\n";

		Console::lightblue();
		cout << "Employee Records\n";
		Console::yellow();
		cout << "----------------------------------\n";

		cout<< "[1] Add New Employee\n\n"
			<< "[2] Search for Employee\n\n"
			<< "[3] Update Employee Information\n\n"
			<< "[4] View All Employees\n\n"
			<< "[5] Edit salary Employees\n\n"
			<< "[6] Delete Employee\n\n";

		Console::lightblue();
		cout << "Return\n";
		Console::yellow();
	   cout << "----------------------------------\n"
		    << "[0] Back\n\n";

	}


	static void printAdminAdminMenu() {

		cout << "\n=========================================\n";
		Console::lightblue();
		cout << "            ADMIN MANAGEMENT";
		Console::yellow();
		cout << "\n=========================================\n\n";

		Console::lightblue();
		cout << " Admin Records\n";
		Console::yellow();
		cout << "-------------------------------\n";

		cout<< "[1] Add New Admin\n\n"
			<< "[2] Search for Admin\n\n"
			<< "[3] View All Admins\n\n"
			<< "[4] Update Admin Information\n\n"
			<< "[5] Edit salary Admins\n\n"
			<< "[6] Delete Admin\n\n";

		Console::lightblue();
		cout << " Return\n";
		Console::yellow();
		cout<< "-------------------------------\n"
			<< "[0] Back\n\n";

	}




	static void editSalaryEmployee(Admin* admin) {

		int id = DataEntry::enterId();


		Employee* employee = admin->searchEmployee(id);

		if (employee == nullptr) {

			Console::error("Employee Not Found.");

		}
		else {
			double amount = DataEntry::enterSalary();

			employee->setSalary(amount);

		}

	}

	static void editSalaryAdmin(Admin* admin) {

		int id = DataEntry::enterId();


		Admin* a = admin->searchAdmin(id);

		if (a == nullptr) {

			Console::error("Admin Not Found.");

		}
		else {

			double amount = DataEntry::enterSalary();
			
			a->setSalary(amount);
				

		}

	}




	static void addNewEmployee(Admin* admin) {

		int id = FilesHelper::getLast(LAST_ID_FILE_EMPLOYEE) + 1;

		string name = DataEntry::enterName();

		string password = DataEntry::enterPassword();

		double salary = DataEntry::enterSalary();

		Employee e(id, name, password, salary);

		admin->addEmployee(e);

		FilesHelper::saveLast(LAST_ID_FILE_EMPLOYEE, id);

		FileManager::updateEmployee();

		cout << "\n-------------------------------------------\n";
		Console::green();
		cout << "     -> Employee account created successfully!";
		Console::yellow();
		cout << "\n-------------------------------------------\n\n";

		e.display("NEW EMPLOYEE ACCOUNT");

	}
	

	static void addNewAdmin(Admin* admin) {

		int id = FilesHelper::getLast(LAST_ID_FILE_ADMIN) + 1;

		string name = DataEntry::enterName();

		string password = DataEntry::enterPassword();

		double salary = DataEntry::enterSalary();

		Admin a(id, name, password, salary);

		admin->addAdmin(a);

		FilesHelper::saveLast(LAST_ID_FILE_ADMIN, id);

		FileManager::updateAdmin();

		cout << "\n-------------------------------------------\n";
		Console::green();
		cout << "  ->Administrator account created successfully!";
		Console::yellow();
		cout << "\n-------------------------------------------\n\n";
		
		a.display("NEW ADMIN ACCOUNT");
	}


	static void searchEmployee(Admin* admin) {

		int id = DataEntry::enterId();

		Employee* employee = admin->searchEmployee(id);


		if (employee != nullptr) {

			employee->display();

		}
		else {
			Console::error("Employee Not Found.");
		}
	}


	static void searchAdmin(Admin* admin) {

		int id = DataEntry::enterId();

		Admin* a = admin->searchAdmin(id);

		if (a != nullptr) {

			a->display();

		}
		else {
			Console::error("Admin Not Found.");
		}
	}


	static void viewAllEmployee(Admin* admin) {
		admin->listAllEmployee();
	}


	static void viewAllAdmin(Admin* admin) {
		admin->listAllAdmin();
	}

	

    static Admin* login(int id, string password) {
        Admin* a = Admin::searchAdmin(id);

        if (a != nullptr && a->getPassword() == password)
        {
            return a;
        }
        return nullptr;

    }



	static bool clientManagementOptions(Admin* admin) {

		EmployeeManager::printClientManagementMenu();

		int choice;
		cout << "Enter your choice: ";

		Console::white();
		cin >> choice;
		cin.ignore();
		Console::yellow();

		switch (choice) {


		case 0: return false;

		case 1:
			EmployeeManager::addNewClient(admin);
			break;

		case 2:
		{
			int idC = DataEntry::enterId();

			Client* client = admin->searchClient(idC);

			if (client == nullptr) {
				Console::error("Client Not Found.");
				break;
			}

			if (DataEntry::editInfo(client)) {

				FileManager::updateClient();

			}
			break;
		}

		case 3:
			EmployeeManager::searchClient(admin);
			break;

		case 4:
			EmployeeManager::viewAllClients(admin);
			break;

		case 5:
		{
			int idR = DataEntry::enterId();

			if (admin->removeClient(idR)) {

				Console::success("Client Removed Successfully\n");

				FileManager::updateClient();
				break;
			}

			else {
				Console::error("Client Not Found.");
			}
			break;
		}
		case 6:
		case 7:
		case 8:
			EmployeeManager::performClientTransaction(admin, choice);

			break;

		default:
			Console::error("Invalid Choice.");
		}

		return true;

	}


	static bool employeeManagementOptions(Admin* admin) {

		printAdminEmployeeMenu();

		int choice;
		cout << "Enter your choice: ";

		Console::white();
		cin >> choice;
		cin.ignore();
		Console::yellow();

	  switch (choice) {

	  case 0: return false;

		case 1:
			addNewEmployee(admin);
			break;

		case 2:
		{
			searchEmployee(admin);
			break;

		case 3:
			int idE = DataEntry::enterId();

			Employee* employeeToEdit = admin->searchEmployee(idE);

			if (employeeToEdit == nullptr) {
				Console::error("Employee not found.");
				break;
			}

			if (DataEntry::editInfo(employeeToEdit)) {

				FileManager::updateEmployee();

			}

			break;
		}

		case 4:

			viewAllEmployee(admin);

			break;

		case 5:
              
			editSalaryEmployee(admin);
			FileManager::updateEmployee();

			break;

		case 6:
		{
			int idRemoveAdmin = DataEntry::enterId();


			if (admin->removeEmployee(idRemoveAdmin)) {

				Console::success("Employee Removed Successfully\n");

				FileManager::updateEmployee();
				break;
			}
			else {
				Console::error("Employee Not Found.\n");
			}
			break;
		}
		default:

			Console::error("Invalid Choice.");

	  }

	  return true;

	}

	static bool adminManagementOptions(Admin* admin) {

		printAdminAdminMenu();

		int choice;
		cout << "Enter your choice: ";

		Console::white();
		cin >> choice;
		cin.ignore();
		Console::yellow();

	  switch (choice) {

		case 0: return false;

		case 1:
			addNewAdmin(admin);
			break;

		case 2:
			searchAdmin(admin);
			break;

		case 3:
			viewAllAdmin(admin);
			break;

		case 4:
		{
			int idA = DataEntry::enterId();

			Admin* adminToEdit = admin->searchAdmin(idA);

			if (adminToEdit == nullptr) {

				Console::error("Admin not found.");
				break;
			}

			if (DataEntry::editInfo(adminToEdit)) {

				FileManager::updateAdmin();

			}
			break;
		}

		case 5:

			editSalaryAdmin(admin);
			FileManager::updateAdmin();

			break;

		case 6:
		{
			int idAdmin = DataEntry::enterId();

			if (idAdmin == admin->getId())
			{

				Console::error("You cannot delete the current logged-in admin.");
				break;

			}

			if (admin->removeAdmin(idAdmin)) {

				Console::success("Admin Removed Successfully\n");

				FileManager::updateAdmin();

			}
			else
			{

				Console::error("Admin Not Found.\n");
				 
			}
			break;
		}

		default:
             
			Console::error("Invalid Choice.");

	  }

	  return true;
	}


	static bool accountOptions(Admin* admin) {

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

			admin->display("MY PROFILE");

			break;

		case 2:
			if (DataEntry::editInfo(admin)) {

				FileManager::updateAdmin();

			}
			break;

		default:

			Console::error("Invalid Choice.");

	  }

	  return true;

	}

    static bool adminOptions(Admin* admin) {
        if (admin == nullptr) {
            return false;
        }

        printAdminMenu();

		int choice;
		 cout << "Enter your choice: ";

		 Console::white();
		 cin >> choice;
		 cin.ignore();
		 Console::yellow();

		switch (choice) {

		case 0:
			DashboardManager::dashBoard();
			break;

		case 1:
			while (clientManagementOptions(admin));
				break;

		case 2:
			while (employeeManagementOptions(admin));
			break;
		
		case 3:
			while (adminManagementOptions(admin));
			break;

		case 4:
			while (accountOptions(admin));
			break;

		case 5: return false;

		default:

			Console::error("Invalid Choice.");

		}

			return true;
	}
    


};

