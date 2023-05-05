// HelloStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>
#include <Windows.h>

using namespace std;

void FirstWay();
void SecondWay();
void PrintUsage();

int main(int argc, char *argv[])
{
    if (argc == 1)
        FirstWay();
    if (argc == 2)
    {
        PrintUsage();
        return 0;
    }
    else
    {
        char* p;
        int option = strtol(argv[1], &p, 10);
        if (option == 2)
            SecondWay();
        else
            FirstWay();
    }
   
    wcin.get();
}

void PrintUsage()
{
    using namespace std;
    wcout << L"usage: hellostring.exe /[1|2]" << endl;
    wcout << L"[1]\tPrint chinese characters with set local and change the code page by default." << endl;
    wcout << L"[2]\tPrint chinese characters with _setmode." << endl;
}

void FirstWay()
{
    using namespace std;
    auto codePage = GetConsoleOutputCP();
    wcout << L"current code page: " << codePage << endl;
    wcout.imbue(locale("chs"));
    wcout << L"chinese character:" << L"你好" << endl;
    wcout << L"Trying set code page: 936" << endl;
    DWORD err=SetConsoleOutputCP(936);
   if (err == 0)
   {
       DWORD errCode= GetLastError();
       wcout << L"Set code page:936 failed! The Error is: "<< errCode<<endl;
   }else
       wcout << L"Set code page: 936 successfully!" << endl;
   wcout << L"chinese character:" << L"你好" << endl;
}

void SecondWay()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"chinese character:" << L"你好" << endl;
}

