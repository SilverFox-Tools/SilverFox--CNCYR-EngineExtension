#include <Windows.h>
#include <string>
#include <Helpers\macro.h>

#include "Stalin.h"
#include "头文件/数据.h"
#include "头文件/其他.h"
#include "头文件/启动游戏.h"
#include "头文件/通用函数.h"

//目前无法实现！！！因为无法挂钩子，注射器会提示Could not run executable 仅完成部分的ReadProcessMemory或WriteProcessMemory

//DEFINE_HOOK(0xC9C70, 建造队列处理, 0x5)
DEFINE_HOOK(0x4C9CAC, 建造队列处理, 0x5)
{
    //__asm {
    //    jmp 0x004C9CC9    // 直接跳转到 loc_4C9CC9 (注意地址为 VA)
    //}

    写入日志("建造队列函数被调用");

    写入日志("");

    return 0;   // 让框架执行原始指令并返回
}