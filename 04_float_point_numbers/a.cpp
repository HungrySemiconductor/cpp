#include <iostream>
using namespace std;

int main(){
    int a = 3;
    int b = a++;    // 先赋值给b=3，后自增a=3+1=4
    int c = ++a;    // 先自增a=4+1=5，后赋值c=5
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;
    cout << "c = " << c <<endl;

    return 0;
} 
