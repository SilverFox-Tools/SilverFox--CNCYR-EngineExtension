#pragma once

#include <fstream>
#include <vector>

using std::string;
using std::wstring;
using std::ios;
using std::vector;


//	================类型转换================
//	----------------转换成string----------------
string wstring转string (const wstring& wstr);

string ANSI转UTF8 (const string& ansi);

string charpp转string (char** ppArgs, int nNumArgs);

vector<string> charpp转list_string (char** ppArgs, int nNumArgs);

string int转string (int 数字);

string float转string (float 数字);

string double转string (double 数字);


//	----------------转换成char----------------
char* string转charp (string str);
