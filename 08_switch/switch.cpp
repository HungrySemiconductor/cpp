#include <iostream>
using namespace std;

int main(){
    unsigned char input_char = 0;

    cout << "Please input a character to start." << endl;
    cin >> input_char;

    while (input_char != 'q')
    {
        switch(input_char)
        {
            case 'a':
            case 'A':
                cout << "Move left. Input 'q' to quit." << endl;
                break;
            case 'd':
            case 'D':
                cout << "Move Right. Input 'q' to quit." << endl;
                break;
            default:
                cout << "Undefined key. Input 'q' to quit." << endl;
                break;
        }
        cin >> input_char;  //循环结束后重新读取输入
    }
    
    return 0;
}