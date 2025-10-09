#include <iostream>
using namespace std;

// 宏定义，输出数组中每个元素内容
#define PRINT_ARRAY(array, n) \
for (int idx = 0; idx < (n); idx++) \
    cout << "array[" << idx << "] = " << (array)[idx] << endl;

int main()
{
    int numbers[4] = {0, 1, 2, 3};
    PRINT_ARRAY(numbers, 4)

    int *p = numbers + 1; // 指向数组的第二个元素
    p++;

    cout << "numbers = "<< numbers << endl; // 数组名表示数组首元素的地址
    cout << "p = " << p << endl;  // p指向数组的第三个元素，相较于数组首地址已经移动了8个字节

    *p = 20;
    *(p-1) = 10;
    p[1] = 30;

    PRINT_ARRAY(numbers, 4)

    return 0;
} 









