#pragma once
#include "iostream"
#include "String.h"
#include "SignedINT.h"

/**
* 函 数 名: Test_SignedINT
* 说    明：测试SignedINT
* 返 回 值: void
*/
void Test_SignedINT()
{
	//测试：32位、8位 无符号数转为有符号数字符串
	printf("\n测试Convert... \n");
	UINT32 uInt32 = 0x80000001;		//三十二位无符号数 8000 0001 -> 有符号数 -7FFF FFFF
	UINT8 uInt8 = 0x81;				//八位无符号数 81 -> 有符号数 -7F

	SignedINT SignedInt32 = SignedINT::GetInt32(uInt32);
	SignedINT SignedInt8 = SignedINT::GetInt8(uInt8);

	printf("signed int32 = %c%08llX  signed int8 =%c%02X \n", SignedInt32.symbol, SignedInt32.digit, SignedInt8.symbol, SignedInt8.digit);

}

/**
* 函 数 名: StringTest
* 说    明：测试String
* 返 回 值: void
*/
void StringTest()
{
	printf("\n测试String... \n");
	//测试普通构造函数(由字符常量)
	String str = "1234";

	//调用拷贝构造函数（对象通过另一个对象进行初始化）
	String str2 = str;

	//测试赋值运算符(由字符常量)
	str = "ABCDE";

	//测试字符串截取
	String subStr = str.SubString(2);
	subStr = str.SubString(1, 3);

	//测试赋值运算符(由对象)
	str2 = subStr;

	//String转为char*打印
	printf("%s \n", subStr.GetPChar());

	//测试字符串拼接
	str = "11" + str;
	str = str + "22";
	str = "LL" + str + "RR";
	str = str + "_MM_" + str;

	//测试大小写转换
	str = "AbCd";
	str = str.ToUpper();
	str = str.ToLower();

	//测试格式化创建String
	String formatStr = String::Format("%08X", 0x123ABC);

	//测试String的值比较
	String strcmp = "ABC";
	if (strcmp.Equals("ABCD")) { printf("相同 \n"); }
	else { printf("不相同 \n"); }
	if (strcmp.Equals(strcmp)) { printf("相同 \n"); }
	else { printf("不相同 \n"); }

}



void main()
{


	/*测试 String*/
	//StringTest();

	/*测试 Convert*/
	Test_SignedINT();

	system("pause");
}