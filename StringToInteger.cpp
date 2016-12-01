#include <iostream>
#include <limits>

//没匹配到有效字符要和npos对比，不能直接当条件
//边界处理的不好

using namespace std;

//特殊情况：
//1.正负号
//2.第一位有效数字前的字符
//3.最后一位有效数字后的字符
//4.int越界
int myAtoi(string str) {
    string strValid("+-0123456789");
    //确定有效数字位
    auto i = str.find_first_not_of(' ');
    if (strValid.find(str[i]) == string::npos)
        return 0;
    int intOut = 0;
    //syb记录符号位
    char syb = 1;
    if (str[i] == '-') {
        syb = -1;
        i += 1;
    } else if (str[i] == '+') i += 1;
    else {
        intOut = str[i] - 48;
        i += 1;
    }
    strValid = "1234567890";
    while (strValid.find(str[i]) != string::npos) {
        //判断添加一位后是否会溢出(这里的边界处理的不好）
        if (intOut > ((INT_MAX - str[i] + 48) / 10))
            //INT_MIN本处于界内，但若当做溢出处理也能返回INT_MIN
            return syb == 1 ? INT_MAX : INT_MIN;
        else {
            //这里的while其实可以将正负的情况分开写
            intOut = 10 * intOut + str[i] - 48;
            i += 1;
        }
    }
    return syb * intOut;
}

int main() {
    string strIn = "-0";
    std::cout << myAtoi(strIn) << std::endl;
    return 0;
}