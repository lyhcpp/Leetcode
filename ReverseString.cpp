#include <iostream>

using namespace std;

string reverseString(string& s){
	string output(s.rbegin(),s.rend());
	return output;
}

int main()
{
	string input("Hello");
	cout<<reverseString(input)<<endl;
	return 0;
}