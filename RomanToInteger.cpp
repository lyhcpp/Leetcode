#include <iostream>
#include <string>

using namespace std;

unsigned int charToInt(char romanInput) {
    switch (romanInput) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(string s) {
    if (s.empty()) return 0;
    int intOutput = 0;
    int temp = charToInt(*s.begin());
    for (auto iter_s = s.begin() + 1; iter_s != s.end(); ++iter_s) {
        int tempLeft = charToInt(*(iter_s - 1));
        int tempRight = charToInt(*iter_s);
        // 如果当前处理的字符对应的值和上一个字符一样，那么临时变量加上这个字符。比如III = 3
        if (tempRight == tempLeft) {
            temp += tempRight;
        }
        // 如果当前(tempRight)比前一个(tempLeft)大，说明这一段的值应该是当前这个值减去前面记录下的临时变量中的值。比如IIV = 5 – 2
        if (tempRight > tempLeft) {
            temp = tempRight - temp;
        }
        // 如果当前(tempRight)比前一个(tempLeft)小，那么就可以先将临时变量的值加到结果中，然后开始下一段记录。比如VI = 5 + 1
        if (tempRight < tempLeft) {
            intOutput += temp;
            temp = tempRight;
        }
    }
    intOutput += temp;
    return intOutput;
}

int main() {
    string input;
    while (1) {
        cin >> input;
        cout << romanToInt(input) << endl;
    }
    return 0;
}