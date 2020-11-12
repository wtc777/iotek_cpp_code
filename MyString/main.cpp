#include "MyString.h"

int main(void)
{
	MyString s1("hello");
	MyString s2 = s1; //调用拷贝构造
	cout<<"s1"<<s1<<"s2"<<s2<<endl;
	if(s1 == s2){
		cout<<"s1 == s2"<<endl;
	}
	
	MyString s3("iotek");
	cout<<"s3"<<s3<<endl;
	if(s3 > s2){
		cout<<"s3 > s2"<<endl;
	}
	
	return 0;
}