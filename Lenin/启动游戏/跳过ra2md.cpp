#include "头文件/数据.h"


//48BC11BD-C4D7-466b-8A31-C6ABBAD47B3E
//D6E7FC97-64F9-4d28-B52C-754EDF721C6F
__declspec(naked) void 跳过ra2md检测_桥接器()
{
    __asm {
        push ecx
        push ebx
        push esi

        mov al, 1

        pop esi
        pop ebx
        pop ecx
        retn
    }
}

void 启动游戏_跳过RA2MD检测()
{
    挂载钩子_替换(YR引擎常量::RA2MD检测_0, 跳过ra2md检测_桥接器);
    挂载钩子_替换(YR引擎常量::RA2MD检测_1, 跳过ra2md检测_桥接器);

	写入日志("!!!跳过RA2MD的检测");
}