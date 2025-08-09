#include <iostream>
#include "mysquare.hpp"

using namespace std;

int main(){
    float value;
    cout << "Input a floating-point number." << endl;
    cin >> value;

    float result = mysquare(value);

    if (result > 0)  
        cout << "The square is " << result << "." << endl;

    return 0;
}