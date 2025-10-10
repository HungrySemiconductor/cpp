#include <iostream>
using namespace std;

int main(){
    // 局部变量从栈上分配内存，本系统中，地址越来越大
    int a = 0;
    int b = 0;
    int c = 0;
    cout << "a: " << &a << endl;
    cout << "b: " << &b << endl;
    cout << "c: " << &c << endl;

    // 动态申请内存，地址越来越大
    // 分配4个字节，但实际上分配的可能比这个大
    // 因为内存分配器通常会分配比请求的更多的内存，以满足对齐要求和减少碎片
    int *p1 = (int*) malloc (4);    
    int *p2 = (int*) malloc (4);
    int *p3 = (int*) malloc (4);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;

    return 0;
}
