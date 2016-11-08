//greedy algorithm, pari, lambda,
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people){
	sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first || (a.first == b.first && a.second < b.second);}
		);
	vector<pair<int, int>> output;
	for(auto &i:people)
	{
		output.insert(output.begin()+i.second, i);
	}
	return output;
}

int main() {
    vector<pair<int, int>> input{{7, 0},
                                 {4, 4},
                                 {7, 1},
                                 {5, 0},
                                 {6, 1},
                                 {5, 2}};
    auto output=reconstructQueue(input);
    for (auto &i:output) {
        cout <<'{'<< i.first << ',' << i.second << '}'<<' ';
    }
    return 0;
}