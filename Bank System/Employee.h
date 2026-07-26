#pragma once
#include "Person.h"
#include "Client.h"

using namespace std;
class Employee :public Person { 
protected:
	
	double salary;
	static vector <Employee> allEmployees;
public:

	Employee(int id, string name,string password, double salary) :
		Person(id, name, password) { 
		setSalary(salary);
		
		if (!error.empty()) {
			throw invalid_argument(error);
	    }

	}


	static void addEmployeeToVector(Employee& employees) {
		allEmployees.push_back(employees);
	}


	static vector<Employee>& getVectorEmployee() {
		return allEmployees;
	}



	void addClient(Client& client) {
		Client::addClientToVector(client);
	}

	bool removeClient(int id) {
		vector<Client>& allclients = Client::getVectorClient();
		for (int i = 0; i < allclients.size(); i++) {
			if (allclients[i].getId() == id) {
				allclients.erase(allclients.begin() + i);
				return true;
			}
		}
		return false;
	}

	static Client* searchClient(int id) {
		vector<Client>& allclients = Client::getVectorClient();

		for (Client& c : allclients) {
			if (c.getId() == id)
				return &c;  //    vector  ترجع عنوان العميل داخل ال
		}

		return nullptr;
	}

	    void listAllClient() {
			 vector<Client>& allclients = Client::getVectorClient();

		   for ( Client& c : allclients) {
			   c.display();  
		   }

	    }


			void editClient(int id, string name, string password, double balance) {
				Client* c = searchClient(id);

				if (c == nullptr) {
					throw runtime_error("Client not found");
				}

				c->setName(name);
				c->setPassword(password);
				c->setMinimumBalance(balance);

			

			}



	   bool setSalary(double salary) {
		   if (!Validation::ceckMinimum(salary ,5000) )		  	
		    {
			  
			    return false;
		   }

		    this->salary = salary;
			return true;
	   }



	    double getSalary() const {
			return salary;
		}


		void display(string title = " EMPLOYEE INFO") {
			cout << "\n=========================================\n";
			Console::lightblue();
			cout << setw(25) << title;
			Console::yellow();
			cout << "\n=========================================\n";

			cout << "ID       : ";
			                              Console::white();
			                             cout << id << endl;


			
			Console::yellow();
			cout << "Name     : ";
			                             Console::white();
			                             cout << name << endl;


			Console::yellow();
			cout << "Password : ";
			                                   Console::white();
			                                cout << passwordHash() << endl;


			Console::yellow();
			cout << "Salary   : ";
			                                   Console::white();
			                                    cout << salary << endl;


			Console::yellow();
			cout << "=========================================";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			cout << endl << endl;
		}


	~Employee(){}


};

