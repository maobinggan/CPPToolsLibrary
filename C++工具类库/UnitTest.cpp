#pragma once
#include "iostream"
#include "String.h"


/**  
* 函 数 名: StringTest 
* 说    明：测试String
* 返 回 值: void 
*/
void StringTest() 
{
	//调用普通构造函数(由字符常量)
	String str = "ABCD"; 

	//调用拷贝构造函数
	String str2 = str; 

	//调用赋值运算符(由字符常量)
	str = "1234";		

	//先调用substring函数，得到返回的char*，随后调用普通构造函数(由字符常量)将char*传递给新的String对象
	String subStr = str.SubString(2); 

	//String转为char*打印
	printf("%s \n", subStr.ToPChar());
}


void main() 
{
	/*测试 String*/
	StringTest();

	system("pause");
}