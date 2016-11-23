#include <iostream>
#include <vector>

using namespace std;

//string(n,'c')
//DFS可以把参数都传进去
//strTmp和vecRes用引用传递
string digToStr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinationsDFS(string &strTmp, unsigned long curDep, unsigned long totDep, vector<string> &vecRes,
                           string &digits) {
    if (curDep == totDep) {
        vecRes.push_back(strTmp);
        return;
    } else {
        for (int i = 0; i != digToStr[digits[curDep] - '0'].size(); ++i) {
            strTmp[curDep] = digToStr[digits[curDep] - '0'][i];
            letterCombinationsDFS(strTmp, curDep + 1, totDep, vecRes, digits);
        }
        return;
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> vecOut;
    auto len = digits.length();
    if (len == 0) return vecOut;
    else {
        auto totDep = digits.size();
        string strTmp(totDep, 0);
        letterCombinationsDFS(strTmp, 0, totDep, vecOut, digits);
    }
    return vecOut;
}

int main() {
    string strIn = "23";
    for (auto v:letterCombinations(strIn))
        cout << v << ' ';
    return 0;
}