#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
string toString(char* chr);
string now_playing;
string ExePath();
void writeToFile(string title);
