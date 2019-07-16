#pragma once
#include<iostream>

class String
{
private:

	char* data;

public:

	//************************************
	// Method:     String 
	// Description: ��ͨ���캯��(���ַ�����)
	//				��䡾 String str = "123" ���ǵ��ô˹��캯��
	// Parameter:  const char * src - 
	// Returns:     - 
	//************************************
	String(const char* src = NULL)
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

	//************************************
	// Method:     String 
	// Description: �������캯��
	//				�������캯����һ������Ĺ��캯�������������Ʊ����������һ�£��������һ�������Ǳ����͵�һ�����ñ�����
	//				�������캯���ĵ���ʱ����
	//				1.��ĳ�����ķ��������Ǹ������
	//				2.��������Ҫͨ������һ��������г�ʼ����������䡾String str2 = str����str2�����ͨ��str�����ʼ��
	// Parameter:  String & src - 
	// Returns:     - 
	//************************************
	String(const String& src)
	{
		if (this != &src)
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

	}

	//************************************
	// Method:     ~String 
	// Description: ��������
	//				�������������ڽ���ʱ����(������returnʱ������ջ�ڵĶ����Զ������������������ڶ��еĶ���(��new������)��Ҫ�ֶ�delete)
	// Returns:     -  
	//************************************
	~String()
	{
		free(this->data);
		data = NULL;
	}

	//************************************
	// Method:     operator= 
	// Description: ��ֵ��������ɶ���
	//				��䡾 str1 = str2 ���ǵ��ô��������ע�⣺��䡾 String str1 = str2 ����δʹ����������أ����ǵ����˿������졣
	// Parameter:  const String & right - 
	// Returns:    String - 
	//************************************
	String operator=(const String& right)
	{
		//�ͷ�
		free(this->data);
		this->data = NULL;
		//��ֵ
		this->data = (char*)malloc(strlen(right.data) + 1);
		memset(this->data, 0, strlen(right.data) + 1);
		strcpy(this->data, right.data);

		//�ȵ��ÿ������캯�������ֲ�����newStr�ĵ�ַ���룬��newStr�ĸ���Ա���ݿ�����һ���µ�[��ʱ����]��
		//��󷵻ص���[��ʱ����]
		return *this;
		//���������������[��ʱ����]������������������������
	}

	//************************************
	// Method:     operator= 
	// Description: ���ظ�ֵ����������ַ�������
	//				��䡾 str = "123" ���ǵ��ô������
	// Parameter:  const char * right -
	// Returns:    String -
	//************************************
	String operator=(const char* right)
	{
		//�ͷ�ԭ���ַ���
		free(this->data);
		this->data = NULL;

		//���¸�ֵ������src�ַ���������
		if (right == NULL)
		{
			data == NULL;
		}
		else
		{
			int len = strlen(right);
			char* temp = (char*)malloc(len + 1);	//��һ��Ϊ����ֹ��'\0'
			data = temp;
			memset(data, 0x0, strlen(right) + 1);
			strcpy(data, right);
		}

		//�ȵ��ÿ������캯�������ֲ�����newStr�ĵ�ַ���룬��newStr�ĸ���Ա���ݿ�����һ���µ�[��ʱ����]��
		//��󷵻ص���[��ʱ����]
		return *this;
		//���������������[��ʱ����]������������������������
	}

	//************************************
	// Method:     operator+ 
	// Description: ���������'+'����Ա����(���ַ�����)
	//				��䡾String newStr = str + "123"�������ô������ operator + ("123")
	// Parameter:  const char * right - 
	// Returns:    String& - 
	//************************************
	String operator+(const char* right)
	{
		//�����¶���
		String newStr;
		newStr.data = (char*)malloc(strlen(this->data) + strlen(right) + 1);
		memset(newStr.data, 0x0, strlen(this->data) + strlen(right) + 1);

		//ƴ��
		strcat(newStr.data, this->data);
		strcat(newStr.data, right);

		//�ȵ��ÿ������캯�������ֲ�����newStr�ĵ�ַ���룬��newStr�ĸ���Ա���ݿ�����һ���µ�[��ʱ����]��
		//������newStr���������������������������
		//��󷵻ص���[��ʱ����]
		return newStr;
	}


	//************************************
	// Method:     operator+ 
	// Description: ���������'+'����Ա����(�ɶ���)
	// Parameter:  const String & str - 
	// Returns:    String - 
	//************************************
	String operator+(const String& right)
	{
		String newString;

		//ֻҪ������һ��ΪNULL�մ����Ͳ���Ҫƴ��
		if (right.data == NULL)
		{
			return *this;
		}
		else if (this->data == NULL)
		{
			newString = right;
		}
		else
		{
			//ƴ��
			newString.data = (char*)malloc(strlen(right.data) + strlen(this->data) + 1);
			memset(newString.data, 0, strlen(right.data) + strlen(this->data) + 1);
			strcat(newString.data, this->data);
			strcat(newString.data, right.data);
		}

		//�ȵ��ÿ������캯�������ֲ�����newStr�ĵ�ַ���룬��newStr�ĸ���Ա���ݿ�����һ���µ�[��ʱ����]��
		//������newStr���������������������������
		//��󷵻ص���[��ʱ����]
		return newString;
	}



	//************************************
	// Method:     operator+ 
	// Description: ���������'+'����Ԫ����
	//				�����������Ϊ�����Ԫ����ʱ��û��������thisָ�룬���еĲ�����������ͨ���������βν��д��ݣ������Ĳ������������������һһ��Ӧ�� 
	//				��䡾String newStr = "123" + str�������ô������ operator + ("123",str)
	// Parameter:  const char * left - �ַ�����
	// Parameter:  const String & right - String����
	// Returns:    friend char*
	//************************************
	friend String operator+(const char* left, String& right)
	{
		//�����µĶ��ڴ�
		String newStr;
		newStr.data = (char*)malloc(strlen(left) + strlen(right.data) + 1);
		memset(newStr.data, 0x0, strlen(left) + strlen(right.data) + 1);

		//ƴ��
		strcat(newStr.data, left);
		strcat(newStr.data, right.data);

		//�ȵ��ÿ������캯�������ֲ�����newStr�ĵ�ַ���룬��newStr�ĸ���Ա���ݿ�����һ���µ�[��ʱ����]��
		//������newStr���������������������������
		//��󷵻ص���[��ʱ����]
		return newStr;
	}

	//************************************
	// Method:     ToPChar 
	// Description: String תΪ char*
	// Returns:    char* -  
	//************************************
	char* ToPChar()
	{
		//����ָ��
		return this->data;
	}

	char* SubString(int beginIndex, int endIndex)
	{

	}

	//************************************
	// Method:     SubString 
	// Description: ��ȡ�ַ���
	// Parameter:  int beginIndex - ��ʼ������������0��ʼ
	// Returns:    char* -  
	//************************************
	String SubString(int beginIndex)
	{
		//�߽���
		int strLen = strlen(this->data);
		if (beginIndex > strLen) { throw  "��exception������Խ��"; }

		//����һ���µ�String 
		String newStr;
		newStr.data = (char*)malloc(strLen - beginIndex + 1);
		memset(newStr.data, 0x0, strLen - beginIndex + 1);

		//��ȡ
		memcpy(newStr.data, this->data + beginIndex, strLen - beginIndex + 1);

		//�ȵ��ÿ������캯�������ֲ�����newStr�ĵ�ַ���룬��newStr�ĸ���Ա���ݿ�����һ���µ�[��ʱ����]��
		//������newStr���������������������������
		//��󷵻ص���[��ʱ����]
		return newStr;
	}

	//************************************
	// Method:     ToUpper 
	// Description:תΪ��д��ĸstr
	// Returns:    String - 
	//************************************
	String ToUpper()
	{
		String newStr = String(this->data);
		char* cursor = newStr.data;
		while (*cursor != 0)
		{
			if (*cursor >= 'a' && *cursor <= 'z')
			{
				*cursor -= 32;//����ASCII��
			}
			cursor++;
		}
		return newStr;
	}

	//************************************
	// Method:     ToLower 
	// Description:תΪСд��ĸstr
	// Returns:    String - 
	//************************************
	String ToLower()
	{
		String newStr = String(this->data);
		char* cursor = newStr.data;
		while (*cursor != 0)
		{
			if (*cursor >= 'A' && *cursor <= 'Z')
			{
				*cursor += 32;//����ASCII��
			}
			cursor++;
		}
		return newStr;
	}
};



