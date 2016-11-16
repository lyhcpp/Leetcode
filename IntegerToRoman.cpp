#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num) {
    vector<vector<string> > roman = {{"", "M", "MM", "MMM"},
                                     {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                                     {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                                     {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}};
    string outputStr;
    int i = 0; //记录第i次除法
    int j = 1000; //记录第i次的被除数是j
    while (num != 0) {
        outputStr += roman[i][num / j];
        num = num % j;
        i += 1;
        j /= 10;
    }
    return outputStr;
}

int main() {
    int inputInt = 46;
    cout << intToRoman(inputInt) << endl;
    return 0;
}
