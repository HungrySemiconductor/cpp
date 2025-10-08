#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    char name[4];
    int born;
    bool male;
};

int main()
{
    Student stu = {"Yu", 2000, true};
    Student *pStu = &stu;   // 将结构体变量的地址赋值给指针变量

    cout << stu.name << " was born in " << stu.born
         << ". Gender: " << (stu.male ? "male" : "female") << endl;   // 通过指针访问结构体成员

    strncpy(pStu->name, "Li", sizeof(pStu->name));  // 修改结构体成员
    pStu->born = 2001;
    (*pStu).born = 2002;
    pStu->male = false;

    cout << stu.name << " was born in " << stu.born
         << ". Gender: " << (stu.male ? "male" : "female") << endl;   // 通过指针访问结构体成员
    
    return 0;
}