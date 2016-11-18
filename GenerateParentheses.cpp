#include <iostream>
#include <string>
#include <vector>

using namespace std;

//返回void的递归:一定会回到调用点的状态
//假设在位置k我们还剩余left个左括号和right个右括号
//若left>right, 后面无法匹配，结束此次执行
//若left<=right:
//每执行一次left-1或right-1，对应添加一个(或)
//当left=right, push一次结果
void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
    if (left > right) {
        return;
    }
    if (left == 0 && right == 0) {
        res.push_back(out);
    } else {
        if (left > 0) {
            generateParenthesisDFS(left - 1, right, out + '(', res);
        }
        if (right > 0) {
            generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> outputVec;
    generateParenthesisDFS(n, n, "", outputVec);
    return outputVec;
}


int main() {
    vector<string> res = generateParenthesis(3);
    for (auto &s:res) {
        cout << s << endl;
    }
    return 0;
}
