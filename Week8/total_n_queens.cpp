#include <iostream>

class Solution {
 public:
  int totalNQueens(int n) {
    if (n < 2) return n == 0 ? 0 : 1;
    int count = 0;
    // cols, fslash, bslash 表示已放置皇后能攻击到到位置
    int cols = 0, fslash = 0, bslash = 0;
    int mask = (1 << n) - 1;
    dfs(0, n, count, cols, fslash, bslash, mask);
    return count;
  }

 private:
  void dfs(int level, int n, int& count, int cols, int fslash, int bslash,
           int mask) {
    // terminator
    if (level >= n) {
      count++;
      return;
    }

    // process
    // 能放置皇后到位置
    int bits = (~(cols | fslash | bslash)) & mask;
    while (bits > 0) {
      // 取最低位的 1
      int pos = bits & -bits;
      // 最低位低 1 置 0
      bits = bits & (bits - 1);
      // drill down
      dfs(level + 1, n, count, cols | pos, (fslash | pos) << 1,
          (bslash | pos) >> 1, mask);
      // revert
    }
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int t = s.totalNQueens(1);
  std::cout << "1 queen: " << t << std::endl;
  t = s.totalNQueens(2);
  std::cout << "2 queen: " << t << std::endl;
  t = s.totalNQueens(4);
  std::cout << "4 queen: " << t << std::endl;
  t = s.totalNQueens(8);
  std::cout << "8 queen: " << t << std::endl;

  return 0;
}
