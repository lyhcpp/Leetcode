#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int thirdMax(vector<int> &nums) {
    const unsigned long len = nums.size();
    int output;
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    int timesCmp = 0; //if timesCmp>=3, thirdMaxNum exists
    int minUpdated = 0; //if timesCmp=2, minUpdated used to check the third is INT_MIN or numsInput
    if (len == 1) return nums[0];
    if (len == 2) return nums[0] >= nums[1] ? nums[0] : nums[1];

    //len>=3 as follows
    for (int i = 0; i != len; ++i) {
        if (nums[i] == INT_MIN)
            minUpdated = 1;
        if (nums[i] == first || nums[i] == second || nums[i] == third)
            continue; //ignore the same number
        if (nums[i] > first) {
            third = second;
            second = first;
            first = nums[i];
            timesCmp += 1;
        } else if (nums[i] > second) {
            third = second;
            second = nums[i];
            timesCmp += 1;
        } else if (nums[i] > third) {
            third = nums[i];
            timesCmp += 1;
        }
    }
    if (minUpdated + timesCmp >= 3)
        output = third;
    else
        output = first;
    return output;
}

int main() {
    vector<int> nums = {1, 2, 2, 5, 3, 5};
    cout<<thirdMax(nums)<<endl;
    return 0;
}