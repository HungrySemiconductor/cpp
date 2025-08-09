# 1 简要介绍

> 课程来源：[快速学习C和C++——南方科技大学于仕琪副教授](https://www.bilibili.com/video/BV1Vf4y1P7pq/?spm_id_from=333.788.videopod.episodes&vd_source=dd2b7c41f54e83182372ee62c303b855)

> 本课重点：
>
> - 指针和内存管理
>
> 课程特点：
>
> - 如何提升程序效率，提速算法
>
> - 介绍OpenCV采用C++特性设计cv::Mat类
>
> - 介绍ARM开发

---

## 1.1 编译与链接

- 编译与链接之间的关系

  >`-c `：将 `.cpp` 文件输出为 `.o` 或 `.obj` 的目标文件
  >
  >当项目有多个源文件时，可以单独编译每个文件，再统一链接
  >
  >修改一个文件时只需单独重新编译该文件即可，提升效率

  >`-o` ：将多个 `.o` 文件和库合并为可执行文件
  >
  >避免默认名称冲突，其后必须紧跟输出文件名

<img src=".\images\image-20250807184945244.png" alt="image-20250807184945244" style="zoom: 67%;" />

- VSCode添加编译器

  > 终端使用 ` WSL:Ubuntu-20.4` 而不是 `PowerShell`，主要是想练习最近学习的 `Linux` 命令

  > 首先在 `VSCode` 中安装扩展 `WSL` ，使之完全运行在  `WSL` 独立的 `Linux` 环境中
  >
  > 由于 `VSCode` 扩展分为本地 ` Windows` 和远程 `WSL` 两种模式，所以需要重新添加扩展`C/C++`、`C/C++ Extension Pack`、`C/C++ Themes` 
  >
  > `sudo update` 输入用户密码后，更新软件列表
  >
  > `sudo apt install g++ make` 安装编译工具
  >
  > `g++ --version` 和 `make --version` 验证安装
  >
  > 版本分别为 `g++ (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0` 和 `GNU Make 4.2.1 Built for x86_64-pc-linux-gnu`

  > 终端字太小了，使用 `Ctrl+,` 打开设置，使用 `terminal integrated: font size` 调整大小为合适值

- 第一次编译

  > 文件：main.cpp mul.cpp mul.hpp
  >
  > 编译：`g++ -c main.cpp mul.cpp`
  >
  > 链接：`g++ main.o mul.o  -o mul `
  >
  > 执行：`./mul`

  > 为什么使用 `./mul`  而不可以直接使用 `mul`
  >
  > Linux/WSL系统中默认不会自动搜索当前目录，而是从 `/user/bin/` 中查找命令
  >
  > 必须执行时明确告诉系统程序的位置  `./` 表示“当前目录”

## 1.2 Makefile管理和编译

- 使用原因

  >文件过多时单独手动编译非常耗时

  >通过 `Makefile` 这个公用的格式写的脚本，可以在终端仅用一条命令自动更新编译和链接

- 使用方法

  >文件名称：`Makefile`
  
  ```makefile
  CXX = g++		# 编译器名称
  TARGET = fileName	# 可执行文件名称
  SRC = $(wildcard *.cpp)					# .cpp文件	
  OBJ = $(patsubst %.cpp, %.o, $(SRC))	# .o文件，由.cpp文件编译而来的
  
  CXXFLAGS = -c -Wall		# 编译选项，显示所有警告
  
  $(TARGET): $(OBJ)		# 目标文件链接成可执行文件
  	$(CXX) -o $@ $^
  
  %.o: %.cpp				# 每个.cpp文件转换为对应的.o文件
  	$(CXX) $(CXXFLAGS) $< -o $@
  
  .PHONY: clean	# 防止存在clean重名文件
  clean:
  	rm -f *.o $(TARGET)
  ```

## 1.3 报错原因

- 3种报错

  > 编译时报错：大多是由于语法错误
  >
  > 链接时报错：可能是函数名称大小写不一致
  >
  > 执行时报错：没有考虑到公式中不合理的情况，如除数为0

## 1.4 预处理和宏

- 预处理器处理预处理指令，例如define、include等，编译器不处理该指令
- 宏由define定义，将文本进行替换，编译器读到该文本时则替换为对应内容

<img src=".\images\image-20250807201841260.png" alt="image-20250807201841260" style="zoom:50%;" />

<img src="E:\Typora\Typora\coding-study\image-20250807201916788.png" alt="image-20250807201916788" style="zoom:50%;" />



## 1.5 命令行输入

- 完整的 `main` 函数有两个参数，通过命令行输入参数

  > `argc`：命令行输入的参数个数，是一个整数
  >
  > `*argv[]或**argv`：命令行输入的参数值，是一个数组

---

# 2 数据运算

## 2.1 整数

- 变量初始化

  > `int a = 10`
  >
  > 变量一定要明确地初始化
  >
  > 如果不初始化定义，程序也不会报错，但不同平台下得到的输出结果将会不同
  >
  > `char` 也是一种整数，只不过是1字节/8位，`int` 是4字节/32位

- 数值溢出 `overflow`

  > 数值运算时，要注意其取值范围

  >`signed int`：有符号类型整数，通常直接写为 `int` ，首位（最高位）为符号位，31位数值位。当两个较大整数相乘时，如果首位填满，则会得到负值，影响输出结果
  >
  >`unsigned int`：无符号类型，32位数值位

- `sizeof` 操作符查看变量长度

  >`sizeof` 是一个操作符，而不是函数
  >
  >函数的参数必须是变量，而 `sizeof` 的参数可以是 `变量/int/shrot/long/...`
  >
  >`cout << "sizeof(int)=" << sizeof(int) << endl;`

- `size_t` 

  > 特点：无符号类型，永远是正数；足够大，内存有多大就可以表示多大
  >
  > 使用：数个数防止溢出；表示内存大小

## 2.2 浮点数

- 采样精度

  > float一般不进行直接相等比较，而是使用 `if(fabs(f1-f2)<FLT_EPSILON)`，差是否小于一个无穷小值进行判断
  >
  > float和int都是32位，但由于小数能够表示的范围更多，所以float值并不是绝对精确的
  >
  > float运算时要注意，当给float数值非常大，增量很小时，float会忽略增量

## 2.3 数值操作

- 常数表示

  > `const`：表示常数，可以替代宏定义，一旦变量类型定义后不可修改类型 `const float PI=3.14159f`
  >
  > `auto`：根据赋值自动生成类型，生成类型后也不可以修改类型 `auto a=2 //int` 
  >
  > `int/double`：数值后不带符号，默认为这两种类型
  >
  > `float/long/unsigned long`：数值后必须要写符号，符号分别为 `f/l/ul`

- 算数运算

  >搞不清优先级就用括号

- 数据转换

  > 小长度转换为大长度，数据不会丢失
  >
  > 大长度转换为小长度，数据会丢失
  >
  > 当数值量很大时，`int1->float->int2`，转换结果 `int1≠int2`

  <img src=".\images\image-20250808135528017.png" alt="image-20250808135528017" style="zoom: 67%;" />

- 除法运算

  > 两个整数相除，结果可能为小数，但由于两个整数后无符号，默认都是 `int`类型，结果将舍去小数部分
  >
  > 两个整数相除，其中任何一个整数后带符号 `f` 声明为浮点类型，结果就会保留小数部分

  <img src=".\images\image-20250808135045632.png" alt="image-20250808135045632" style="zoom: 67%;" />

# 3 分支循环

## 1.1 条件语句

- 条件

  > **条件** 就是 **可以转换为bool型的表达式**，如果不是bool会先转换为 `bool`，例如（-2）就是 `True` 值
  >
  > 关系表达式：用关系运算符（等于、大于、小于...）比大小的结果：`True/False`
  >
  > 逻辑表达式：用逻辑运算符（取反 `！`、与 `&&`、或 `||`）算出的结果：`True/Flase`

<img src="D:\GitHub\cpp\images\image-20250809110918338.png" alt="image-20250809112944503" style="zoom: 33%;" />



## 1.2 循环语句

- `while` 循环
- `for` 循环

- 退出循环

  >`break`：退出当前循环，并终止循环
  >
  >`continue`：退出当前循环，进入下一次循环

- `goto` 跳转

  > 跳到 `goto` 所指向的位置执行，一般用作 `EXIT_ERROR`

- `switch-case` 语句

  > `case <xxx>` 并不是 `if` 条件判断，而是`label` 标签

