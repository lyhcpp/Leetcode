#include <iostream>
/*
 * 心得：
 * 1. 字符串的题就用字符去做，用库函数反而慢并且对于边界处理不到位
 * 2. 对遍历到终点的处理
 */
using namespace std;

//assign, erase
//考虑情况：
//1.多个'.'作分割
//2.'.'个数相同
//int compareVersion(string version1, string version2) {
//    while (1) {
//        if (version1 == version2)
//            return 0;
//        auto posDot1 = version1.find('.');
//        auto posDot2 = version2.find('.');
//        string strLeft1, strLeft2, strTmp1, strTmp2;
//        strLeft1.assign(version1, 0, posDot1);
//        strLeft2.assign(version2, 0, posDot2);
//        int intLeft1 = stoi(strLeft1), intLeft2 = stoi(strLeft2);
//        if (intLeft1 > intLeft2) return 1;
//        else if (intLeft1 < intLeft2) return -1;
//        else {
//            strTmp1 = version1.substr(posDot1 + 1);
//            strTmp2 = version2.substr(posDot2 + 1);
//            if (strTmp1 == version1)
//                return -1;
//            if (strTmp2 == version2)
//                return 1;
//            version1 = strTmp1;
//            version2 = strTmp2;
//        }
//    }
//}

int compareVersion(string version1, string version2) {
    auto iter1 = version1.begin(), iter2 = version2.begin();
    int intTmp1 = 0, intTmp2 = 0;
    while (intTmp1 == intTmp2) {
        for (intTmp1 = 0; *iter1 != '.' && iter1 != version1.end(); ++iter1) {
            intTmp1 = 10 * intTmp1 + *iter1 - 48;
        }
        for (intTmp2 = 0; *iter2 != '.' && iter2 != version2.end(); ++iter2) {
            intTmp2 = 10 * intTmp2 + *iter2 - 48;
        }
        if (intTmp1 > intTmp2) return 1;
        else if (intTmp1 < intTmp2) return -1;
        if (iter1 != version1.end()) iter1 += 1;
        if (iter2 != version2.end()) iter2 += 1;
        if (iter1 == version1.end() && iter2 == version2.end()) break;
    }
    return 0;
}

int main() {
    string a = "1.2.1", b = "1.2.1.0.0.0";
    std::cout << compareVersion(a, b) << std::endl;
    return 0;
}