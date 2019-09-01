#pragma once
#include "iostream"
#include "String.h"
#include "SignedINT.h"

/**
* �� �� ��: Test_SignedINT
* ˵    ��������SignedINT
* �� �� ֵ: void
*/
void Test_SignedINT()
{
	//���ԣ�32λ��8λ �޷�����תΪ�з������ַ���
	printf("\n����Convert... \n");
	UINT32 uInt32 = 0x80000001;		//��ʮ��λ�޷����� 8000 0001 -> �з����� -7FFF FFFF
	UINT8 uInt8 = 0x81;				//��λ�޷����� 81 -> �з����� -7F

	SignedINT SignedInt32 = SignedINT::GetInt32(uInt32);
	SignedINT SignedInt8 = SignedINT::GetInt8(uInt8);

	printf("signed int32 = %c%08llX  signed int8 =%c%02X \n", SignedInt32.symbol, SignedInt32.digit, SignedInt8.symbol, SignedInt8.digit);

}

/**
* �� �� ��: StringTest
* ˵    ��������String
* �� �� ֵ: void
*/
void StringTest()
{
	printf("\n����String... \n");
	//������ͨ���캯��(���ַ�����)
	String str = "1234";

	//���ÿ������캯��������ͨ����һ��������г�ʼ����
	String str2 = str;

	//���Ը�ֵ�����(���ַ�����)
	str = "ABCDE";

	//�����ַ�����ȡ
	String subStr = str.SubString(2);
	subStr = str.SubString(1, 3);

	//���Ը�ֵ�����(�ɶ���)
	str2 = subStr;

	//StringתΪchar*��ӡ
	printf("%s \n", subStr.GetPChar());

	//�����ַ���ƴ��
	str = "11" + str;
	str = str + "22";
	str = "LL" + str + "RR";
	str = str + "_MM_" + str;

	//���Դ�Сдת��
	str = "AbCd";
	str = str.ToUpper();
	str = str.ToLower();

	//���Ը�ʽ������String
	String formatStr = String::Format("%08X", 0x123ABC);

	//����String��ֵ�Ƚ�
	String strcmp = "ABC";
	if (strcmp.Equals("ABCD")) { printf("��ͬ \n"); }
	else { printf("����ͬ \n"); }
	if (strcmp.Equals(strcmp)) { printf("��ͬ \n"); }
	else { printf("����ͬ \n"); }

}



void main()
{


	/*���� String*/
	//StringTest();

	/*���� Convert*/
	Test_SignedINT();

	system("pause");
}