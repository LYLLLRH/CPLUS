#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


//定义单个节点
typedef struct Qnode {
	int data;
	struct Qnode* next;
}Qnode, * queuePtr;

//定义队列
typedef struct queue {
	Qnode* front;
	Qnode* rear;
	int size;
}queue;

/// 函数名:创建节点
/// 创建单个节点
/// 参数：节点数据data
/// 返回值：节点指针newnode
struct Qnode* creatnode(int data)
{
	struct Qnode* newnode = (Qnode*)malloc(sizeof(struct Qnode));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

/// 函数名:创建队列
/// 创建队列
/// 参数：无
/// 返回值：头节点指针quueInit
struct queue* createQueue()
{
	struct queue* queueInit = (queue*)malloc(sizeof(struct queue));
	queueInit->front = queueInit->rear = NULL;
	queueInit->front = creatnode(0);
	queueInit->size = 0;
	return queueInit;
}

/// 函数名:插入
/// 队尾插入元素
/// 参数：头节点指针queue，节点数据data
/// 返回值：无
void insert(queue* Q, int data)
{
	struct Qnode* newnode = creatnode(data);
	if (Q->size == 0)
	{
		Q->rear = newnode;
		Q->front->next = newnode;
	}
	else
	{
		Q->rear->next = newnode;
		Q->rear = newnode;
	}
	Q->size++;
}

/// 函数名:退出
/// 队首取出元素数据
/// 参数：头节点指针queue
/// 返回值：节点数据a
int quit(queue* Q)
{
	struct Qnode* q;
	int a;
	if (Q->front == Q->rear) return NULL;
	q = Q->front->next;
	a = q->data;
	Q->front->next = q->next;
	if (Q->rear == q) Q->rear == Q->front;
	free(q);
	Q->size--;
	return a;
}

/// 函数名:打印队列
/// 打印队列全部元素
/// 参数：头节点指针queue
/// 返回值：无
void printQueue(struct queue* Q)
{
	struct Qnode* q = Q->front;
	while (q)
	{
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;
}




int main()
{
	struct queue* newqueue = createQueue();
	int i=1,judge=0;
	cout << "请选择功能" << endl << "1，取号" << endl << "2，查看队列" << endl << "3,退出系统" << endl<< "4，模拟功能：令队首客户服务结束" << endl;
	while (judge != 3)
	{
		scanf("%d", &judge); getchar();
		switch (judge)
		{
		case 1:insert(newqueue, i); cout << "您的号码是：" << i<<endl; i++; break;
		case 2:if (newqueue->size == 0) { cout << "无人排队中，若需服务请先取号" << endl; break; }
			   if (newqueue->size == 1) { cout << "目前队列中有1位客户" << endl; cout << "正在服务：第" << newqueue->front->next->data << "号客户，若需服务请先取号" << endl; break; }
			   cout << "目前队列中有" << newqueue->size << "位客户"<<endl; 
			   cout << "正在服务：第" << newqueue->front->next->data << "号客户,请第" << newqueue->front->next->next->data << "号客户准备" << endl; break;
		case 3:cout<<"已退出系统" << endl; break;
		case 4:if (newqueue->size == 0) { cout << "无人排队中，此功能无效，别故意找茬" << endl; break; }
			  cout << "第"<<newqueue->front->next->data<<"位客户已服务结束" << endl;quit(newqueue); break; 
		default: cout << "无效输入" << endl; break;
		}
	}
}