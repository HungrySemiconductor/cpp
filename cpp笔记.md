# 1 

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

![image-20250807184945244](E:\Typora\Typora\coding-study\image-20250807184945244.png)

- VSCode添加编译器

  > 终端选择` WSL` 而不是 `PowerShell`，主要是想练习最近学习的 `Linux` 命令

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

  >
  >
  >

- 使用方法

  >
  >
  >



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

![image-20250807201841260](E:\Typora\Typora\coding-study\image-20250807201841260.png)

![image-20250807201916788](E:\Typora\Typora\coding-study\image-20250807201916788.png)



## 1.5 命令行输入



---

# 2





# 3