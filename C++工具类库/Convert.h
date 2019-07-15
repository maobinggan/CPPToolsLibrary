#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>

class Convert
{
public:

	//************************************
	// Method:     ToStr_Int32
	// Description:ת�ַ�����32λ�޷�����תΪ�з�����
	// Parameter:  UINT32 uInt32 - 
	// Parameter:  OUT char * resStr - 
	// Returns:    void - 
	//************************************
	static void ToInt32Str(UINT32 uInt32, OUT char* resStr)
	{
		//�õ��з������������Ų��֡�
		char symbol32 = uInt32 & 0x80000000 ? '-' : '+';
		//�õ��з����������ֲ��֣�(����)�����һȡ����ȥ������λ��
		INT32 int32 = (symbol32 == '-') ? ~(uInt32 - 1) & 0x7FFFFFFF : uInt32;
		//�ַ���ƴ��
		sprintf(resStr, "%c%08X", symbol32, int32);
	}

	//************************************
	// Method:     ToStr_Int8
	// Description:ת�ַ�����8λ�޷�����תΪ�з�����
	// Parameter:  UINT8 uInt8 - 
	// Parameter:  OUT char * resStr - 
	// Returns:    void - 
	//************************************
	static void ToInt8Str(UINT8 uInt8, OUT char* resStr)
	{
		//�õ��з������������Ų��֡�
		char symbol8 = uInt8 & 0x80 ? '-' : '+';
		//�õ��з����������ֲ��֣�(����)�����һȡ����ȥ������λ��
		INT8 int8 = (symbol8 == '-') ? ~(uInt8 - 1) & 0x7F : uInt8;
		//�ַ���ƴ��
		sprintf(resStr, "%c%02X", symbol8, int8);
	}
};