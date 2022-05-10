##  Json in C++

C++ Json 有几十种的Json库，在这里采用最流行的`nlohmann`为主开发的Json库。
这个Json的库在 [nlohmann json](https://github.com/nlohmann/json.git)

#### 在Visual Studio 的使用

支持的版本有

- Visual Studio 2015, 2017, 2019, 2022

1. git clone https://github.com/LYLLLRH/CPLUS (如果没有装git，也可以通过Cooy文件的方式)
2. 拷贝JOSN 下`nlohmann` 这个目录到项目主文件的目录下，这个目录下面有个后缀为hpp的文件

> hpp后缀,其实质就是将.cpp的实现代码混入.h头文件当中，定义与实现都包含在同一文件，则该类的调用者只需要include该hpp文件即可，无需再将cpp加入到project中进行编译。而实现代码将直接编译到调用者的obj文件中，不再生成单独的obj,采用hpp将大幅度减少调用 project中的cpp文件数与编译次数，也不用再发布烦人的lib与dll,因此非常适合用来编写公用的开源库。

3. 在项目的主程序加入如下命令
```
#include "./nlohmann/json.hpp"
using json = nlohmann::json;
```
然后就可以用，如下命令定义json的实例
```
json t;
t["name"] = "Micheal Zhang";
t["age"] = 20 ;
t["sex"] = "Male";
t["major"] = "CS";

cout << t["name"] << endl;
cout << t;
```
完整的使用方法和例子，可以参考如下[网站](https://programming.vip/docs/c-json-library-nlohmann-simple-use-tutorial.html)

#### 在Docker 环境中测试

1. Docker 生成文件（已经生成）
```
FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o myapp -lstdc++ -std=c++11 json_exercise_1.cpp
CMD ["./myapp"]
```

2. 在JSON目录下，运行如下命令，在本地生成Docker 镜像
```
docker build -t myapp:1.1 .
```
3. 运行如下命令，进行测试
```
docker run -it --rm myapp:1.1 
```