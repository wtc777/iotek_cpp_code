#include "MyString.h"
//有参构造函数
MyString::MyString(const char* cstr)
{
	if(NULL == cstr){
		this->m_data = new char[1]();
		this->m_data[0] = '\0';
	}
	int len = strlen(cstr);
	this->m_data = new char[len + 1]();
	strcpy(this->m_data, cstr);
	this->m_data[len] = '\0';
}
//拷贝构造函数
MyString::MyString(const MyString&rhs)
{
	int len = strlen(rhs.m_data);
	this->m_data = new char[len + 1];
	strcpy(this->m_data, rhs.m_data);
	this->m_data[len] = '\0';
}
//析构函数
MyString::~MyString()
{
	if(NULL != this->m_data){
		delete[] m_data;
		m_data = NULL;
	}
}
MyString MyString::operator+(const MyString& rhs)
{
	MyString temp;
	int len = strlen(this->m_data) + strlen(rhs.m_data);
	temp.m_data = new char[len + 1]();
	strcpy(temp.m_data, this->m_data);
	strcat(temp.m_data, rhs.m_data);
	temp.m_data[len] = '\0';
	return temp;//临时对象，返回值采用值传递
}
MyString& MyString::operator+=(const MyString& rhs)
{
	*this = *this + rhs;
	return *this;
}
MyString MyString::operator=(const MyString& rhs)
{
	if(this == &rhs) return *this;//防止自我赋值
	delete[]this->m_data;
	int len = strlen(rhs.m_data);
	this->m_data = new char[len + 1];
	strcpy(this->m_data, rhs.m_data);
	this->m_data[len] = '\0';
	return rhs;
}
//运算符重载
ostream& operator<<(ostream& out, const MyString&rhs)
{
	out<<rhs.m_data;
	return out;
}