#include<iostream>
using namespace std;
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<cstring>
#include<cstdlib>

typedef struct Mystring{
	char Datastr[256];
	int flag;//flag=0可以录入字符串|flag=1可以统计字符数
	pthread_mutex_t mutex;//互斥锁
}Str;

void* pthread_start(void* arg)
{
	Str* data = static_cast<Str*>(arg);
	while(1){
		pthread_mutex_lock(&data->mutex);//加锁
		while(!data->flag){//禁止统计字符数时，让出时间片
			pthread_mutex_unlock(&data->mutex);
			usleep(100);
			pthread_mutex_lock(&data->mutex);
		}
		printf("字符串数量:%d\n",strlen(data->Datastr));
		data->flag = 0;
		if(strncmp(data->Datastr,"end",3) == 0){
			pthread_mutex_unlock(&data->mutex);
			break;//结束子线程条件
		}
		pthread_mutex_unlock(&data->mutex);
	}
	return static_cast<void*>(nullptr);
}

int main(void)
{
	Str data;
	memset(&data,0, sizeof(Str));
	//互斥锁初始化
	pthread_mutex_init(&data.mutex, nullptr);
	data.flag = 0;
	//开启子线程
	pthread_t tid;
	pthread_create(&tid, nullptr, pthread_start, &data);
	
	while(1){
		pthread_mutex_lock(&data.mutex);
		while(data.flag){//禁止输入字符串时，让出时间片
			pthread_mutex_unlock(&data.mutex);
			usleep(100);
			pthread_mutex_lock(&data.mutex);
		}
		printf("请输入字符串:");
		scanf("%s",data.Datastr);
		data.flag = 1;
		if(strncmp(data.Datastr, "end", 3) == 0){
			pthread_mutex_unlock(&data.mutex);
			break;//结束进程条件
		}
		pthread_mutex_unlock(&data.mutex);
	}
	pthread_join(tid, nullptr);
	return 0;
	return 0;
}
