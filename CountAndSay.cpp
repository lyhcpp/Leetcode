#include <iostream>

using namespace std;

//char(intTmp+'0')
string countAndSay(int n) {
    string strOut = "1";
    if (n == 1) return strOut;
    for (int i = 1; i < n; ++i) {
        string strTmp = "";
        int intTmp = 1;
        unsigned long len = strOut.length();
        for (int j = 0; j < len; ++j) {
            if (strOut[j] == strOut[j + 1]) intTmp += 1;
            else {
                strTmp = strTmp + static_cast<char>(intTmp + '0') + strOut[j];
                intTmp = 1;
            }
        }
        strOut = strTmp;
    }
    return strOut;
}

int main() {
    cout << countAndSay(5) << endl;
    return 0;
}
