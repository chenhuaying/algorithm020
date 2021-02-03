#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::max;
using std::stack;
using std::string;
using std::vector;

class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);
    int longest = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(')
        stk.push(i);
      else if (s[i] == ')' && stk.top() != -1 && s[stk.top()] == '(') {
        stk.pop();
        longest = max(longest, i - stk.top());
      } else {
        stk.top() = i;
      }
    }
    return longest;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<string> testCase = {"(()", ")()())"};
  for (auto tc : testCase) {
    int res = s.longestValidParentheses(tc);
    std::cout << "test case: " << tc << ", " << res << std::endl;
  }
  return 0;
}
