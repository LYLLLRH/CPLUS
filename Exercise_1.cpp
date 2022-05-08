#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
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

}stu;//学生信息结构体

/// 函数名:创建学生信息
/// 创造单个学生的个人信息
/// 参数：学生A
/// 返回值：无
void createInfo(stu &studentA)
{
	char number[20], name[20], age[20], major[10], sex[20];
	cout << "学号:" ; scanf("%s", studentA.number); getchar();
	cout << "姓名:" ; scanf("%s", studentA.name); getchar();
	cout << "年龄:" ; scanf("%s", studentA.age); getchar();
	cout << "性别:" ; scanf("%s", studentA.sex); getchar();
	cout << "专业:" ; scanf("%s", studentA.major); getchar();
	cout << "录入成功" << endl;
}

/// 函数名:输出节点信息
/// 输出单个节点的学生的全部信息
/// 参数：学生A
/// 返回值：无
void printNode(stu A)
{

	cout << "名字:" << A.name << endl;
	cout << "学号:" << A.number << endl;
	cout << "年龄:" << A.age << endl;
	cout << "性别:" << A.sex << endl;
	cout << "专业:" << A.major << endl << endl;
}

/// 函数名:按姓名检索
/// 按照姓名查询学生，并输出学生所有信息
/// 参数：向量组A，学生姓名name
/// 返回值：无
void searchByName(vector<stu> A,char name[])
{
	int i, j,judge=0;
	j = A.size();
	for (i = 0; i < j; i++)
	{
		if (!strcmp(name, A[i].name))
		{
			printNode(A[i]);
			judge = 1;
		}
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }
}

/// 函数名:按学号检索
/// 按照学号查询学生，并输出学生所有信息
/// 参数：向量组A，学生学号number
/// 返回值：无
void searchByNumber(vector<stu> A, char number[])
{
	int i, j, judge = 0;
	j = A.size();
	for (i = 0; i < j; i++)
	{
		if (!strcmp(number, A[i].number))
		{
			printNode(A[i]);
			judge = 1;
		}
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }
}

/// 函数名:按性别检索
/// 按照性别查询学生，并输出学生所有信息
/// 参数：向量组A，学生性别sex
/// 返回值：无
void searchBySex(vector<stu> A, char sex[])
{
	int i, j, judge = 0;
	j = A.size();
	for (i = 0; i < j; i++)
	{
		if (!strcmp(sex, A[i].sex))
		{
			printNode(A[i]);
			judge = 1;
		}
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }
}

/// 函数名:按年龄检索
/// 按照年龄查询学生，并输出学生所有信息
/// 参数：向量组A，学生年龄age
/// 返回值：无
void searchByAge(vector<stu> A, char age[])
{
	int i, j, judge = 0;
	j = A.size();
	for (i = 0; i < j; i++)
	{
		if (!strcmp(age, A[i].age))
		{
			printNode(A[i]);
			judge = 1;
		}
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }
}

/// 函数名:按专业检索
/// 按照专业查询学生，并输出学生所有信息
/// 参数：向量组A，学生专业major
/// 返回值：无
void searchByMajor(vector<stu> A, char major[])
{
	int i, j, judge = 0;
	j = A.size();
	for (i = 0; i < j; i++)
	{
		if (!strcmp(major, A[i].major))
		{
			printNode(A[i]);
			judge = 1;
		}
	}
	if (judge == 0) { cout << "找不到指定学生" << endl; }
}

/// 函数名:输出向量组信息
/// 输出整个向量组全部的学生的全部信息
/// 参数：向量组A
/// 返回值：无
void printList(vector<stu> A)
{
	int i,j;
	j = A.size();
	for (i = 0; i<j ; i++)
	{
		cout << "名字:" << A[i].name << endl;
		cout << "学号:" << A[i].number << endl;
		cout << "年龄:" << A[i].age << endl;
		cout << "性别:" << A[i].sex << endl;
		cout << "专业:" << A[i].major << endl << endl;
	}
}

int main()
{
	int judge = 0,location ,location3;//两个位置量和一个存储键盘输入的变量
	char sjudge[20];//用于搜索的比较量
	vector<stu> students;
	vector<stu>::iterator location2;
	stu student;
	cout << "-1,停止操作" << endl << "1，创建学生列表" << endl << "2，增加学生信息" << endl << "3，插入学生信息" << endl<< "4，删除学生信息" << endl << "5，查询学生信息（姓名）" << endl << "6，查询学生信息（学号）" << endl << "7，查询学生信息（性别）" << endl << "8，查询学生信息（年龄）" << endl << "9，查询学生信息（专业）" << endl << "10，打印所有学生信息" << endl;
	while (judge != -1)
	{
		scanf("%d", &judge); getchar();
		switch (judge)
		{
		case 1:cout << "学生列表已创建" << endl << "列表长度:" << students.size() << endl; break;
		case 2:cout << "请输入学生信息:" << endl; createInfo(student); students.push_back(student);  break;
		case 3:cout << "请输入插入信息的位置:"; scanf("%d", &location); getchar(); if (location > students.size()) { cout << "输入数值超出长度" << endl; break; }createInfo(student); students.insert(students.begin() + (location - 1), student); break;
		case 4:cout << "1,批量删除" << endl<< "2，个别删除" << endl; 
			   scanf("%d", &judge); getchar(); 
			   switch (judge)
			   {
			   case 1:cout << "请输入删除信息的起始位置:"; scanf("%d", &location); getchar(); cout << "请输入删除信息的结束位置:"; scanf("%d", &location3); getchar(); students.erase(students.begin() + (location - 1), students.begin() + location3); break;
			   case 2:cout << "请输入删除信息的位置:" ; scanf("%d", &location); getchar(); students.erase(students.begin() + (location - 1), students.begin() + location); break;
			   default:cout << "操作停止" << endl; break;
			   }
			   cout << "删除成功" << endl;break;
		case 5:cout << "请输入学生姓名:" ; scanf("%s", &sjudge); getchar(); searchByName(students, sjudge); break;
		case 6:cout << "请输入学生学号:" ; scanf("%s", &sjudge); getchar(); searchByNumber(students, sjudge); break;
		case 7:cout << "请输入学生性别:" ; scanf("%s", &sjudge); getchar(); searchBySex(students, sjudge); break;
		case 8:cout << "请输入学生年龄:" ; scanf("%s", &sjudge); getchar(); searchByAge(students, sjudge); break;
		case 9:cout << "请输入学生专业:" ; scanf("%s", &sjudge); getchar(); searchByMajor(students, sjudge); break;
		case 10:cout << "全部学生信息如下："<<endl; printList(students); break;
		case -1:cout << "操作停止" << endl; break;
		default: cout << "无效输入" << endl; break;
		}
	}
}
