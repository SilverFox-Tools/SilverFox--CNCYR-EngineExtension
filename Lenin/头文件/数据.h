#pragma once

#include <windows.h>
#include <fstream>
#include <vector>

using std::string;
using std::wstring;
using std::ios;
using std::vector;

extern HMODULE g_hDllModule;
extern string dll根目录;
extern string dll目录;

extern bool 存在Ares;

extern vector<string> 参数列表;
extern vector<string> Ares文件名列表;

namespace YR引擎常量 {
    constexpr DWORD RA2MD检测_0 = 0x9F5C0;
    constexpr DWORD RA2MD检测_1 = 0x9F620;
}


//	================获取数据================
string 获取标志();
string 获取当前时间();


//	================文件路径================
string 规范路径(string 路径);
bool 获取根目录();
bool 存在文件(string 路径);
bool 存在多个文件_任意一个(const vector<string>& 文件列表, const string& 根目录);


//	================读写文件================
bool 写入文本(string 文件路径 = "", string 内容 = "", ios::openmode 模式 = ios::out);
bool 写入日志(string 内容 = "", bool 是否写入时间 = true, ios::openmode 模式 = ios::app);


//	================读写内存================
string 读取内存数据_string(const char* 内存地址, int 数据大小);
bool 写入内存数据_string(const string& 内容, char* 内存地址, int 缓冲区大小);

int 读取内存数据_int(const void* 内存地址);
bool 写入内存数据_int(int 数据, void* 内存地址, size_t 缓冲区大小);

//	----------------内存钩子----------------
void 挂载钩子_替换(DWORD 内存地址, void* 函数);