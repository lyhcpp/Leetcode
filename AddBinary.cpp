#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    //令a为长的字符串，方便下面计算
    if (a.length() < b.length()) a.swap(b);
    auto diffCount = a.length() - b.length();
    //将短的字符串补全至和长的字符串位数一致
    b.insert(b.begin(), diffCount, '0');
    string strOut(a);
    auto cnt = a.length();
    bool carry = 0;
    while (cnt) {
        if ((a[cnt - 1] + b[cnt - 1] + carry) == 96) {
            carry = 0;
            strOut[cnt - 1] = '0';
            cnt--;
            continue;
        }
        if ((a[cnt - 1] + b[cnt - 1] + carry) == 97) {
            carry = 0;
            strOut[cnt - 1] = '1';
            cnt--;
            continue;
        }
        if ((a[cnt - 1] + b[cnt - 1] + carry) == 98) {
            carry = 1;
            strOut[cnt - 1] = '0';
            cnt--;
            continue;
        }
        if ((a[cnt - 1] + b[cnt - 1] + carry) == 99) {
            carry = 1;
            strOut[cnt - 1] = '1';
            cnt--;
            continue;
        }
    }
    if (carry) strOut.insert(strOut.begin(),'1');
    return strOut;
}

int main() {
    string a="10",b="11";
    std::cout << addBinary(a,b) << std::endl;
    return 0;
}