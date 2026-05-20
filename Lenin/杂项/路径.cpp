#include <string>
#include <filesystem>
#include <iostream>

#include "头文件/数据.h"
#include "头文件/通用函数.h"

using std::string;
using std::wstring;
using namespace std;
namespace fs = std::filesystem;


HMODULE g_hDllModule = NULL;
string dll根目录 = 规范路径(ANSI转UTF8 (fs::absolute(".\\").string()));
string dll目录 = "";

string 规范路径(string 路径)
{
    while (!路径.empty() && 路径.back() == '\\') {
        路径.pop_back();
    }
	return 路径;
}

bool 获取根目录()
{
    static wchar_t dllPath[32768] = { 0 };  // Windows最大路径限制是32767

    if (g_hDllModule)
    {
        GetModuleFileNameW(g_hDllModule, dllPath, 32768);

        wstring path(dllPath);
        size_t pos = path.find_last_of(L"\\/");
        if (pos != wstring::npos)
        {
            dll目录 = dll根目录 + wstring转string(path.substr (pos));
			return true;
        }
    }
    return false;
}

bool 存在文件(string 路径)
{
    DWORD attrs = GetFileAttributesA(路径.c_str());
    return (attrs != INVALID_FILE_ATTRIBUTES) && !(attrs & FILE_ATTRIBUTE_DIRECTORY);
}

bool 存在多个文件_任意一个(const vector<string>& 文件列表 , const string& 根目录)
{
    for (const auto& 文件名 : 文件列表) {
        if (存在文件(根目录 + "\\" + 文件名)) {
            return true;
        }
    }
	return false;
}