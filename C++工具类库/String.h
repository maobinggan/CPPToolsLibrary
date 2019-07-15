#pragma once
#include<iostream>

class String
{
private:
	char* data;

public:

	/**
	* �� �� ��: String
	* ˵    �������캯��(���ַ�����)
				��䡾String str="123";���ǵ��ô˹��캯��
	* ��    ��: const char * src -
	* �� �� ֵ:
	*/
	String(const char* src)
	{
		//����src�ַ���������
		if (src == NULL)
		{
			this->data == NULL;
		}
		else
		{
			this->data = (char*)malloc(strlen(src) + 1);	//��һ��Ϊ����ֹ��'\0'
			memset(this->data, 0x0, strlen(src) + 1);
			strcpy(this->data, src);
		}

	}

	/**
	* �� �� ��: String
	* ˵    �����������캯��
				��䡾String str1 = str2; ���ǵ��ô������
	* ��    ��: String & src -
	* �� �� ֵ:
	*/
	String(String& src)
	{
		//����src�ַ���������
		if (src.data == NULL)
		{
			this->data == NULL;
		}
		else
		{
			this->data = (char*)malloc(strlen(src.data) + 1);	//��һ��Ϊ����ֹ��'\0'
			memset(this->data, 0x0, strlen(src.data) + 1);
			strcpy(this->data, src.data);
		}
	}

	/**
	* �� �� ��: ~String
	* ˵    �����������������ڽ���ʱ������������
				�ں���returnʱ������ջ�ڵĶ����Զ������������������ڶ��еĶ���(��new������)��Ҫ�ֶ�delete
	* �� �� ֵ:
	*/
	~String()
	{
		free(this->data);
		data = NULL;
	}

	//�������������ֵ�����
	String& operator=(const String& str)
	{
		if (this != &str)
		{

		}
		return *this;
	}


	/**
	* �� �� ��: operator=
	* ˵    �������ظ�ֵ����������ַ�������
	*			��䡾str="123";���ǵ��ô������
	* ��    ��: const char * src -
	* �� �� ֵ: String& - д��'������'���������Ͳ����ڴ˺���������������������ˡ�
	*/
	String& operator=(const char* src)
	{
		//�ͷ�ԭ���ַ���
		free(this->data);
		this->data = NULL;

		//���¸�ֵ������src�ַ���������
		if (src == NULL)
		{
			data == NULL;
		}
		else
		{
			data = (char*)malloc(strlen(src) + 1);	//��һ��Ϊ����ֹ��'\0'
			memset(data, 0x0, strlen(src) + 1);
			strcpy(data, src);
		}
		return *this;
	}

	/**
	* �� �� ��: ToCStr
	* ˵    ����String תΪ char*
	* �� �� ֵ: char*
	*/
	char* ToPChar()
	{
		//����ָ��
		return this->data;
	}

	char* SubString(int beginIndex, int endIndex)
	{

	}

	/**
	* �� �� ��: SubString
	* ˵    ������ȡ�ַ���
	* ��    ��: char * src -
	* ��    ��: int beginIndex - ��ʼ������������0��ʼ��
	* �� �� ֵ: String
	*/
	char* SubString(int beginIndex)
	{
		//�߽���
		int strLen = strlen(this->data);
		if (beginIndex > strLen) { throw  "��exception������Խ��"; }

		//��ȡ������һ���µ�char* ��
		char* newData = (char*)malloc(strLen - beginIndex + 1);
		memset(newData, 0x0, strLen - beginIndex + 1);
		memcpy(newData, this->data + beginIndex, strLen - beginIndex + 1);

		//����char*�󣬽�����'���ظ�ֵ����������ַ�������'��ֵ
		//����  String sub=str.SubString(2);������'���ظ�ֵ����������ַ�������'��ֵ��sub
		return newData;
	}


	//************************************
	// Method:     ToUpper
	// Description:תΪ��д��ĸstr
	// Parameter:  char * src - 
	// Returns:    void - 
	//************************************
	static void ToUpper(char* src)
	{
		char* cursor = src;
		while (*cursor != 0)
		{
			if (*cursor > 'a' && *cursor < 'z')
			{
				*cursor -= 32;//����ASCII��
			}
			cursor++;
		}
	}

	//************************************
	// Method:     ToLower
	// Description:תΪСд��ĸstr
	// Parameter:  char * src - 
	// Returns:    void - 
	//************************************
	static void ToLower(char* src)
	{
		char* cursor = src;
		while (*cursor != 0)
		{
			if (*cursor > 'A' && *cursor < 'Z')
			{
				*cursor += 32; //����ASCII��
			}
			cursor++;
		}
	}
};



