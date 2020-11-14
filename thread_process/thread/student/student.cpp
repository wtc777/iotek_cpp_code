#include<iostream>
using namespace std;
#include<pthread.h>

typedef struct Student{
	int id;
	char name[20];
	float score;
}Stu;

void* Printstu(void* arg)
{
	Stu* stu = (Stu*)arg;
	cout<<"this is child process:"<<pthread_self()<<endl;
	
	cout<<"id:"<<stu->id<<endl;
	cout<<"name:"<<stu->name<<endl;
	cout<<"score:"<<stu->score<<endl;
	return (void*)"thread ended...";
}

int main(void)
{
	Stu jack = {1, "jack" , 98.5};
	cout<<"this is main process:"<<pthread_self()<<endl;
	pthread_t thid;
	pthread_create(&thid, nullptr, Printstu, &jack);
	void* rst = nullptr;
	pthread_join(thid, (void**)&rst);
	cout<<"thread return value:"<<(char*)rst<<endl;
	return 0;
}