#include <iostream>
using namespace std;

struct Student
{
    char name[4];
    int born;
    bool male;
};

int main()
{
    Student students[128];

    // 都输出数组的首地址
    printf("students = %p\n", students);	
    printf("&students = %p\n", &students);	
    printf("&students[0] = %p\n", &students[0]);

    // 数组的首地址赋值给指针变量
    Student *p = students;
    Student *p2 = &students[2];

    // 通过指针变量访问数组元素
    p[0].born = 2001;	 
    students[1].born = 2002;
    p2->born = 2003;

    printf("students[0].born = %d\n", students[0].born);
    printf("students[1].born = %d\n", students[1].born);
    printf("students[2].born = %d\n", students[2].born);

    return 0;
}


