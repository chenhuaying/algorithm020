#include <algorithm>
#include <iostream>
#include <vector>

using std::min;
using std::vector;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    // 题目条件给出grid的长度大于0, 此异常条件可以省略
    if (grid.size() == 0) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
      dp[i][0] = grid[i][0] + dp[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
      dp[0][j] = grid[0][j] + dp[0][j - 1];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> testCase[] = {
      vector<vector<int>>{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
      vector<vector<int>>{{1, 2, 3}, {4, 5, 6}}};
  for (auto tc : testCase) {
    int res = s.minPathSum(tc);
    std::cout << res << std::endl;
  }
  return 0;
}
