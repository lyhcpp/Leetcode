#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num) {
    vector<int> output(num + 1);
    for (int i = 1; i <= num; ++i) {
        output[i] = output[i & (i - 1)] + 1;
    }
    return output;
}

int main() {
    int num=5;
    auto output=countBits(num);
    for(auto &c:output)
    {
        cout<<c<<',';
    }
    return 0;
}