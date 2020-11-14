#include<iostream>
using namespace std;
#include<pthread.h>
#include<unistd.h>
#include<fstream>

struct FileOpe{
	ofstream outfile;
	int flag;//flag=0 main 打开文件，flaf != 0子线程写入字符串到文件
		pthread_mutex_t mutex;
};

void* pthread_start(void* arg)
{
	struct FileOpe* ope = static_cast<struct FileOpe*>(arg);
	while(1){
		pthread_mutex_lock(&ope->mutex);
		while(!ope->flag){
			pthread_mutex_unlock(&ope->mutex);
			usleep(100);
			pthread_mutex_lock(&ope->mutex);
		}
		//想文件中写入字符串"hello"
		if(++ope->flag > 20) break;
		ope->outfile<<"hello"<<endl;
		sleep(1);
		pthread_mutex_unlock(&ope->mutex);
	}
	return static_cast<void*>(nullptr);
}

int main(void)
{
	struct FileOpe ope;
	ope.flag = 0;
	
	pthread_t tid;
	pthread_create(&tid, nullptr, pthread_start, &ope);
	pthread_mutex_init(&ope.mutex,nullptr);
	
	pthread_mutex_lock(&ope.mutex);
	while(ope.flag){
		pthread_mutex_unlock(&ope.mutex);
		usleep(100);
		pthread_mutex_lock(&ope.mutex);
	}
	
	//打开文件
	ope.outfile.open("test.txt");
	if(!ope.outfile){
		cerr<<"file open failed...";
		pthread_mutex_unlock(&ope.mutex);
		pthread_exit(nullptr);
	}
	ope.flag = 1;
	pthread_mutex_unlock(&ope.mutex);
	
	pthread_join(tid, nullptr);
	ope.outfile.close();//关闭文件
	return 0;
}