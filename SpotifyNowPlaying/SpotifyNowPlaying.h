#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
string toString(char* chr);
string now_playing;
