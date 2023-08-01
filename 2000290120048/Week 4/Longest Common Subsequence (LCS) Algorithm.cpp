#include <iostream>
#include <vector>
#include <algorithm>

int lcs(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string str1 = "AGGTAB";
    std::string str2 = "GXTXAYB";

    int len = lcs(str1, str2);
    std::cout << "Length of LCS: " << len << std::endl;
    return 0;
}
