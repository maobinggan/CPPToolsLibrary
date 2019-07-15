#pragma once
#include "iostream"
#include "String.h"
#include "Convert.h"

/**  
* �� �� ��: ConvertTest 
* ˵    ��������Convert
* �� �� ֵ: void 
*/
void ConvertTest()
{
	//���ԣ�32λ��8λ �޷�����תΪ�з������ַ���
	UINT32 uInt32 = 0x80000001;		//��ʮ��λ�޷����� 8000 0001 -> �з����� -7FFF FFFF
	UINT8 uInt8 = 0x81;				//��λ�޷����� 81 -> �з����� -7F
	char uInt32Str[20] = { 0 };
	char uInt8Str[20] = { 0 };
	Convert::ToInt32Str(uInt32, uInt32Str);
	Convert::ToInt8Str(uInt8, uInt8Str);
	printf("signed int32 = %s  signed int8 =%s \n", uInt32Str, uInt8Str);

}

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

	/*���� Convert*/
	ConvertTest();

	system("pause");
}