#include <iostream>
using namespace std;

union ipv4addr{
    std::uint32_t addr32;
    std::uint8_t addr8[4];
};

int main()
{
    union ipv4addr ip;

    cout << "sizeof(ip) = " << sizeof(ip) <<endl;

    ip.addr8[3] = 127;
    ip.addr8[2] = 0;
    ip.addr8[1] = 0;
    ip.addr8[0] = 0;

    cout << "The ip address is ";
    cout << +ip.addr8[3] << ".";    // ip.addr8将会输出其对应的字符，为此需要使用+强制转换为编码值
    cout << +ip.addr8[2] << ".";
    cout << +ip.addr8[1] << ".";
    cout << +ip.addr8[0] << endl;

    cout << std::hex;
    cout << "in hex" << ip.addr32 << endl;

    return 0;
}

