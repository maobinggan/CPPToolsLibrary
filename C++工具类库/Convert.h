#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>

class Convert
{
public:

	//************************************
	// Method:     ToStr_Int32
	// Description:转字符串：32位无符号数转为有符号数
	// Parameter:  UINT32 uInt32 - 
	// Parameter:  OUT char * resStr - 
	// Returns:    void - 
	//************************************
	static void ToInt32Str(UINT32 uInt32, OUT char* resStr)
	{
		//得到有符号数的正负号部分。
		char symbol32 = uInt32 & 0x80000000 ? '-' : '+';
		//得到有符号数的数字部分：(负数)补码减一取反，去掉符号位。
		INT32 int32 = (symbol32 == '-') ? ~(uInt32 - 1) & 0x7FFFFFFF : uInt32;
		//字符串拼接
		sprintf(resStr, "%c%08X", symbol32, int32);
	}

	//************************************
	// Method:     ToStr_Int8
	// Description:转字符串：8位无符号数转为有符号数
	// Parameter:  UINT8 uInt8 - 
	// Parameter:  OUT char * resStr - 
	// Returns:    void - 
	//************************************
	static void ToInt8Str(UINT8 uInt8, OUT char* resStr)
	{
		//得到有符号数的正负号部分。
		char symbol8 = uInt8 & 0x80 ? '-' : '+';
		//得到有符号数的数字部分：(负数)补码减一取反，去掉符号位。
		INT8 int8 = (symbol8 == '-') ? ~(uInt8 - 1) & 0x7F : uInt8;
		//字符串拼接
		sprintf(resStr, "%c%02X", symbol8, int8);
	}
};