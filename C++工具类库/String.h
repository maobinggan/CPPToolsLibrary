#pragma once
#include<iostream>

class String
{
private:
	char* data;

public:

	/**
	* 函 数 名: String
	* 说    明：构造函数(由字符常量)
				语句【String str="123";】是调用此构造函数
	* 参    数: const char * src -
	* 返 回 值:
	*/
	String(const char* src)
	{
		//复制src字符串的内容
		if (src == NULL)
		{
			this->data == NULL;
		}
		else
		{
			this->data = (char*)malloc(strlen(src) + 1);	//加一是为了终止符'\0'
			memset(this->data, 0x0, strlen(src) + 1);
			strcpy(this->data, src);
		}

	}

	/**
	* 函 数 名: String
	* 说    明：拷贝构造函数
				语句【String str1 = str2; 】是调用此运算符
	* 参    数: String & src -
	* 返 回 值:
	*/
	String(String& src)
	{
		//复制src字符串的内容
		if (src.data == NULL)
		{
			this->data == NULL;
		}
		else
		{
			this->data = (char*)malloc(strlen(src.data) + 1);	//加一是为了终止符'\0'
			memset(this->data, 0x0, strlen(src.data) + 1);
			strcpy(this->data, src.data);
		}
	}

	/**
	* 函 数 名: ~String
	* 说    明：当对象生命周期结束时调用析构函数
				在函数return时，存于栈内的对象自动调用析构函数，存于堆中的对象(即new出来的)需要手动delete
	* 返 回 值:
	*/
	~String()
	{
		free(this->data);
		data = NULL;
	}

	//重载运算符：赋值运算符
	String& operator=(const String& str)
	{
		if (this != &str)
		{

		}
		return *this;
	}


	/**
	* 函 数 名: operator=
	* 说    明：重载赋值运算符（由字符常量）
	*			语句【str="123";】是调用此运算符
	* 参    数: const char * src -
	* 返 回 值: String& - 写成'传引用'，编译器就不会在此函数结束后调用析构函数了。
	*/
	String& operator=(const char* src)
	{
		//释放原有字符串
		free(this->data);
		this->data = NULL;

		//重新赋值：拷贝src字符串的内容
		if (src == NULL)
		{
			data == NULL;
		}
		else
		{
			data = (char*)malloc(strlen(src) + 1);	//加一是为了终止符'\0'
			memset(data, 0x0, strlen(src) + 1);
			strcpy(data, src);
		}
		return *this;
	}

	/**
	* 函 数 名: ToCStr
	* 说    明：String 转为 char*
	* 返 回 值: char*
	*/
	char* ToPChar()
	{
		//返回指针
		return this->data;
	}

	char* SubString(int beginIndex, int endIndex)
	{

	}

	/**
	* 函 数 名: SubString
	* 说    明：截取字符串
	* 参    数: char * src -
	* 参    数: int beginIndex - 起始索引，索引从0开始。
	* 返 回 值: String
	*/
	char* SubString(int beginIndex)
	{
		//边界检查
		int strLen = strlen(this->data);
		if (beginIndex > strLen) { throw  "【exception】索引越界"; }

		//截取：构造一个新的char* ，
		char* newData = (char*)malloc(strLen - beginIndex + 1);
		memset(newData, 0x0, strLen - beginIndex + 1);
		memcpy(newData, this->data + beginIndex, strLen - beginIndex + 1);

		//返回char*后，将调用'重载赋值运算符（由字符常量）'赋值
		//例如  String sub=str.SubString(2);将调用'重载赋值运算符（由字符常量）'赋值给sub
		return newData;
	}


	//************************************
	// Method:     ToUpper
	// Description:转为大写字母str
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
				*cursor -= 32;//根据ASCII码
			}
			cursor++;
		}
	}

	//************************************
	// Method:     ToLower
	// Description:转为小写字母str
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
				*cursor += 32; //根据ASCII码
			}
			cursor++;
		}
	}
};



