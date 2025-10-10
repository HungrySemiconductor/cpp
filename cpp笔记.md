# 1 简要介绍

> 课程来源：[C/C++基础语法与优化策略——南方科技大学于仕琪副教授](https://www.bilibili.com/video/BV1Vf4y1P7pq/?spm_id_from=333.788.videopod.episodes&vd_source=dd2b7c41f54e83182372ee62c303b855)

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

  > 终端字太小了，使用 `Ctrl+`， 打开设置，使用 `terminal integrated: font size` 调整大小为合适值

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

- **`sizeof` 操作符查看变量长度**

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

<img src=".\images\image-20250809110918338.png" alt="image-20250809112944503" style="zoom: 33%;" />



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

# 4 数据类型

## 4.1 数组

- 数组性质

> **c++中数组是一段连续的内存，数组名就是一个指针（指向数组首地址），数组下标就是指针偏移量**
>
> 数组一定要进行初始化，否则输出是随机值
>
> 初始化个数小于数组下标值时，未初始化的其他元素为0

> **c/c++中数组元素的读写不检查是否越界**
>
> 优点：执行效率高，省去每次读写的检查步骤
>
> 缺点：容易出错

<img src=".\images\image-20250810145430576.png" alt="image-20250810145430576" style="zoom:50%;" />

- 未知长度的数组

  > 向函数中传入数组：数组的首地址+数组的长度
  >
  > `float array_sum(float values[], size_t length)`;
  >
  > `float array_sum(float *values, size_t length);`

- 二维数组

  >**二维数组定义时一定要给出列长度**
  >
  >计算机使用连续内存存储数组，需要列数来确定一行的结束，即从哪里开始下一行

- 常量数组

  >**数组前的const固定了数组的长度和内容不可改变**
  >
  >一般用于仅读取数组的情况，防止误操作篡改数组

## 4.2 字符串

- 数组分割字符串

  > **数组字符串最后一定要以 `\0` 结尾，否则可能会引发越界，直到碰到 `\0` 为止**

  > 注意区分 `sizeof` 和 `strlen` ！！！！！！
  >
  > `sizeof`：返回整个数组的字节大小，元素数量x每个元素大小，与初始化值无关，仅表示占用内存大小
  >
  > `strlen`：返回字符串的字符长度，直到遇到 `\0` 为止，仅用于字符串

- 常量字符串

  > 使用连续的字节存储，`char` 为1个字节，每一个字符都是一个 `char`，最后都以 `\0` 结尾

  ![image-20250810171251188](.\images\image-20250810171251188.png)

  > `strcpy`：复制字符串
  >
  > > `strncpy`：将一个字符串的前 n 个字符复制到另一个字符串中。
  > >
  > > 当源字符串的长度小于 n 时，目标字符串的剩余部分将用空字节填充。由于 **strncpy** 不会自动添加空字符，使用时应确保目标字符串足够大，以容纳 n 个字符和一个额外的空字符。这可以通过将 n 设置为目标数组大小减一，并在数组最后一个元素设置为空字符来实现。
  > >
  > > 这样可以确保即使源字符串长度超过目标数组大小，也**不会导致缓冲区溢出**，同时保证了字符串正确结束。
  > >
  > > `strncpy(dest, src, sizeof(dest) - 1);`
  > >
  > > ``dest[sizeof(dest) - 1] = '\0'`
  >
  > `strcat`：连接字符串
  >
  > `strcmp`：比较大小，第一个字符的编码值大小，True输出正值，False输出负值

- 字符串类

  > 同样没有越界安全检查，提升效率的同时，也会增加风险，重要在于程序员是否清楚操作

  <img src=".\images\image-20250810173033794.png" alt="image-20250810173842366" style="zoom:67%;" />

## 4.3 其他类型

- 结构体

  > 不同的数据类型放在一起成为一个新的数据类型，**括号外要带分号**
  >
  > 一般将结构体放在主函数外
  >
  > 为**内存对齐提高访问效率**，数据存储需要是4的倍数，不足的要补齐

  > **大小端指的是存储顺序**
  >
  > 大端存储：**高位字节在前**（低地址存高位），网络协议（如 TCP/IP）、Java 虚拟机默认使用大端序
  >
  > 小端存储：**低位字节在前**（低地址存低位），x86/x64、ARM（默认小端）等常用 CPU 使用小端序

  <img src="E:\Typora\Typora\coding-study\Snipaste_2025-08-10_17-58-30.png" style="zoom: 67%;" />

- 联合体

  > 联合体里成员共享一个内存，多个变量时所占内存以最大的变量的长度为准
  >
  > 例如 `ipv4` 地址既可以表示为 `32bits` ，也可以用 `4bytes` 表示
  >
  > **使用字符串类std::xxx时，赋值将被认为是字符串，如果需要输出数字，必须使用+进行强制转换字符为数字**

  <img src="E:\Typora\Typora\coding-study\image-20250810184730970.png" alt="image-20250810184730970" style="zoom:50%;" />

- 枚举类型

  >代替 `const` 使用，可以配合 `unions`  和 `switch-case` 使用，灵活选择不同的数据类型
  >
  >默认从0开始递增，也可以手动指定枚举值

<img src="E:\Typora\Typora\coding-study\image-20250810194918409.png" alt="image-20250810194918409" style="zoom: 67%;" />

## 4.4 Typedef

- Typedef

  > 是一个关键词，用来创建**某种数据类型的别名**
  >
  > 例如：Typedef unsigned char uchar // 给unsigned char类型起了一个别名uchar，**两者完全等价**

- 应用于**头文件**

  ```c++
  _uint8_t.h
  #ifndef _UINT8_T
  #define _UINT8_T
  typedef unsigned char uint8_t; //创建了8位整数类型的一个别名
  #endif
  ```

- 应用于**宏定义**（为应用在当不同系统中统一变量长度，跨平台兼容）

  ```c++
  #if defined(_LP64)	// 检查某个宏是否被定义，如果在64位系统下，定义wchar_t是4字节数据类型
  typedef int wchar_t;	
  #else	// 其他系统下（32位系统中long是4字节）
  typedef long wchar_t;
  #endif
  ```

# 5 指针

## 5.1 指针类型

- 指针

  > 指针声明：`<数据类型> * <变量名>`
  >
  > 指针内容：指针存的是一个地址
  >
  > `&` ：放在变量前，取变量的地址
  >
  > `*`：放在地址前（指针前），取地址中的内容

<img src=".\images\image-20250811104451044.png" alt="image-20250811104451044" style="zoom: 33%;" />

- 结构体的指针

  ```c++
  struct Student
  {
      char name[4];
      int born;
      bool male;
  };
  
  Student stu = ("Yu", 2002, true);
  Student *pStu = &stu;	// 将结构体变量的地址赋值给指针变量
  
  // 通过指针修改结构体的方式
  strncpy(pStu->name, "Li", sizeof(pStu->name)); 
  (*pStu).born = 2000;
  pStu->male = false;
  ```

- 输出指针的信息

  ```c++
  Student stu = {"Yu", 2000, true};
  Student *pStu = &stu; 
  cout << "sizeof(pStu) = " << sizeof(pStu) << endl;	// 输出指针的长度
  cout << "Address of stu" << pStu << endl;	// 输出指针所指向的地址
  ```

- 指针的指针

  ![image-20251008183538403](E:\Typora\Typora\coding-study\image-20251008183538403-1759921489119.png)

  ```c++
  int num = 10;	
  int *p = &num;	// 指针
  int **pp = &p;	// 指针的指针
  
  *(*pp) = 20;	// 取两次值是num的值	
  ```

- 常量指针

  <img src="D:\GitHub\cpp\images\image-20251008191305398.png" alt="image-20251008191305398" style="zoom:50%;" />

## 5.2 指针与数组

- 数组的地址

  > 数组的地址不可以修改，相当于是 `cosnt` 类型
  >
  > 指针的地址可以变化的，是灵活的
  >
  > 但二者也有等价的地方，如下

  ```c
  struct Student
  {
      char name[4];
      int born;
      bool male;
  };
  
  Student students[128];	// 定义一个结构体类型的数组
  
  // 以下三种写法，都输出数组的首地址
  printf("students = %p\n", students);	
  printf("&students = %p\n", &students);	
  printf("&students[0] = %p\n", &students[0]);
  
  // 可以将数组（的首地址）赋值给指针
  Student *p = students;	// 指针指向数组的首地址
  Student *p0 = &student[0];	// 也可以单独取地址
  
  // 通过指针变量访问数组元素，和直接访问数组元素效果一样
  // 下面三者等价
  p[0].born = 2001;	 
  students[0].born = 2001;
  p0->born = 2001;
  ```

## 5.3 指针的代数操作

- 指针移动：**一个元素的移动，而不是一个地址的移动**

  >int *p	此处指针为int类型，其内容为所指向的元素的首地址
  >
  >p + num：向大地址移动num个元素
  >
  >p - num：向小地址移动num个元素
  >
  >（根据指针的类型移动，如**int为4个字节**，则**该处指针移动num个元素，即4*num**个字节）

  **容易出错的地方：指针越界到未定义的地方，即时不报错也会埋下隐患！！！**

  ```c++
  int num = 0;	// int类型，4个字节
  int *p = &num;	// 指针指向num的首地址
  
  p[0] = 3;	// 修改num的值为3
  
  p[-1] = 1;	// 该地址未定义，指针越界，潜在的error！！！
  p[1] = 4;	// 该地址未定义，指针越界，潜在的error！！！
  *(p+1) = 4;	// 与上面的写法等价
  ```


## 5.4 动态内存管理

- 程序与内存：程序的运行是**操作系统给程序在内存中分配了一段空间用于运行**

- 内存空间：一般可以分为下面五段

  <img src="D:\GitHub\cpp\images\image-20251010211249723.png" alt="image-20251010211249723" style="zoom:50%;" />

- 堆和栈

  > **地址分配：**理论上二者地址相向而行，但实际上他们之间插入了很多共享库、内存映射文件等，占据了中间的大量空间，且现代计算机虚拟内存较大，不至于精打细算。

  <img src="D:\GitHub\cpp\images\image-20251010214158412.png" alt="image-20251010214158412" style="zoom:67%;" />

  > **谨慎使用：**要谨慎使用动态内存分配——因为每个分配都有不可见的开销（为字节对齐，分配器多分配的内存）！
  >
  > **随机分配：**动态申请的内存里的内容可能是之前用过的，所以新的内容会覆盖
  >
  > **内存泄漏：**如果不手动释放，会造成内存泄漏，造成内存浪费，所以要记下地址择机释放
  >
  > ```c++
  > ======  C  ======
  > // c语言 内存申请
  > p = (int *) malloc (4 * sizeof(int));
  > // c语言 内存释放
  > free (p);
  > 
  > 
  > 
  > ====== C++ ======
  > // c++ 内存申请
  > int *p = new int;		// 申请一个整数类型内存（4字节），默认初始化
  > int *p = new int();		// 4字节，初始化为0
  > int *p = new int(5);	// 4字节。初始化为5
  > int *p = new int{};		// c++11中，4字节，初始化为0
  > int *p = new int{5};	// c++11中，4字节，初始化为5
  > Student *p = new Student;	// 申请一个类（结构体），默认初始化
  > Student *p = new Student{"Yu", 2020, 1};	// 申请一个类（结构体），初始化为指定值
  > int *p = new int[16];		// 申请16个int，64位内存，默认初始化
  > int *p = new int[16]();	// 申请16个int，全部初始化为0
  > int *p = new int[16]{};	// 申请16个int，全部初始化为0
  > int *p = new int[16]{1,2,3};	// 申请16个int，前三个整数初始化为指定值，剩下的初始化为0
  > Student *p = new Student[16];	// 申请16个类（结构体）内存空间，默认初始化
  > Student *p = new Student[16]{{"Yu", 2020, 1},{"Li", 2002, 0}};	// 申请16个类（结构体）内存空间，前两个初始化为指定值，剩下的默认初始化
  > 
  > // c++ 内存释放
  > delete p;	// 释放整数内存
  > delete []p;	// 释放数组（类/结构体）内存，（对于类，会调用每个类的解析构函数）
  > ```