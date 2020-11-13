#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(void)
{
	int i = 0;
	pid_t pid = fork();
	if(pid > 0){
		//父进程打印5次
		for(i = 0; i < 5; i++){
			cout<<"i am parent process"<<endl;
			sleep(1);
		}
	}else if(pid == 0){
		//子进程打印3次
		for(i = 0; i < 3; i++){
			cout<<"i am child process"<<endl;
			sleep(1);
		}
	}else{
		cerr<<"fork failed..."<<endl;
	}
	return 0;
}