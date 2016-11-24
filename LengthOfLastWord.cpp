#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
    auto iterLast = s.end() - 1;
    for (; iterLast != s.begin() - 1; --iterLast)
        if (*iterLast != ' ') break;
    if (iterLast == s.begin() - 1)
        return 0;
    auto iterFir = iterLast;
    for (; iterFir != s.begin() - 1; --iterFir) {
        if (*iterFir == ' ') break;
    }
    return iterLast - iterFir;
}

int main() {
    string strInt = "I am OK ";
    cout << lengthOfLastWord(strInt) << endl;
    return 0;
}