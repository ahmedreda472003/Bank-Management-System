#pragma once
#include "Employee.h"
using namespace std;

class Admin : public Employee {
private:
    static vector <Admin> allAdmins;

public:

    Admin(int id, string name,string password, double salary) 
        : Employee(id, name, password, salary){}



    static void addAdminToVector(Admin& admin) {
        allAdmins.push_back(admin);
    }

    static  vector<Admin>& getVectorAdmin() {
        return allAdmins;
    }




    void addEmployee(Employee& employee) {
        Employee::addEmployeeToVector(employee);
    }

    void addAdmin(Admin& admin) {
        Admin::addAdminToVector(admin);
    }

   static Employee* searchEmployee(int id) {
        vector<Employee>& allemployees = Employee::getVectorEmployee();

        for (Employee& e : allemployees) {
            if (e.getId() == id)
                return &e;  // ترجع عنوان العميل  vector
        }

        return nullptr;

    }


   static Admin* searchAdmin(int id) {
       vector<Admin>& allAdmins = Admin::getVectorAdmin();

       for (Admin& a : allAdmins) {
           if (a.getId() == id)
               return &a;  // ترجع عنوان العميل  vector
       }

       return nullptr;

   }

    
    void editEmployee(int id, string name, string password, double salary) {
        Employee* e = searchEmployee(id);

        if (e == nullptr) {
            throw runtime_error("Employee not found");
        }

        e->setName(name);
        e->setPassword(password);
        e->setSalary(salary);

       
    }


    void listAllEmployee() {
         vector<Employee>& allEmployees = Employee::getVectorEmployee();

        for ( Employee& e : allEmployees) {
            e.display();
        }

    }


    void listAllAdmin() {
        vector<Admin>& allAdmins = Admin::getVectorAdmin();

        for (Admin& e : allAdmins) {
            e.display();
        }

    }


    bool removeEmployee(int id) {
        vector<Employee>& allEmployees = Employee::getVectorEmployee();
        for (int i = 0; i < allEmployees.size(); i++) {
            if (allEmployees[i].getId() == id) {
                allEmployees.erase(allEmployees.begin() + i);
                return true;
            }
        }
        return false;
    }


    bool removeAdmin(int id) {
        vector<Admin>& allAdmins = Admin::getVectorAdmin();
        for (int i = 0; i < allAdmins.size(); i++) {
            if (allAdmins[i].getId() == id) {
                allAdmins.erase(allAdmins.begin() + i);
                return true;
            }
        }
        return false;
    }


    void display(string title = "ADMIN INFO") {
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

    ~Admin() {}

};

