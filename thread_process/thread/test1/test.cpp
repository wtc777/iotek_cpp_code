#include<iostream>
using namespace std;
#include<unistd.h>
#include<pthread.h>
#include<cstdio>

typedef struct Resource{
	int value;//value<=3 main 挂起，child工作，value>3两线程工作
	pthread_mutex_t mutex;
}Resrc;

void* thread_start(void* arg)
{
	Resrc* data = static_cast<Resrc*>(arg);
	while(1){
		if(data->value > 20)break;//子线程结束条件
		pthread_mutex_lock(&data->mutex);//加锁
		printf("(child):%lu:value:%d\n",pthread_self(), ++ data->value);
		pthread_mutex_unlock(&data->mutex);//释放锁
		usleep(100);
	}
	return static_cast<void*>(nullptr);
}

int main(void)
{
	Resrc data;
	data.value = 0;
	pthread_mutex_init(&data.mutex,nullptr);
	
	pthread_t tid;
	pthread_create(&tid, nullptr, thread_start, &data);
	
	while(1){
		if(data.value > 20) break;
		while(data.value <= 3) continue;
		pthread_mutex_lock(&data.mutex);//加锁
		printf("(main):%lu;value:%d\n",pthread_self(), ++data.value);
		pthread_mutex_unlock(&data.mutex);//释放锁
		usleep(100);
	}
	pthread_join(tid, nullptr);
	return 0;
}