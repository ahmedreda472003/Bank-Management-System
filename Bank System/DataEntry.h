#pragma once
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include"Person.h"
#include"Console.h"
#include "Validation.h"
class DataEntry
{
public:

	static string enterName() {

		string name;

		while (true) {
			cout << "\nEnter Name: ";
			Console::white();
			getline(cin, name);
			Console::yellow();

			if (Validation::isValidName(name)) {

				Console::success("Name accepted.\n");
				
				return name;
			}

			Console::error("Invalid name! \n");
			cout << "Name must contain only letters and be between 3 and 20 characters. ";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			cout << endl << endl;
		}
	}


	static string enterPassword() {

		while (true) {

			cout << "\nEnter Password: ";

			Console::white();
			string password = Validation::inputPassword();
			Console::yellow();

			if (Validation::isValidPassword(password)) {

				Console::success("Password accepted.\n");

				return password;

			}

			Console::error("Invalid password! \n");
			cout << "Password must be between 8 and 20 characters. ";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			cout << endl << endl;
		}
	}

	static double enterBalance() {

		double balance;
		while (true) {

			cout << "\nEnter Balance: ";
			Console::white();
			cin >> balance;
			cin.ignore();
			Console::yellow();

			if (Validation::ceckMinimum(balance, 1500)) {

				Console::success("Balance accepted.\n");

				return balance;

			}
			Console::error("Invalid balance! \n");
			cout << "Minimum balance is 1500. ";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			cout << endl << endl;
		}
	}


	static double enterSalary() {

		double salary;

		while (true) {

			cout << "\nEnter Salary: ";

			Console::white();
			cin >> salary;
			cin.ignore();
			Console::yellow();

			if (Validation::ceckMinimum(salary, 5000)) {

				Console::success("Salary accepted.\n");

				return salary;

			}
			Console::error("Invalid salary! \n");
			cout << "Minimum salary is 5000. ";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			cout << endl << endl;
		}
	}



	static bool changePassword(Person* person) {

		while (true) {

			cout << "\n=========================================\n";
			Console::lightblue();
			cout << "           CHANGE PASSWORD";
			Console::yellow();
			cout << "\n=========================================\n";

			cout << "\nNote: Enter 0 to cancel.\n";

			// Current Password
			cout << "\nCurrent Password: ";
			Console::white();
			string currentPassword = Validation::inputPassword();
			Console::yellow();

			if (currentPassword == "0")
				return false;

			if (person->getPassword() != currentPassword) {
				Console::error("Current password is incorrect! \n");
				continue;
			}

			// New Password
			cout << "\nNew Password: ";
			Console::white();
			string newPassword = Validation::inputPassword();
			Console::yellow();

			if (newPassword == "0")
				return false;

			// Confirm Password
			cout << "\nConfirm Password: ";
			Console::white();
			string confirmPassword = Validation::inputPassword();
			Console::yellow();

			if (confirmPassword == "0")
				return false;

			if (newPassword != confirmPassword) {
				Console::error("Passwords do not match! \n");
				continue;
			}

			if (!person->setPassword(newPassword)) {
				Console::error("Invalid password! \n");
				continue;
			}

			Console::success("Password changed successfully.\n");

			return true;
		}
	}



	static bool changeName(Person* person) {

		while (true) {

			cout << "\n=========================================\n";
			Console::lightblue();
			cout << "            CHANGE NAME";
			Console::yellow();
			cout << "\n=========================================\n";

			cout << "\nNote: Enter 0 to cancel.\n";


			string newName;
			// New Name
			cout << "\nNew Name: ";
			Console::white();
			getline(cin, newName);
			Console::yellow();

			if (newName == "0")
				return false;


			if (!person->setName(newName)) {
				Console::error("Invalid name! \n");
				continue;
			}

			Console::success("Name changed successfully.\n");

			return true;
		}
	}



	static bool editInfo(Person* person) {

		if (person == nullptr)
			return false;

		cout << "\n=========================================\n";
		Console::lightblue();
		cout << "        UPDATE INFORMATION";
		Console::yellow();
		cout << "\n=========================================\n\n";

		Console::lightblue();
		cout << "Personal Information\n";
		Console::yellow();
		cout << "-------------------------\n";

		cout << "[1] Update Name\n\n";
		cout << "[2] Update Password\n\n";

		Console::lightblue();
		cout << "Return\n";
		Console::yellow();
		cout << "-------------------------\n";

		cout << "[0] Back\n\n";

		cout << "Select an option: ";
		int choice;
		Console::white();
		cin >> choice;
		cin.ignore();
		Console::yellow();

		switch (choice) {

		case 0:
			return false;

		case 1:
			return changeName(person);

		case 2:
			return changePassword(person);

		default:
			Console::error("Invalid option!");
			return false;
		}
	}




	static int enterId() {
		int id;
		cout << "\nGet id account: ";

		Console::white();
		cin >> id;
		cin.ignore();
		Console::yellow();

		return id;

	}

};

