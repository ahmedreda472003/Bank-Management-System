#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
using namespace std;


const string ADMIN_FILE = "Admins.txt";
const string CLIENT_FILE = "Clients.txt";
const string EMPLOYEE_FILE = "Employees.txt";
const string LAST_ID_FILE_CLIENT = "last_id_client.txt";
const string LAST_ID_FILE_EMPLOYEE = "last_id_employee.txt";
const string LAST_ID_FILE_ADMIN = "last_id_admin.txt";


class FilesHelper{
public:
	static void saveLast(string fileName, int id) {
		ofstream database(fileName);
		if (database.is_open())
		{
			database << id;
		}

		database.close();
	
	}
	static int getLast(string fileName) {
		ifstream database(fileName);
		
			int id = 0;
			if (database.is_open())
			{
				database >> id;
			}
			database.close();
			return id;
    }

	static void saveClient(Client& c) {
		/*int newId = getLast(LAST_ID_FILE_CLIENT) + 1;*/
		ofstream database(CLIENT_FILE, ios::app);
		if (database.is_open())
		{
			database
				<< c.getId() <<  '-'
				<< c.getName() << '-'
				<< c.getPassword() << '-'
				<< c.getBalance()
				<< endl;
		}
		
		/*saveLast(LAST_ID_FILE_CLIENT, newId);*/
		database.close();
	}

	static void saveEmployee(string fileName, Employee e) {
		//int newId = getLast(lastIdFile) + 1;
		ofstream database(fileName, ios::app);
		if (database.is_open())
		{
			database
				<< e.getId() << '-'
				<< e.getName() << '-'
				<< e.getPassword() << '-'
				<< e.getSalary()
				<< endl;
		}

		/*saveLast(lastIdFile, newId);*/
		database.close();

	}

	static void fetchClients() {
		ifstream database(CLIENT_FILE);

		if (database.is_open())
		{
			string line;
			while (getline(database, line))
			{	

				if (line.empty())
					continue;

				Client c = Parser::parseToClient(line);
				Client::addClientToVector(c);
			}
		}

		database.close();
	}


	static void fetchEmployees() {
		
		ifstream database(EMPLOYEE_FILE);
		if (database.is_open())
		{
			string line;
			
			while (getline(database, line))
			{

				if (line.empty())
					continue;

				Employee e = Parser::parseToEmployee(line);
				Employee::addEmployeeToVector(e);
			}
		}
		database.close();
	}

	static void fetchAdmins() {
		ifstream database(ADMIN_FILE);
		if (database.is_open())
		{
			string line;		
			while (getline(database, line))
			{

				if (line.empty())
					continue;

				Admin a = Parser::parseToAdmin(line);
				Admin::addAdminToVector(a);
				
			}
		}
		database.close();

	}


	static void clearFile(string fileName, string lastIdFile) {
		ofstream database(fileName, ios::trunc);
		database.close();


	}
};

