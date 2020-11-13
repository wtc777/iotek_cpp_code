#include<iostream>
using namespace std;
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>

int main(void)
{
	int i = 0;
	pid_t pid;
	for(; i < 3; i++){
		pid = fork();
		if(pid == 0){
			cout<<"this is child process--->"<<getpid()<<endl;
			while(1);
		}else if(pid < 0){
			cerr<<"fork failed..."<<endl;
		}
	}
	if (pid > 0){
		//父进程
		for(i = 0; i < 3; i++){
			wait(0);//父进程等待回收子进程资源
		}
	}
	return 0；
}