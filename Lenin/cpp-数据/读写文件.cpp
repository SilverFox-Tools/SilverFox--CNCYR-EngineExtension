#include <string>
#include <fstream>
#include "头文件/数据.h"

using std::string;
using std::ios;
using std::ofstream;


bool 写入文本(string 文件路径, string 内容, ios::openmode 模式)
{
	ofstream file(文件路径, 模式);

	if (file.is_open())
	{
		file << 内容;
		file.close();
		return true;
	}

	return false;
}

bool 写入日志(string 内容, bool 是否写入时间, ios::openmode 模式)
{
	if (是否写入时间 && !内容.empty())
	{
		内容 = "[" + 获取当前时间() + "]" + 内容;
	}
	return 写入文本(".\\DFYH.log", 内容 + "\n", 模式);
}

string 获取标志()
{
	string 字符串;
	字符串 += ";;;⬛ ⬛ ⬛ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬛ ⬛ ⬛ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛\n";
	字符串 += ";;;⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛\n";
	字符串 += ";;;⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬜ ⬜ ⬛ ⬛ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛\n";
	字符串 += ";;;⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬜ ⬜ ⬛ ⬛ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛\n";
	字符串 += ";;;⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬛ ⬛ ⬛ ⬛ ⬜ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬛ ⬛ ⬛ ⬛ ⬛ ⬛\n";
	字符串 += ";;;⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛\n";
	字符串 += ";;;⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛\n";
	字符串 += ";;;⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛\n";
	字符串 += ";;;⬛ ⬛ ⬛ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬜ ⬛ ⬛ ⬜ ⬜ ⬛ ⬛\n";
	return 字符串;
}