#pragma once
#include "iostream"
#include "String.h"


/**  
* �� �� ��: StringTest 
* ˵    ��������String
* �� �� ֵ: void 
*/
void StringTest() 
{
	//������ͨ���캯��(���ַ�����)
	String str = "ABCD"; 

	//���ÿ������캯��
	String str2 = str; 

	//���ø�ֵ�����(���ַ�����)
	str = "1234";		

	//�ȵ���substring�������õ����ص�char*����������ͨ���캯��(���ַ�����)��char*���ݸ��µ�String����
	String subStr = str.SubString(2); 

	//StringתΪchar*��ӡ
	printf("%s \n", subStr.ToPChar());
}


void main() 
{
	/*���� String*/
	StringTest();

	system("pause");
}