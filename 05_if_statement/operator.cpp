#include <iostream>
using namespace std;

int main(){
    bool isPositive = true;
    int factor = 0;

// Version1
    // if(isPositive)
    //     factor = 1;
    // else
    //     factor = -1;

// Version2
    // factor = isPositive ? 1 : -1;    // 需要跳转到条件判断，效率低

// Version3
    factor = (isPositive) * 2 - 1;      // 只需要数学运算，效率高

    cout << "factor = " << factor << endl;
    return 0;
} 
