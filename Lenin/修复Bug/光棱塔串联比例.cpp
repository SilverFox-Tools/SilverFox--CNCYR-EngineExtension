#include <Windows.h>
#include <string>
#include <Helpers\macro.h>

#include "Stalin.h"
#include "头文件/数据.h"
#include "头文件/其他.h"

// ==============================
// 需要你从 IDA 确认的三个偏移量（RVA）
// ==============================
#define RVA_SUB_5283D0              0x5283D0    // sub_5283D0 函数的 RVA
#define RVA_PRISM_START             0x12A3C8    // "sub esp,8" 这条指令的 RVA（劫持起点）
#define RVA_PRISM_RETURN            0x12A3F0    // "mov [esi+49Ch], eax" 之后的下一条指令的 RVA（跳回点）

// 字符串常量的 RVA（直接从 IDA 复制）
#define RVA_OFF_7F0C9C              0x7F0C9C    // 指向 "General" 的指针存储处
#define RVA_A_PRISMSUPPORTMO        0x89D2E8    // "PrismSupportModifier" 字符串本身

// 原版系数，与 ds:dbl_7E2AC0 相同（一般是 150.0）
static constexpr double kPrismCoeff = 150.0;

// ==============================
// 安装时自动赋值的全局变量
// ==============================
static DWORD g_dwFunc5283D0 = 0;            // sub_5283D0 的绝对地址
static DWORD g_dwReturnAddr = 0;            // 跳回原函数的地址
static LPCSTR g_pGeneral = nullptr;         // "General" 字符串指针
static LPCSTR g_pPrismSupport = nullptr;    // "PrismSupportModifier" 字符串指针

// ==============================
// 业务函数：完全复刻原版汇编的逻辑
// ==============================
void __fastcall 复刻光棱支援(void* pThis, void* pUnit)
{
    // pThis -> edi, pUnit -> esi
    uint8_t* unit = (uint8_t*)pUnit;

    // 1. 调用原版函数 sub_5283D0，读取浮点值
    double rawValue = 0.0;
    __asm {
        mov ecx, pThis
        push g_pPrismSupport    // "PrismSupportModifier"
        push g_pGeneral         // "General"
        call[g_dwFunc5283D0]   // 调用原版函数，返回值在 ST(0)
        fstp qword ptr[rawValue]
    }

    // 2. 乘以系数
    double result = rawValue * kPrismCoeff;

    // 3. 转为整数（截断，与原版 sub_7C5F00 一致）
    int newValue = (int)result;

    // 4. 写入 [esi+49Ch]
    *(int*)(unit + 0x49C) = newValue;
}

// ==============================
// 裸钩桥接器（极简版）
// ==============================
__declspec(naked) void 光棱支援_桥接器()
{
    __asm {
        pushad
        pushfd
        push edi       // pThis
        push esi       // pUnit
        call 复刻光棱支援
        add esp, 8
        popfd
        popad
        jmp[g_dwReturnAddr]   // 跳回原函数继续执行
    }
}

// ==============================
// 安装钩子
// ==============================
void InstallPrismHook()
{
    DWORD base = (DWORD)GetModuleHandle("gamemd.exe");
    if (!base) return;

    // 1. 计算所有绝对地址
    g_dwFunc5283D0 = base + RVA_SUB_5283D0;
    g_dwReturnAddr = base + RVA_PRISM_RETURN;

    // 获取字符串指针（注意：off_7F0C9C 是指向字符串的指针，需要解引用一次）
    g_pGeneral = *(LPCSTR*)(base + RVA_OFF_7F0C9C);
    g_pPrismSupport = (LPCSTR)(base + RVA_A_PRISMSUPPORTMO);

    // 2. 在劫持起点写入 JMP 指令
    DWORD hookAddr = base + RVA_PRISM_START;
    DWORD old;
    VirtualProtect((void*)hookAddr, 5, PAGE_EXECUTE_READWRITE, &old);
    *(BYTE*)hookAddr = 0xE9;                           // jmp rel32
    DWORD rel = (DWORD)光棱支援_桥接器 - (hookAddr + 5);
    memcpy((void*)(hookAddr + 1), &rel, 4);
    VirtualProtect((void*)hookAddr, 5, old, &old);

    写入日志("!!!光棱支援逻辑已替换（复刻原版）");
}