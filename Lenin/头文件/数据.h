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

extern DWORD 内存地址基底_GameMD;

namespace YR引擎常量_内存地址 {
	constexpr DWORD RA2MD检测_0	= 0x9F5C0;
	constexpr DWORD RA2MD检测_1	= 0x9F620;

	constexpr DWORD 光棱塔串联伤害比例					= 0x27114F;//67114f
	constexpr DWORD 光棱塔串联伤害比例_返回点			= 0x27117F;

	constexpr DWORD 字符串_General				= 0x426278;
	constexpr DWORD 字符串_PrismSupportModifier	= 0x43BBDC;

	constexpr DWORD 函数3C5F00	= 0x3C5F00;

	constexpr DWORD 浮点数3E2AC0	= 0x3E2AC0;


	constexpr DWORD 从Rules查找_双精度浮点				= 0x1283D0;//int 节,int 键,double 默认值
	constexpr DWORD 从Rules查找_双精度浮点_节是否有效	= 0x1283DD;//cmp
	constexpr DWORD 从Rules查找_双精度浮点_键是否有效	= 0x1283E9;//cmp
	constexpr DWORD 从Rules查找_双精度浮点_找到键		= 0x1284ED;//loc

}


//	================获取数据================
string 获取标志 ();
string 获取当前时间 ();


//	================文件路径================
string 规范路径 (string 路径);
bool 获取根目录 ();
bool 存在文件 (string 路径);
bool 存在多个文件_任意一个 (const vector<string>& 文件列表, const string& 根目录);


//	================读写文件================
bool 写入文本 (string 文件路径 = "", string 内容 = "", ios::openmode 模式 = ios::out);
bool 写入日志 (string 内容 = "", bool 是否写入时间 = true, ios::openmode 模式 = ios::app);


//	================读写内存================
string 读取内存数据_string (const char* 内存地址, int 数据大小);
bool 写入内存数据_string (const string& 内容, char* 内存地址, int 缓冲区大小);

int 读取内存数据_int (const void* 内存地址);
bool 写入内存数据_int (int 数据, void* 内存地址, size_t 缓冲区大小);

float 读取内存数据_float (const void* 内存地址);
bool 写入内存数据_float (float 数据, void* 内存地址, size_t 缓冲区大小);

double 读取内存数据_double (const void* 内存地址);
bool 写入内存数据_double (double 数据, void* 内存地址, size_t 缓冲区大小);

//	----------------内存钩子----------------
void 挂载钩子_替换 (DWORD 内存地址, void* 函数);