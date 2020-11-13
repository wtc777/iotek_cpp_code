#include <iostream>
using namespace std;
#include "MyList.h"
//链表遍历打印
template <typename T>
void display(MyList<T> list){
	int i = 0;
	for(; i < list.size(); i++){
		cout<<list[i]->data<<" ";
	}
	cout<<endl;
}
//链表遍历打印-迭代器访问
template <typename T>
void displaybyit(MyList<T> list)
{
	typename iterator it = list.begin();
	for(; it != list.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

//回调函数-比较方法
bool cmpdown(int lhs, int rhs){return lhs < rhs;}
bool cmp up(int lhs, int rhs){return lhs > rhs;}

int main(void)
{
	MyList<int> l1;
	cout<<"please input numbers:"<<endl;
	int num = 0;
	while(1){
		cin>>num;
		if(-1 == num) break;//退出程序条件
		l1.push_back(num);
	}
	display(l1);
	l1.bubble_sort(cmpdown);
	cout<<"after bubble_sort down:"<<endl;
	display(l1);
	l1.bubble_sort(cmpup);
	cout<<"after bubble_sort up:"<<endl;
	displaybyit(l1);
	return 0;
}