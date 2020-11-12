#ifndef __MYSTRING_H
#define __MYSTRING_H
#include<iostream>
using namespace std;
#include <cstring>
class MyString{
private:
	char* m_data;
public:
	//有参构造函数
	MyString(const char* cstr = 0);
	//拷贝构造函数
	MyString(const MyString&rhs);
	//析构函数
	~MyString();
	//存取器
	char* data()const{return this->m_data;}
	size_t getSize()const{return strlen(this->m_data);}
	//算数运算符重载
	MyString operator+(const MyString& rhs);
	MyString& operator+=(const MyString& rhs);
	MyString operator=(const MyString& rhs);
	const char operator[](int index)const{return this->m_data[index];}
	char operator[](int index){return this->m_data[index];}
	//关系运算符重载
	bool operator<(const MyString& rhs)const{return strcmp(this->m_data, rhs.m_data) < 0;}
	bool operator<=(const MyString& rhs)const{return strcmp(this->m_data, rhs.m_data) <= 0;}
	bool operator==(const MyString& rhs)const{return strcmp(this->m_data, rhs.m_data) == 0;}
	bool operator>(const MyString& rhs)const{return strcmp(this->m_data, rhs.m_data) > 0;}
	bool operator>=(const MyString& rhs)const{return strcmp(this->m_data, rhs.m_data) >= 0;}
friend ostream& operator<<(ostream& out, const MyString&rhs);//输出流运算符重载
};
#endif
