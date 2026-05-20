#pragma once

#include <fstream>
#include <vector>

using std::string;
using std::wstring;
using std::ios;
using std::vector;


//	================类型转换================
string wstring转string(const wstring& wstr);

string ANSI转UTF8(const string& ansi);

string charpp转string(char** ppArgs, int nNumArgs);

vector<string> charpp转list_vector(char** ppArgs, int nNumArgs);
