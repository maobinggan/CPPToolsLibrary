#pragma once
#include "iostream"
#include "String.h"
#include "Convert.h"

/**
* 函 数 名: ConvertTest
* 说    明：测试Convert
* 返 回 值: void
*/
void ConvertTest()
{
	//测试：32位、8位 无符号数转为有符号数字符串
	UINT32 uInt32 = 0x80000001;		//三十二位无符号数 8000 0001 -> 有符号数 -7FFF FFFF
	UINT8 uInt8 = 0x81;				//八位无符号数 81 -> 有符号数 -7F
	char uInt32Str[20] = { 0 };
	char uInt8Str[20] = { 0 };
	Convert::ToInt32Str(uInt32, uInt32Str);
	Convert::ToInt8Str(uInt8, uInt8Str);
	printf("signed int32 = %s  signed int8 =%s \n", uInt32Str, uInt8Str);

}

/**
* 函 数 名: StringTest
* 说    明：测试String
* 返 回 值: void
*/
void StringTest()
{
	//测试普通构造函数(由字符常量)
	String str = "1234";

	//调用拷贝构造函数（对象通过另一个对象进行初始化）
	String str2 = str;

	//测试赋值运算符(由字符常量)
	str = "ABCDE";

	//测试字符串截取
	String subStr = str.SubString(2);

	//String转为char*打印
	printf("%s \n", subStr.ToPChar());

	//测试字符串拼接
	str = "11"+str;
	str = str + "22";
	str = "LL" + str+"RR";
	str = str + "MM" + str;

}



void main()
{


	/*测试 String*/
	StringTest();

	/*测试 Convert*/
	ConvertTest();

	system("pause");
}