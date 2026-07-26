#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
using namespace std;
class Console
{
public:
   

    static void lightblue() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11); } //  عناوين
   
    static void yellow() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); }   // لون البرنامج
   
    static void green() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); }    // النجاح
   
    static void red() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); }      // الخطا
   
    static void white() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); }    //  المستخدم



    static void error(const string& message) {
        red();
        cout << "-> " << message << '\n';
        yellow();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    static void success(const string& message) {
        green();
        cout << "-> " << message << '\n';
        yellow();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }


};

