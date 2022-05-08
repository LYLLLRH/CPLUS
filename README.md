### C++ 题目

**题目**
![题目](题目.png)

**解答**
1. Excerse_1.cpp : 学生信息管理系统（顺序表）
2. Excerse_2.cpp : 学习信息管理系统（链表）
3. Excerse_3.cpp : 进制转换（链表实现）
4. Excerse_4.cpp : 银行排队系统

**运行**
1. 首先需要安装docker，[Docker](//www.docker.com)
2. 进入此项目的根目录
3. 运行如下命令，进行编译
```
docker build -t myapp:1.0 .
```
4. 编译成功后，运行如下命令进行测试
```
docker run -it --rm --name running-app myapp:1.0
```
