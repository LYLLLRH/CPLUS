#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct table {
	int data;
	string c;
	struct table* next;
}table, * linklist;//栈（链表实现）定义

/// 函数名：计算
/// 用于进制转换的计算，利用递归
/// 对于一个数a,不断对于对应进制k进行取余运算，最后倒序输出余数就是对应进制的值
/// 参数：链表节点，待转换数字a，进制k
/// 返回值：无
void caculate(linklist pnode,int a,int k)
{
	int b,c;
	linklist newnode = NULL;
	newnode = new table;
	newnode->next = NULL;
	pnode->next = newnode;
	if (newnode == NULL) { cout << "创建失败"; }
	if (a != 0) 
	{	
		c = a % k;
		switch (c)
		{
		case 10:newnode->c = "A"; newnode->data = -1; b = (a - (a % k)) / k; caculate(newnode, b, k); break;
		case 11:newnode->c = "B"; newnode->data = -1; b = (a - (a % k)) / k; caculate(newnode, b, k); break;
		case 12:newnode->c = "C"; newnode->data = -1; b = (a - (a % k)) / k; caculate(newnode, b, k); break;
		case 13:newnode->c = "D"; newnode->data = -1; b = (a - (a % k)) / k; caculate(newnode, b, k); break;
		case 14:newnode->c = "E"; newnode->data = -1; b = (a - (a % k)) / k; caculate(newnode, b, k); break;
		case 15:newnode->c = "F"; newnode->data = -1; b = (a - (a % k)) / k; caculate(newnode, b, k); break;
		default:newnode->data = c;b = (a - (a % k)) / k;caculate(newnode, b, k);break;
		}
	 }
}

/// 函数名：建立链表
/// 用于建立链表头节点
/// 参数：无
/// 返回值：链表头节点
linklist creatlist()
{
	linklist headnode = (linklist)malloc(sizeof(table));
	headnode->next = NULL;
	return headnode;

}

/// 函数名：清除
/// 用于清除被占用的空间，防止可能出现的内存泄露
/// 参数：链表节点
/// 返回值：无
void clear(linklist headnode)
{
	linklist p = headnode;
	while (!(p->next==NULL))
	{
		linklist newnode = NULL;
		newnode = p->next;
		p->next = newnode->next;
		free(newnode);
	}
}

/// 函数名：输出链表
/// 用于倒序输出链表中的值
/// 参数：链表节点
/// 返回值：无
void printlist(linklist pnode)
{
	if (!(pnode->next==NULL))
	{
		printlist(pnode->next);
		if (pnode->data == -1)
		{
			cout << pnode->c;
		}
		else
		{
			cout << pnode->data;
		}
	}
}

int main()
{
	int base, number,judge=0;
	linklist a = creatlist();
	cout << "输入-1以中止转换" << endl;
	while (1)
	{
		cout << "请输入要转换的数:"; cin >> number;
		cout << "请输入要转换到的进制(2-16):"; cin >> base;
		if (base > 16) { cout << "输入进制超出范围" << endl; continue; }
		if (number == -1 || base == -1) { break; }
		caculate(a, number, base);
		cout << "对应" << base << "进制的数为:";
		printlist(a->next);
		cout << endl;
	}
}