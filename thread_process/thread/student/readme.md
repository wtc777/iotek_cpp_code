创建子线程
定义一个结构体变量
struct student
{
	int id;
	char name[20];
	float score;
};
将结构体变量通过传参的方式传入子线程，
在子线程中打印这个结构体的内容，
子线程退出的时候给主线程一个返回值，
主线程接收返回值并打印