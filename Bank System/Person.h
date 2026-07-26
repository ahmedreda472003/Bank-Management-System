#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

#include "Validation.h"

using namespace std;

class Person
{
protected:
    int id;
    string name , password;
    string error;
public:
    Person(int id, string name,  string password ) : id(id)
    {
        setName(name);
        setPassword(password);

        if (!error.empty())
            throw invalid_argument(error);
    }

    bool setName(const string& name)
    {
        if (!Validation::isValidName(name))
        {
            return false;
        }

        this->name = name ;
        return true;
    }


    bool setPassword(const string& password)
    {
        if (!Validation::isValidPassword(password))
        {
           
            return false;

        }
        

        this->password = password;

        return true;
    }


    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    string getPassword() const
    {
        return password;
    }

    string passwordHash() {
        string passwordHash;
        for (int i = 1; i <= password.size(); i++) {
            passwordHash += "*";
        }
        return  passwordHash;

    }


    virtual void display(string title = "PERSON") = 0;

    virtual ~Person() {}
};