#include <iostream>
using namespace std;

struct Student{ 
    char name[4];   // 4 bytes
    int born;       // 4 bytes 
    bool male;      // 1 bytes
};

int main()
{
    Student stu = {"Yu", 2000, true};
    // struct Student stu;
    // strcpy(stu.name, "Yu");
    // stu.born = 2000;
    // stu.male = true;

    cout << "Student " << stu.name << ", ";
    cout << "born in " << stu.born << ", ";
    cout << "gender is " << (stu.male ? "male" : "female") << "." << endl;
    cout << "sizeof(stu) = " << sizeof(stu) << endl;    // 为内存对齐，长度为12bytes

    return 0;
}
