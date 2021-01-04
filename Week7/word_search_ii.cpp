#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (board.size() == 0 || board[0].size() == 0) return {};
    for (auto word : words) {
      insert(word);
    }

    m = board.size();
    n = board[0].size();
    vector<string> result;
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (root.nodes[board[i][j] - 'a'] != nullptr) {
          dfs(board, i, j, "", &root, result);
        }
      }
    }
    return result;
  }

 private:
  struct TrieNode {
    TrieNode* nodes[26];
    bool isEnd;
    TrieNode() : isEnd(false) {
      for (int i = 0; i < 26; i++) nodes[i] = nullptr;
    }
  };

  void insert(string word) {
    TrieNode* cur = &root;
    for (auto ch : word) {
      if (cur->nodes[ch - 'a'] == nullptr) cur->nodes[ch - 'a'] = new TrieNode;
      cur = cur->nodes[ch - 'a'];
    }
    cur->isEnd = true;
  }

  void dfs(vector<vector<char>>& board, int i, int j, string word,
           TrieNode* node, vector<string>& result) {
    word.push_back(board[i][j]);
    TrieNode* cur = node->nodes[board[i][j] - 'a'];
    if (cur->isEnd == true) {
      result.push_back(word);
      cur->isEnd = false;
    }

    // modified source data
    // char tmp = board[i][j];
    // board[i][j] = '@';
    visited[i][j] = true;
    for (auto direction : directions) {
      int x = i + direction[0];
      int y = j + direction[1];
      if (x >= 0 && x < m && y >= 0 && y < n &&
          visited[x][y] == false
          /*board[x][y] != '@'*/
          && cur->nodes[board[x][y] - 'a'] != nullptr) {
        dfs(board, x, y, word, cur, result);
      }
    }
    // board[i][j] = tmp;
    visited[i][j] = false;
  }

  vector<vector<bool>> visited;
  TrieNode root;
  int m;
  int n;
  int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};

int main(int argc, char const* argv[]) {
  vector<vector<char>> boards[] = {
      {{'a', 'a'}},
      {{'a', 'a'}},
      {{'o', 'a', 'a', 'n'},
       {'e', 't', 'a', 'e'},
       {'i', 'h', 'k', 'r'},
       {'i', 'f', 'l', 'v'}},
  };
  vector<string> targets[] = {
      {"a"},
      {"aaa"},
      {"oath", "pea", "eat", "rain"},
  };
  for (int i = 0; i < 3; i++) {
    Solution s;
    auto res = s.findWords(boards[i], targets[i]);
    for (auto itm : res) {
      std::cout << itm << std::endl;
    }
    std::cout << "-------" << std::endl;
  }
  return 0;
}
