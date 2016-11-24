#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    //将strs中的每个string按字母排好序，作为map的key
    vector<string> vecSorted(strs);
    for (auto &s:vecSorted) sort(s.begin(), s.end());

    //key:排好序的string; value:i,即原string在输入vector中的序号
    map<string, vector<int>> mapStr;
    for (int i = 0; i != vecSorted.size(); ++i) {
        mapStr[vecSorted[i]].push_back(i);
    }

    //按map中的顺序push进vec
    vector<vector<string>> vecVecStrOut;
    for (auto iter = mapStr.begin(); iter != mapStr.end(); ++iter) {
        vector<string> vecOutTmp;
        //numVec是vecotr<int>，装着原string在输入vector中的序号
        vector<int> numVec(iter->second);
        for (int i = 0; i != numVec.size(); ++i) {
            vecOutTmp.push_back(strs[numVec[i]]);
        }
        vecVecStrOut.push_back(vecOutTmp);
    }
    return vecVecStrOut;
}

int main() {
    vector<string> vecStr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> vecOut = groupAnagrams(vecStr);
    return 0;
}