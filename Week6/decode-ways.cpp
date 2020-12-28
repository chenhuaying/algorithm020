#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n + 1);
    dp[1] = codes.count(s.substr(0, 1)) ? 1 : 0;
    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
      int x = numDecode(s.substr(i - 1, 1));
      int y = numDecode(s.substr(i - 2, 2));
      // f(n) = f(n-1) + f(n-2)
      dp[i] = (x == 0 ? 0 : dp[i - 1]) + (y == 0 ? 0 : dp[i - 2]);
    }
    return dp[n];
  }

 private:
  unordered_set<string> codes{"1",  "2",  "3",  "4",  "5",  "6",  "7",
                              "8",  "9",  "10", "11", "12", "13", "14",
                              "15", "16", "17", "18", "19", "20", "21",
                              "22", "23", "24", "25", "26"};
  int numDecode(string s) { return codes.count(s) ? 1 : 0; }
};

int main(int argc, char const *argv[]) {
  Solution solution;
  string testCase[] = {"12", "226", "0", "1", "2", "10", "2101", "170"};
  for (auto tc : testCase) {
    int res = solution.numDecodings(tc);
    std::cout << res << std::endl;
  }
  return 0;
}
