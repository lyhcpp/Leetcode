#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canConstruct(string ransomNote, string magzazine){
	vector<int> vecHash(256,0);
	for(auto i:magzazine) vecHash[static_cast<int>(i)]++;
	for(auto i:ransomNote) vecHash[static_cast<int>(i)]--;
	for(auto &i:vecHash)
		if (i<0) return false;
	return true;
}

int main() {
    bool canConstruct(string ransomNote, string magazine);
    string ransomNote("asdfghjkq"),magazine("asdfghjklzxcvbnm");
    cout<<canConstruct(ransomNote, magazine)<<endl;
    return 0;
}