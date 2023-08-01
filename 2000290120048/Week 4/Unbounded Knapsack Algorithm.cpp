#include <iostream>
#include <vector>
#include <algorithm>

int unboundedKnapsack(int W, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    std::vector<int> dp(W + 1, 0);

    for (int w = 1; w <= W; ++w) {
        for (int i = 0; i < n; ++i) {
            if (weights[i] <= w) {
                dp[w] = std::max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }

    return dp[W];
}

int main() {
    int W = 10;
    std::vector<int> weights = {2, 3, 4, 5};
    std::vector<int> values = {3, 4, 5, 6};

    int maxVal = unboundedKnapsack(W, weights, values);
    std::cout << "Maximum value: " << maxVal << std::endl;
    return 0;
}
