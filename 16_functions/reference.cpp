#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cout << num << endl;

    int &num_ref = num; // num_ref是num的别名
    num_ref = 10;       // 修改num_ref实际上也是在修改num
    cout << num_ref << endl;
}
