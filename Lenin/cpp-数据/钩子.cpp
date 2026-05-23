#include <string>

#include "头文件/数据.h"

void 挂载钩子_替换 (DWORD 内存地址, void* 函数)
{
	BYTE* addr = (BYTE*)(内存地址基底_GameMD + 内存地址);
	DWORD oldProtect;
	VirtualProtect (addr, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	addr[0] = 0xE9;
	DWORD rel = (DWORD)函数 - (DWORD)(addr + 5);
	memcpy (addr + 1, &rel, 4);
	VirtualProtect (addr, 5, oldProtect, &oldProtect);
}