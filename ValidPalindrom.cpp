#include <iostream>
#include <cctype>

using namespace std;

//cctype.h中的isalpha, isdigit, tolower
bool isPalindrome(string &s) {
    if (s.empty()) return true;
    auto iterStart = s.begin(), iterFinish = s.end() - 1;
    while (iterStart < iterFinish) {
        //将输入字符串中的字母转换为小写
        auto lhs=tolower(*iterStart),rhs=tolower(*iterFinish);
        if (!isalpha(lhs)&&!isdigit(lhs)) {
            iterStart += 1;
            continue;
        }
        if (!isalpha(rhs)&&!isdigit(rhs)) {
            iterFinish -= 1;
            continue;
        }
        if (lhs!=rhs)
            return false;
        iterStart += 1;
        iterFinish -= 1;
    }
    return true;
}

int main() {
    string strIn("aba");
    std::cout << isPalindrome(strIn) << std::endl;
    return 0;
}