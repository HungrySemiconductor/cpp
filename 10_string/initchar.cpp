#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char rabbit[16] = {'P', 'e', 't', 'e', 'r'};
    cout << "String length is " << strlen(rabbit) << endl;
    for(int i = 0; i < 16; i++)
        cout << i << ":" << +rabbit[i] << "(" << rabbit[i] << ")" << endl; // 使用操作符‘+’，使字符转化为编码值输出
    
    char bad_pig[9] = {'P', 'e', 'p', 'p', 'a', ' ', 'P', 'i', 'g'};    // 没有以'0\'结尾，超出数组下标会越界，输出结果错误
    char good_pig[10] = {'P', 'e', 'p', 'p', 'a', ' ', 'P', 'i', 'g', '\0'};

    cout << "rabbit is (" << rabbit << ")" << endl;
    cout << "pig's bad name is (" << bad_pig << ")" << endl;
    cout << "pig's good name is (" << good_pig << ")" << endl;

    return 0;
}