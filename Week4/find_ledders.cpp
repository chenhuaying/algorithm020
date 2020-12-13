#include <vector>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using std::vector;
using std::string;
using std::deque;
using std::unordered_map;
using std::unordered_set;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        deque<string> queue;
        // 已入队列的元素
        unordered_set<string> queued;
        // 辅助map，保存字符串对应的路径
        unordered_map<string, vector<vector<string>>> assistMap;
        unordered_set<string> wordSet;
        for (auto word : wordList) {
            wordSet.insert(word);
        }
        queue.push_back(beginWord);
        queued.insert(beginWord);
        assistMap[beginWord] = vector<vector<string>>{vector<string>{beginWord}};

        vector<vector<string>> results;
        while (!queue.empty()) {
            int queueLength = queue.size();
            vector<string> words;
            vector<string> visited;
            // 一层一层的遍历
            for (int i = 0; i < queueLength; i++) {
                string word = queue.front();
                visited.push_back(word);
                if (word == endWord) {
                    for (auto path : assistMap[word]) {
                        results.push_back(path);
                    }
                } else {
                    for (int i = 0; i < word.size(); i++) {
                        for (auto c : characters) {
                            string newWord = word.substr(0, i);
                            newWord += c;
                            newWord += word.substr(i+1, word.size());
                            if (wordSet.find(newWord) != wordSet.end()) {
                                if (newWord != word) {
                                    if (assistMap[newWord].empty()) {
                                        assistMap[newWord] = {};
                                    }
                                    for (auto path : assistMap[word]) {
                                        path.push_back(newWord);
                                        assistMap[newWord].push_back(path);
                                    }
                                }
                                words.push_back(newWord);
                                if (queued.find(newWord) == queued.end()) {
                                    queue.push_back(newWord);
                                    queued.insert(newWord);
                                }
                            }
                        }
                    }
                }
                queue.pop_front();
            }
            for (auto w : words) {
                wordSet.erase(w);
            }
            for (auto w : visited) {
                assistMap.erase(w);
            }
        }
        return results;
    }

private:
    string characters = "abcdefghijklmnopqrstuvwxyz";

    void showPaths(vector<vector<string>>& paths) {
        std::cout << "[";
        for (auto path : paths) {
            showPath(path);
        }
        std::cout << "]" << std::endl;
    }

    void showPath(vector<string>& path) {
        std::cout << "[";
        for (auto p : path) {
            std::cout << p << " ";
        }
        std::cout << "]";
    }
};

struct testCase {
	string begin;
	string end;
	vector<string> wordList;
};

int main(int argc, char const *argv[])
{
    Solution s;
	testCase tcs[] = {
		{"ta", "if", vector<string>{"ts","sc","ph","ca","jr","hf","to","if","ha","is","io","cf","ta"}},
        {"a", "c", {"a","b","c"}},
        {"hot", "cog",{"hot","dot","dog","lot","log","cog"}},
        {"red", "tax", {"ted","tex","red","tax","tad","den","rex","pee"}}
	};
    for (auto tc : tcs) {
        auto results = s.findLadders(tc.begin, tc.end, tc.wordList);
        for (auto result : results) {
            for (auto item : result) {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "----------------------------------------------------" << std::endl;
	}
    return 0;
}
