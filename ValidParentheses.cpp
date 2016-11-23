#include <iostream>
#include <stack>

using namespace std;

//栈操作
bool isValid(string s) {
    stack<char> charStack;
    if (s.empty()) return true;
    for (auto &c:s) {
        if ((c == '(') || (c == '[') || (c == '{')) {
            charStack.push(c);
            continue;
        }

        if ((c == ')') || (c == ']') || (c == '}')) {
            if (charStack.empty()) return false;
            if ((c - charStack.top() == 1) || (c - charStack.top() == 2)) {
                charStack.pop();
                continue;
            } else
                return false;
        }
    }
    if (charStack.empty()) return true;
    return false;

}

int main() {
    string strIn = "{()}[";
    cout << isValid(strIn) << endl;
    return 0;
}