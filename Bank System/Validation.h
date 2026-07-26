#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
using namespace std;
class Validation{
public:

    static bool isValidName(const string& name)
    {
        if (name.empty()) {
            return false;
        }

        // لا يبدأ أو ينتهي بمسافة
        if (name.front() == ' ' || name.back() == ' ') {
            return false;
        }

        int letterCount = 0;
        bool lastWasSpace = false;

        for (char c : name)
        {
            if (isalpha(static_cast<unsigned char>(c)))
            {
                letterCount++;
                lastWasSpace = false;
            }
            else if (c == ' ')
            {
                // يمنع وجود مسافتين متتاليتين
                if (lastWasSpace)
                    return false;

                lastWasSpace = true;
            }
            else
            {
                // أي رمز أو رقم غير مسموح
                return false;
            }
        }

        return letterCount >= 3 && letterCount <= 20;
    }


	static bool isValidPassword(string password, int minCount = 8, int maxCount = 20)
	{
		if (password.size() < minCount || password.size() > maxCount){
			return false;
		}

		bool hasLower = false;
		bool hasUpper = false;

		for (int i = 0; i < password.size(); i++){
			
			if (!isalnum(password[i])){
				return false;
			}

			

			if (islower(password[i]))
				hasLower = true;
			else if (isupper(password[i]))
				hasUpper = true;
		}

		return (hasLower && hasUpper);	
	}


	static bool ceckMinimum(double number, int min) {
		if (number >= min) {
			return true; 
		}		
		return false;
	}


    static string inputPassword() {
        string password="";
        char ch;

        while ((ch = _getch()) != '\r') { // Enter
            if (ch == '\b') { // Backspace
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                password += ch;
                cout << '*';
            }
        }

        cout << endl;
        return password;
    }


  
};

