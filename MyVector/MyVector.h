#ifndef VECTOR_H
#define VECTOR_H
/*
顺序容器：元素加入的顺序和存储的顺序保持一致
vector<T>动态数组 可以存储任意类型元素
string 自动增长，但是只能存储char类型的元素
*/
template<typename T>
class MyVector{
private:
	T* m_data;//数组的首地址
	int size;//实际元素的个数
	int capacity;//总容量
	
public:	
	//迭代器访问
	typedef T* iterator;
	iterator begin(){return this->m_data;}
	iterator end(){return this->m_data + size;}
	
	MyVector(int maxsize = 5);//构造函数
	~MyVector();//析构函数
	MyVector(int n,const T&value);//有参构造函数
	MyVector(const MyVector<T>& rhs);//拷贝构造函数
	
	int getSize()const{return this->size;}
	//添加元素
	void push_back(const T& value);
	//删除元素
	void pop_back(){this->size--;}
	//访问元素
	T& operator[](int index){return this->m_data[index];}
};
template <typename T>
MyVector<T>::MyVector(int maxsize)//构造函数
	:size(0),
	capacity(maxsize)
{
	this->m_data = new T[this->capacity];//申请空间
}
template <typename T>
MyVector<T>::~MyVector()//析构函数
{
	if(nullptr != this->m_data){
		delete[] this->m_data;
	}
}
template <typename T>
MyVector<T>::MyVector(int n,const T&value)//有参构造函数
	:size(n),
	capacity(n)
{
	this->m_data = new T[this->capacity]();//申请空间
	//赋值
	int i = 0;
	for(; i < this->size; i++){
		this->m_data[i] = value;
	}
}
template <typename T>
MyVector<T>::MyVector(const MyVector<T>& rhs)//拷贝构造函数
	:size(rhs.size),
	capacity(rhs.capacity),
	m_data(new T[rhs.capacity])
{
	//赋值
	int i = 0;
	for(; i < this->size; i++){
		this->m_data[i] = rhs.m_data[i];
	}
}
//添加元素
template <typename T>
void MyVector<T>::push_back(const T& value)
{
	if(this->size >= this->capacity){
		//扩容
		capacity += 0.5 * capacity;
		//申请新空间
		T* t_data = new T[capacity]();
		//拷贝原来空间的内容到新空间
		int i = 0;
		for(; i < this->size; i++){
			t_data[i] = this->m_data[i];
		}
		//释放原空间
		delete[] this->m_data;
		//指向新空间
		this->m_data = t_data;
	}
	this->m_data[this->size++] = value;
}
#endif