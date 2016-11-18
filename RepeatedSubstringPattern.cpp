#include <iostream>

using namespace std;

//string的substr方法
//str.substr(indexStart,numbers)
bool repeatedSubstringPattern(string str) {
    auto strSize = str.size();
    for (unsigned long i = 1; i <= strSize / 2; ++i) {
        if (strSize % i == 0) {
            auto count = strSize / i;
            auto subStr = str.substr(0, i);
            string cmp = "";
            while (count != 0) {
                cmp += subStr;
                count--;
            }
            if (cmp == str) {
                return true;
            } else {
                continue;
            }
        }
    }
    return false;
}

int main() {
    string strTest = "adadad";
    cout << repeatedSubstringPattern(strTest) << endl;
    return 0;
}
