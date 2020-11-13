#ifndef MYLIST_H_
#define MYLIST_H_
#include <iostream>
using namespace std;

//声明节点结构化体类型
template <typename T>
struct Node{
	T	data;//数据
	Struct Node<T>* prev;//指向前一节点的指针
	struct Node<T>* next;//指向后一节点的指针
};

//声明迭代器类
template <typename T>
class Iterator{
public:
	Iterator (Node<T>* p)//构造函数
		:p(p)
	{
		
	}
	
	Iterator operator++(int)//后加加运算符重载
	{
		p = p->next;
		return Iterator(p);
	}
	
	T& operator *()const{return p->data;}//取值运算符重载
	bool operator != (const Iterator& rhs)const {return this->p != rhs.p;}//关系运算符重载
private:
	Node<T>* p;
};

//声明MyList列表容器类
class MyList{
private:
	Node<T>* head;//链表头节点
public:
	//迭代器访问方法
	typedef Iterator<T> iterator;
	iterator begin() {return iterator(this->head->next);}
	iterator end() {return iterator(this->head);}
	
	MyList();//无参构造
	MyList(const MyList& rhs);//拷贝构造
	void push_back(const T& value);
	void pop_back();
	Node<T>* operator[](int index)const;//节点访问
	int size()const;
	void bubble_sort(bool (*cmp)(T,T));//冒泡排序，升序or降序取决于回调函数
	void swap(Node<T> * lhs, Node<T>* rhs);//两个节点指针域交换
	~MyList();//析构函数
};

template <typename T>
MyList<T>::MyList()//无参构造
{
	this->head = new Node<T>();
	this->head->prev = this->head;
	this->head->next = this->head;
}

template <typename T>
MyList<T>::MyList(const MyList& rhs)//拷贝构造
{
	this->head = new Node<T>();
	this->head->prev = this->head;
	this->head->next = this->head;
	
	int i = 0;
	for(; i < rhs.size(); i++){
		this->push_back(rhs[i].data);
	}
}

template <typename T>
void MyList<T>::push_back(const T& value)
{
	//创建新节点
	Node<T>* pNode = new Node<T>();
	pNode->data = value;
	//链接节点
	pNode->next = this->head;
	pNode->prev = this->head->prev;
	this->head->prev->next = pNode;
	this->head->prev = pNode;
}

template <typename T>
void MyList<T>:: pop_back()
{
	Node<T>* n_t = this->head->prev;
	this->head->prev = n_t->prev;
	n_t->prev->next = this->head;
	delete n_t;//删除节点
}

template <typename T>
Node<T>* MyList<T>::operator[](int index)const//节点访问
{
	Node<T>* p = this->head->next;
	for(; index-- && p != this->head; p = p->next);
	return p;
}

template <typename T>
int MyList<T>::size()const
{
	Node<T>* p = this->head->next;
	int i = 0;
	for(; p != this->head; i++, p = p->next);
	return i;
}

template <typename T>
void MyList<T>::bubble_sort(bool (*cmp)(T,T))//冒泡排序，升序or降序取决于回调函数
{
	int len = this->size();
	int i = 0, j = 0;
	for(; i < len - 1; i++){
		for(j = 0; j < len - i - 1; j++){
			if(cmp((*this)[j]->data, (*this)[j + 1]->data)){
				swap((*this)[j]->data,(*this)[j + 1]->data);
			}
		}
	}
}

template <typename T>
void MyList<T>::swap(Node<T> * lhs, Node<T>* rhs)//两个节点指针域交换
{
	lhs->prev->next = rhs;
	rhs->next->prev = lhs;
	
	rhs->prev = lhs->prev;
	lhs->next = rhs->next;
	
	rhs->next = lhs;
	lhs->prev = rhs;
}

template <typename T>
MyList<T>::~MyList()//析构函数
{
	Node<T>* p = this->head->next;
	while(p != this->head){
		p = p->next;
		delete p->prev;
		p->prev = nullptr;
	}
	delete this->head;
	this->head = nullptr;
}
#endif