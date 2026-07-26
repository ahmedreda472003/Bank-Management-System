#pragma once
#include <thread>
#include <chrono>
#include "Person.h"
#include "Console.h"
using namespace std;

class Client :public Person {
private:

	 double balance;
	static vector <Client> allClients;

public:
	Client(int id, string name,string password, double balance) :
		Person(id, name, password) 
	{
		   setMinimumBalance(balance);
		   if (!error.empty()) {
			   throw invalid_argument(error);
		   }
	
	}

	

	static void addClientToVector( Client& client) {
		allClients.push_back(client);
	}


	static vector<Client>& getVectorClient() {
		return allClients;
	}


	bool setMinimumBalance(double balance) {
		if (!Validation::ceckMinimum(balance, 1500))
		{
			return false;
		}
		this->balance = balance;
		return true;
	}


	bool deposit(double amount) {
		if (amount < 0) {
			Console::error("It is not permissible to deposit funds in this case ");	
			return false;
		}

		balance += amount;
		return true;
	} 


	bool withdraw(double amount) {
		if (amount < 0) {
			Console::error("Withdrawals are not permitted in this case ");
			return false;
		}

		if (balance >= amount) {
			balance = balance - amount;
			return true;
		}

		else { 
			Console::error("The amount is not enough ");
			return false;
		}
	}


	bool transferTo(double amount, Client& recipient) {
		
		if (amount <= 0) {
			Console::error("Transfers are not allowed in this case ");
			return false;
		}

		else if (this == &recipient) {
			Console::error("You can't transfer to the same account. ");
			return false;
		}
		else if (balance < amount) {
			Console::error("The amount is not enough ");
			return false;
		}

			balance -= amount;
			recipient.balance += amount;
			return true;		
	}


	double getBalance() const {
		return balance;
	}

	

	void display(string title = "CLIENT INFO") {
		cout << "\n=========================================\n";
		Console::lightblue();
		cout << setw(25) << title;
		Console::yellow();
		cout << "\n=========================================\n";

		cout << "ID       : " ;
		                                Console::white();
			                            cout << id << endl;
		Console::yellow();
		cout << "Name     : " ;
		                               Console::white();
                                        cout << name << endl;
		Console::yellow();
		cout << "Password : " ;
		                                  Console::white();
                                        cout << passwordHash() << endl;
		Console::yellow();
		cout << "Balance  : " ;
		                                 Console::white();
                                        cout << balance << endl;

		Console::yellow();
		cout<< "=========================================";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		cout << endl << endl;
	}

	~Client() {}
};

