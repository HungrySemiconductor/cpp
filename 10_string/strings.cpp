#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[] = "Hello, \0CPP";
    char str2[] = "SUSTech";
    char result[128];

    for(int i = 0; i < 16; i++) // 越界访问了
        cout << i << ":" << +str1[i] << "(" << str1[i] << ")" << endl;        

    strcpy(result, str1);   // 复制字符串
    cout << "Result = " << result << endl;
    strcat(result, str2);   // 连接字符串
    cout << "Result = " << result << endl;

    cout << "strcmp() = " << strcmp(str1, str2) << endl;    // 比较大小，第一个字符的编码值大小，True输出正值，False输出负值

    return 0;
}