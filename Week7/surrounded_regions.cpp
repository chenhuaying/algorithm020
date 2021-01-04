#include <algorithm>
#include <iostream>
#include <vector>

using std::swap;
using std::vector;

class UnionFind {
 public:
  UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      parents.push_back(i);
      rank.push_back(0);
    }
  }

  int find(int p) {
    while (p != parents[p]) {
      p = parents[p];
    }
    return p;
  }

  void unite(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rank[rootP] > rank[rootQ]) swap(rootP, rootQ);
    parents[rootP] = rootQ;
    if (rank[rootP] == rank[rootQ]) rank[rootQ] += 1;
  }

  bool isConnected(int p, int q) { return find(p) == find(q); }

 private:
  vector<int> parents;
  vector<int> rank;
};

class Solution {
 public:
  void solve(vector<vector<char>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) return;
    m = grid.size(), n = grid[0].size();
    UnionFind uf = UnionFind(m * n + 1);
    int dummy = m * n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 'O') {
          if (i != 0 && i != m - 1 && j != n - 1 && j != 0) {
            for (auto direction : directions) {
              int x = i + direction[0];
              int y = j + direction[1];
              if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 'O') {
                uf.unite(getIndex(x, y), getIndex(i, j));
              }
            }
          } else {
            uf.unite(getIndex(i, j), dummy);
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!uf.isConnected(getIndex(i, j), dummy)) {
          grid[i][j] = 'X';
        }
      }
    }
  }

 private:
  int m;
  int n;
  int getIndex(int i, int j) { return i * n + j; }
  int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  void dfs(vector<vector<char>>& grid, int i, int j, UnionFind& uf) {}
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<char>> grid;
  grid.push_back({'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O'});
  grid.push_back({'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'});
  grid.push_back({'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X'});
  grid.push_back({'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O'});
  grid.push_back({'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X'});
  grid.push_back({'X', 'X', 'O', 'X', 'X', 'O', 'O', 'X', 'X', 'X'});
  grid.push_back({'O', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O'});
  grid.push_back({'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X'});
  grid.push_back({'X', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O'});
  grid.push_back({'X', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O'});

  s.solve(grid);
  for (int i = 0; i < grid.size(); i++) {
    std::cout << "[";
    for (int j = 0; j < grid[0].size(); j++) {
      std::cout << grid[i][j] << ", ";
    }
    std::cout << "]" << std::endl;
  }
  return 0;
}