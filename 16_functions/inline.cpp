#include <iostream>
using namespace std;

#define MAX_MACRO(a, b) (a) > (b) ? (a) : (b)

int main()
{
    int x = 10;
    int y = 20;
    int max_val = MAX_MACRO(x++, y++);
    cout << "Max value: " << max_val << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;   
}
