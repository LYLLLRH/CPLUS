#define _CRT_SECURE_NO_WARNINGS
# include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct student {
	char number[20];
	char name[20];
	char age[20];
	char major[10];
	char sex[20];
}stu ;//学生信息结构体

typedef struct table {
	stu A;
	struct table* next;
}table, * linklist;//链表结构体

linklist createnode();//函数声明，只是为了顺序好看不得不在这个位置声明

///函数名：创造链表
///创造头节点，指针域为空
///参数：无
///返回值：头节点指针
linklist creatlist()
{
	linklist headnode = (linklist)malloc(sizeof(table));
	headnode->next = NULL;
	return headnode;

}

///函数名：创造节点
///新建一个节点
///参数：无
///返回值：新建节点指针
linklist createnode()
{
	linklist newnode = NULL;
	newnode = (linklist)malloc(sizeof(table));
	cout << "学号:" << endl;
	scanf("%s", &newnode->A.number); getchar();
	cout << "姓名:" << endl;
	scanf("%s", &newnode->A.name); getchar();
	cout << "年龄:" << endl;
	scanf("%s", &newnode->A.age); getchar();
	cout << "性别:" << endl;
	scanf("%s", &newnode->A.sex); getchar();
	cout << "专业:" << endl;
	scanf("%s", &newnode->A.major); getchar();
	cout << "录入成功" << endl;
	newnode->next = NULL;
	if (newnode == NULL) { cout<<"创建失败"; }
	return newnode;
}

//从头节点插入函数（倒序插入）(泛用性不如后面的任意节点插入，只做演示，不做实际用途）
//void insertnodebyhead(linklist headnode)
//{
//	linklist newnode = NULL;
//	newnode = new table;
//	cout << "学号:" << endl;
//	scanf("%s", &newnode->A.number); getchar();
//	cout << "姓名:" << endl;
//	scanf("%s", &newnode->A.name); getchar();
//	cout << "年龄:" << endl;
//	scanf("%s", &newnode->A.age); getchar();
//	cout << "性别:" << endl;
//	scanf("%s", &newnode->A.sex); getchar();
//	cout << "专业:" << endl;
//	scanf("%s", &newnode->A.major); getchar();
//	cout << "录入成功" << endl;
//	newnode->next = headnode->next;
//	headnode->next = newnode;
//}

//查询第i个节点的学生结构体(泛用性不如查询指针，只做演示，不做实际用途)
//stud getnode(linklist headnode, int i)
//{
//	linklist p = headnode->next;
//	int j = 1;
//	while (p && j < i)
//	{
//		p = p->next; ++j;
//	}
//	if (!p || j > i)return 0;
//	return &(p->A);
//}

///函数名:查询节点
///查询第i个节点的指针（可根据实际储存的数据类型更换）
///此函数用于插入函数嵌套，主函数中无作用
///参数：头节点headnode，节点位置i
///返回值：指针域指向第i个节点的节点的指针
linklist getnodep(linklist headnode, int i)
{
	linklist p = headnode->next;
	int j = 1;
	while (j < i)
	{
		p = p->next; ++j;
	}
	if (j > i){ cout << "输入值超出列表长度，请重试" << endl; return 0; }
	return p;
}

void printNode(linklist p);//函数声明，只是为了顺序好看不得不在这个位置声明
						   
/// 函数名:按姓名检索
/// 按照姓名查询学生，并输出学生所有信息
/// 参数：头节点指针headnode，学生姓名name
/// 返回值：无
void searchByName(linklist headnode,char name[])
{
	int judge=0;
	linklist node=headnode->next;
	while (node)
	{
		if (!strcmp(name,node->A.name))
		{
			printNode(node);
			judge = 1;
		}
		node = node->next;
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }
}

/// 函数名:按学号检索
/// 按照学号查询学生，并输出学生所有信息
/// 参数：头节点指针headnode，学生学号number
/// 返回值：无
void searchByNumber(linklist headnode, char number[])
{
	int judge=0;
	linklist node = headnode->next;
	while (node)
	{
		if (!strcmp(number, node->A.number))
		{
			printNode(node);
			judge = 1;
		}
		node = node->next;
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }

}

/// 函数名:按年龄检索
/// 按照年龄查询学生，并输出学生所有信息
/// 参数：头节点指针headnode，学生年龄age
/// 返回值：无
void searchByAge(linklist headnode, char age[])
{
	int judge=0;
	linklist node = headnode->next;
	while (node)
	{
		if (!strcmp(age, node->A.age))
		{
			printNode(node);
			judge = 1;
		}
		node = node->next;
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }
}

/// 函数名:按性别检索
/// 按照性别查询学生，并输出学生所有信息
/// 参数：头节点指针headnode，学生性别sex
/// 返回值：无
void searchBySex(linklist headnode, char sex[])
{
	int judge=0;
	linklist node = headnode->next;
	while (node)
	{
		if (!strcmp(sex, node->A.sex))
		{
			printNode(node);
			judge = 1;
		}
		node = node->next;
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }
}

/// 函数名:按专业检索
/// 按照专业查询学生，并输出学生所有信息
/// 参数：头节点headnode，学生专业major
/// 返回值：无
void searchByMajor(linklist headnode, char major[])
{
	int judge=0;
	linklist node = headnode->next;
	while (node)
	{
		if (!strcmp(major, node->A.major))
		{
			printNode(node);
			judge = 1;
		}
		node = node->next;
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }
}

/// 函数名:插入数据
/// 在任意位置插入节点
/// 参数：头节点headnode，节点位置i
/// 返回值：0或1
int insertnodenormal(linklist headnode,int i)
{
	linklist pnode;
	pnode = getnodep(headnode, i);
	linklist newnode = NULL;
	newnode = new table;
	cout << "学号:" << endl;
	scanf("%s", &newnode->A.number); getchar();
	cout << "姓名:" << endl;
	scanf("%s", &newnode->A.name); getchar();
	cout << "年龄:" << endl;
	scanf("%s", &newnode->A.age); getchar();
	cout << "性别:" << endl;
	scanf("%s", &newnode->A.sex); getchar();
	cout << "专业:" << endl;
	scanf("%s", &newnode->A.major); getchar();
	cout << "录入成功" << endl;
	newnode->next = pnode->next;
	pnode->next = newnode;
	return 1;
}

/// 函数名:输出链表
/// 输出链表的所有节点的值
/// 参数：头节点headnode
/// 返回值：无
void printlist(linklist headnode)
{
	linklist p = headnode->next;
	while (p)
	{
		cout << "名字" << p->A.name << endl;
		 cout << "学号"<<p->A.number<<endl; 
		 cout << "年龄"<<p->A.age<<endl; 
		 cout << "性别"<<p->A.sex<<endl; 
		 cout << "专业"<<p->A.major<<endl<<endl; 
		p = p->next;
	}
	cout << endl;
}

/// 函数名:输出节点
/// 输出单个节点的值
/// 参数：头节点headnode
/// 返回值：无
void printNode(linklist p)
{
	cout << "名字:" << p->A.name << endl;
	cout << "学号:" << p->A.number << endl;
	cout << "年龄:" << p->A.age << endl;
	cout << "性别:" << p->A.sex << endl;
	cout << "专业:" << p->A.major << endl << endl;
}

/// 函数名:删除结点
/// 删除节点
/// 参数：头节点headnode，节点位置i
/// 返回值：0或1
int deleteNode(linklist headnode, int i)
{
	linklist newnode=NULL,pnode=NULL;
	pnode = getnodep(headnode, i);
	if (pnode == NULL) { cout << "输入值超出列表长度，请重试" << endl; return 0; }
	newnode = pnode->next;
	pnode->next = newnode->next;
	free(newnode);
	cout << "已删除学生信息" << endl;
	return 1;
}

int main()
{
	int judge=0,listjudge=0,location;
	char sjudge[20];
	linklist a = creatlist();
	cout << "-1,停止操作" << endl << "1，创建学生列表" << endl << "2，插入学生信息" << endl << "3，删除学生信息" << endl << "4，查询学生信息（姓名）" << endl<< "5，查询学生信息（学号）" <<endl<< "6，查询学生信息（性别）" << endl<<"7，查询学生信息（年龄）" << endl<<"8，查询学生信息（专业）" << endl<<"9，打印所有学生信息"<<endl;
	while (judge != -1)
	{
		scanf("%d", &judge); getchar();
		switch (judge)
		{
		case 1:if (listjudge == 1) { cout << "学生列表已经创建" << endl; break; }a->next = createnode(); listjudge = 1; break;
		case 2:cout << "请输入插入信息的位置:" << endl; scanf("%d", &location); getchar(); insertnodenormal(a, location - 1); break;
		case 3:cout << "请输入删除信息的位置:" << endl; scanf("%d", &location); getchar(); deleteNode(a, location-1); break;
		case 4:cout << "请输入学生姓名:" << endl; scanf("%s", &sjudge); getchar(); searchByName(a, sjudge); break;
		case 5:cout << "请输入学生学号:" << endl; scanf("%s", &sjudge); getchar(); searchByNumber(a,sjudge); break;
		case 6:cout << "请输入学生性别:" << endl; scanf("%s", &sjudge); getchar(); searchBySex(a, sjudge); break;
		case 7:cout << "请输入学生年龄:" << endl; scanf("%s", &sjudge); getchar(); searchByAge(a, sjudge); break;
		case 8:cout << "请输入学生专业:" << endl; scanf("%s", &sjudge); getchar(); searchByMajor(a, sjudge); break;
		case 9:cout << "全部学生信息如下：" << endl; printlist(a); break;
		case -1:cout << "操作停止"<<endl; break;
		default: cout << "无效输入" << endl; break;
		}
	}
}