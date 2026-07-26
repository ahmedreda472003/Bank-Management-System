#pragma once
#include <fstream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FilesHelper.h"
using namespace std;

class FileManager
{
public:

	static void addClient(Client& c) {
		FilesHelper::saveClient(c);
	}

	static void addEmployee(Employee& e) {
		FilesHelper::saveEmployee(EMPLOYEE_FILE,  e);
	}

	static void addAdmin(Admin& a) {
		FilesHelper::saveEmployee(ADMIN_FILE, a);
	}

	static void fetchAllClients() {
		FilesHelper::fetchClients();
	}

	static void fetchAllEmployees() {
		FilesHelper::fetchEmployees();
	}


	static void fetchAllAdmins() {
		FilesHelper::fetchAdmins();
	}

	static void fetchAllData() {
		FilesHelper::fetchAdmins();
		FilesHelper::fetchEmployees();
		FilesHelper::fetchClients();
	}

	static void removeAllClients() {
		FilesHelper::clearFile(CLIENT_FILE, LAST_ID_FILE_CLIENT);
	}

	static void removeAllEmployees() {
		FilesHelper::clearFile(EMPLOYEE_FILE, LAST_ID_FILE_EMPLOYEE);
	}

	static void removeAllAdmins() {
		FilesHelper::clearFile(ADMIN_FILE, LAST_ID_FILE_ADMIN);
	}



	static void updateClient() {
		removeAllClients();

		vector<Client>& allclients = Client::getVectorClient();

		for (Client& c : allclients) {
			addClient(c);
		}
	}

	static void updateEmployee() {

		removeAllEmployees();

		vector<Employee>& allEmployee = Employee::getVectorEmployee();

		for (Employee& e : allEmployee) {
			addEmployee(e);
		}
	}

	static void updateAdmin() {
		removeAllAdmins();

		vector<Admin>& allAdmin = Admin::getVectorAdmin();

		for (Admin& a : allAdmin) {
			addAdmin(a);
		}
	}	

};