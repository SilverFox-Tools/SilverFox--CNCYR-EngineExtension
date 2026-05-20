#include <Windows.h>
#include <string>
#include <Helpers\macro.h>

#include "Stalin.h"
#include "头文件/数据.h"
#include "头文件/通用函数.h"
#include "头文件/其他.h"
#include "头文件/启动游戏.h"

using std::ios;

bool 存在Ares = false;
extern vector<string> Ares文件名列表 = {
    "Ares.dll"
};

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        g_hDllModule = hModule;
        获取根目录();
        写入日志(获取标志(), false, ios::out);
        写入日志("");
        写入日志("!!!DLL加载成功");
        写入日志("");
        写入日志("!!!Dll根目录为:\n——>\t" + dll根目录);
        写入日志("!!!Dll目录为:\n——>\t" + dll目录);

		存在Ares = 存在多个文件_任意一个(Ares文件名列表, dll根目录);

        写入日志("");

        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


vector <string> 参数列表;
//获取进程参数
DEFINE_HOOK(0x52F639, _get_Options, 0x5)
{
    写入日志("!!!获取进程参数");
    GET(char**, ppArgs, ESI);
    GET(int, nNumArgs, EDI);
    写入日志(
        "完整参数——>\t"
        +
        ANSI转UTF8(
            charpp转string(ppArgs, nNumArgs)
        )
    );

    参数列表 = charpp转list_vector(ppArgs, nNumArgs);
    string 字符串 = "参数:\n";
    for (const auto& 参数 : 参数列表) {
        字符串 += "——>\t" + 参数 + "\n";
	}
    写入日志(字符串);

    写入日志("");
    return 0;
}

//进程创建
DEFINE_HOOK(0x7CD810, 进程创建, 0x9)
{
    写入日志("!!!进程创建");

#if DEBUG
    杀死调试器();
#endif
    if (存在Ares) {

	}
    else
    {
        启动游戏_跳过RA2MD检测();
        InstallPrismHook();
    }
    写入日志("");
    return 0;
}

//进程退出
DEFINE_HOOK(0x7CD8F1, 进程退出, 0x5)
{   
    写入日志("!!!进程退出");

    写入日志("");
    return 0;
}

//游戏初始化
DEFINE_HOOK(0x52CAE9, 游戏初始化, 0x5)
{
    写入日志("!!!游戏初始化");

	Sleep(1000*1);

    写入日志("");
    return 0;
}

//初始化
DEFINE_HOOK(0x6BD7CB, 初始化, 0x5)
{
    写入日志("!!!初始化");

    写入日志("");
    return 0;
}

//主循环内调用的渲染函数
//DEFINE_HOOK(0x55D84F, _process_渲染, 0x5)
//{
//    写入日志("主循环内调用的渲染函数");
//    return 0;
//}

//主循环前初始化
//DEFINE_HOOK(0x48CE7E, 主循环前初始化, 0x5)
//{
//    写入日志("主循环前初始化");
//    return 0;
//}

//0x7CD810


//DEFINE_HOOK(0x48CE8A, EntryPoint, 0x5)
//{
//    写入日志("aaa");
//    return 0;
//}
