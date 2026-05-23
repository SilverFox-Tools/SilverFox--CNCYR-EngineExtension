#include <string>
#include <cstring>
using std::string;

string 读取内存数据_string (const char* 内存地址, int 数据大小)
{
	string 输出;

	if (内存地址 == nullptr || 数据大小 <= 0)
	{
		return 输出;  // 返回空字符串
	}

	输出.resize (数据大小);
	memcpy (&输出[0], 内存地址, 数据大小);
	return 输出;
}

bool 写入内存数据_string (const string& 内容, char* 内存地址, int 缓冲区大小)
{
	if (内存地址 == nullptr || 缓冲区大小 <= 0)
	{
		return false;
	}

	if (内容.size () > 缓冲区大小)
	{
		return false;
	}

	memcpy (内存地址, 内容.c_str (), 内容.size ());
	return true;
}


int 读取内存数据_int (const void* 内存地址)
{
	if (内存地址 == nullptr) return 0;

	int 输出;
	memcpy (&输出, 内存地址, sizeof (int));
	return 输出;
}

bool 写入内存数据_int (int 数据, void* 内存地址, size_t 缓冲区大小)
{
	if (内存地址 == nullptr || 缓冲区大小 < sizeof (int)) return false;

	memcpy (内存地址, &数据, sizeof (int));
	return true;
}


float 读取内存数据_float (const void* 内存地址)
{
	if (内存地址 == nullptr) return 0.0f;
	float 输出;
	memcpy (&输出, 内存地址, sizeof (float));
	return 输出;
}

bool 写入内存数据_float (float 数据, void* 内存地址, size_t 缓冲区大小)
{
	if (内存地址 == nullptr || 缓冲区大小 < sizeof (float)) return false;
	memcpy (内存地址, &数据, sizeof (float));
	return true;
}


double 读取内存数据_double (const void* 内存地址)
{
	if (内存地址 == nullptr) return 0.0;
	double 输出;
	memcpy (&输出, 内存地址, sizeof (double));
	return 输出;
}

bool 写入内存数据_double (double 数据, void* 内存地址, size_t 缓冲区大小)
{
	if (内存地址 == nullptr || 缓冲区大小 < sizeof (double)) return false;
	memcpy (内存地址, &数据, sizeof (double));
	return true;
}
