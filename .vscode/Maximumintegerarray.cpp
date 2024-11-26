#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return max(nums[0] * nums[1], nums[n - 1] * nums[n - 2]);
}

int main() {
    vector<int> nums = {-10, -3, 5, 6, -2};
    cout << maxProduct(nums) << endl;  // Output: 30
    return 0;
}
