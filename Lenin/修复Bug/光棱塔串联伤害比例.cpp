#include "头文件/数据.h"
#include "头文件/通用函数.h"

namespace 变量_ATesla串联伤害比例 {
	static LPCSTR General = nullptr;
	static LPCSTR PrismSupportModifier = nullptr;

	static double* 浮点数3E2AC0 = nullptr;

	static DWORD 从Rules查找_双精度浮点 = 0;
	static DWORD 函数3C5F00 = 0;

	static DWORD 光棱塔串联伤害比例_返回点		= 0;
}

__declspec(naked) void 修复Bug_光棱塔串联伤害比例_桥接器 ()
{
	__asm {
		sub		esp, 8
		fild	dword ptr[esi + 49Ch]

		mov		eax, [变量_ATesla串联伤害比例::浮点数3E2AC0]
		fdiv    qword ptr[eax]

		fstp	qword ptr[esp]

		mov		edx, [变量_ATesla串联伤害比例::General]
		push	[变量_ATesla串联伤害比例::PrismSupportModifier]
		push	edx
		mov		ecx, edi	//ATesla，PrismType的值。因为是给PrismType里的建筑设置属性，RA2/YR 里填的是ATesla

		call	[变量_ATesla串联伤害比例::从Rules查找_双精度浮点]

		mov		eax, [变量_ATesla串联伤害比例::浮点数3E2AC0]
		fmul	qword ptr[eax]
		call	[变量_ATesla串联伤害比例::函数3C5F00]
		mov		[esi + 49Ch], eax

		jmp		[变量_ATesla串联伤害比例::光棱塔串联伤害比例_返回点]
	}
}

void 修复Bug_光棱塔串联伤害比例()
{
	变量_ATesla串联伤害比例::General				= (LPCSTR)(内存地址基底_GameMD + YR引擎常量_内存地址::字符串_General);
	变量_ATesla串联伤害比例::PrismSupportModifier = (LPCSTR)(内存地址基底_GameMD + YR引擎常量_内存地址::字符串_PrismSupportModifier);

	变量_ATesla串联伤害比例::从Rules查找_双精度浮点	= 内存地址基底_GameMD + YR引擎常量_内存地址::从Rules查找_双精度浮点;
	变量_ATesla串联伤害比例::函数3C5F00				= 内存地址基底_GameMD + YR引擎常量_内存地址::函数3C5F00;

	变量_ATesla串联伤害比例::浮点数3E2AC0		= (double*)(内存地址基底_GameMD + YR引擎常量_内存地址::浮点数3E2AC0);

	变量_ATesla串联伤害比例::光棱塔串联伤害比例_返回点			= 内存地址基底_GameMD + YR引擎常量_内存地址::光棱塔串联伤害比例_返回点;

	挂载钩子_替换 (YR引擎常量_内存地址::光棱塔串联伤害比例			, 修复Bug_光棱塔串联伤害比例_桥接器);

	写入日志 ("修复Bug-光棱塔串联伤害比例");
}