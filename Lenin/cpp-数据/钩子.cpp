#include <string>

#include "头文件/数据.h"

void 挂载钩子_替换(DWORD 内存地址, void* 函数)
{
    DWORD base = (DWORD)GetModuleHandle("gamemd.exe");
    if (!base) return;

    BYTE* addr = (BYTE*)(base + 内存地址);
    DWORD oldProtect;
    VirtualProtect(addr, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
    addr[0] = 0xE9;                               // jmp rel32
    DWORD rel = (DWORD)函数 - (DWORD)(addr + 5);
    memcpy(addr + 1, &rel, 4);
    VirtualProtect(addr, 5, oldProtect, &oldProtect);
}