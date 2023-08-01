#include <iostream>
#include <vector>
#include <algorithm>

int lis(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    int maxLength = lis(nums);
    std::cout << "Length of Longest Increasing Subsequence: " << maxLength << std::endl;
    return 0;
}
