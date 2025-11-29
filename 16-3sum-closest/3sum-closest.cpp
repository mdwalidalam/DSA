class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int closest = nums[0] + nums[1] + nums[2]; // initial sum

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int curr = nums[i] + nums[left] + nums[right];

                // update closest if needed
                if (abs(curr - target) < abs(closest - target)) {
                    closest = curr;
                }

                if (curr < target) {
                    left++;
                } else if (curr > target) {
                    right--;
                } else {
                    return curr; // exact match
                }
            }
        }

        return closest;
    }
};
