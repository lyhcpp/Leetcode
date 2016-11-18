#include <iostream>

using namespace std;
/*
简便算法:
//find_first_of和find_last_of的pos参数的意义：
//分别为起始位置与结束位置
string reverseVowels(string s) {
    string target = "aeiouAEIOU";
    size_t first = s.find_first_of(target);
    size_t last = s.find_last_of(target);
    while (first < last) {
        swap(s[first],s[last]);
        first = s.find_first_of(target, first+1);
        last = s.find_last_of(target, last-1);
    }
    return s;
}
*/
const string vowels = "aeiouAEIOU";

string reverseVowels(string &s) {
    string strRes(s);
    int posBeg = 0;
    auto posEnd = s.size();
    while (posBeg < posEnd) {
        //如果str[posBeg]是元音
        if (vowels.find(s[posBeg]) != string::npos) {
            //寻找未被交换过的子串的最后一个元音
            posEnd = string(s, 0, posEnd).find_last_of(vowels);
            swap(strRes[posBeg], strRes[posEnd]);
        }
        posBeg += 1;
    }
    return strRes;
}

int main() {
    string str = "AEIOU";
    cout << reverseVowels(str) << endl;
    return 0;
}