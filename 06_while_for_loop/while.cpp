#include <iostream>
using namespace std;

int main(){
    int num = 10;
    // size_t = 10;  //size_t是无符号整数，减到0后又会从最大的值开始无限循环下去
    while(num >= 0)
    {
        cout << "num = " << num << endl;
        num -= 1;
    }
    return 0;
}