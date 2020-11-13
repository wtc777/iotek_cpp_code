#include<iostream>
using namespace std;
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>

int main(void)
{
	pid_t pid = fork();
	int i = 0;
	for(; i < 2; i++){
		if(pid == 0){//在子进程中再创建子进程
			cout<<"this is child proces--->"<<getpid()<<endl;
			if(i >= 1){
				while(1);//进程链末端死循环
				break;
			}
			pid = fork();
		}else if(pid > 0){//父进程等待回收子进程资源
			wait(0);
		}else{
			cerr<<"fork failed...";
		}
	}
	return 0;
}