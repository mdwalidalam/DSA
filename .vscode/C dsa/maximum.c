#include <stdio.h>
#include <limits.h>

int maxProduct(int nums[], int n) {
    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for(int i = 0; i < n; i++) {
        if (nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] > max2) {
            max2 = nums[i];
        }

        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] < min2) {
            min2 = nums[i];
        }
    }
    return max1 * max2 > min1 * min2 ? max1 * max2 : min1 * min2;
}

int main() {
    int nums[] = {-10, -3, 5, 6, -2};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", maxProduct(nums, n));  // Output: 30
    return 0;
}
