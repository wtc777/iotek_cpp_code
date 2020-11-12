#include "MyVector.h"

#include <iostream>
using namespace std;
int main(void)
{
	MyVector<int> v;//调用无参构造函数创建该对象
	MyVector<int> v1(4,100);//调用有参构造创建该对象
	MyVector<int> cv = v1;//调用拷贝构造函数初始化该对象
	
	for(int i = 0; i < 10; i++){
		v.push_back(i);
	}
	
	for(int i = 0; i < v.getSize(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	for(MyVector<int>::iterator it = cv.begin(); it != cv.end(); it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}