#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& e : m) {
            res.push_back(e.second);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	auto res = s.groupAnagrams(strs);
	for (auto group: res) {
		for (auto itm : group) {
			std::cout << itm << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
