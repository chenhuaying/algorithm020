#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> table(26, 0);
        for (auto& ch: s) {
            table[ch - 'a']++;
        }
        for (auto& ch: t) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	bool res = s.isAnagram("anagram", "nagaram");
	std::cout << "anagram | nagaram: " << res << std::endl;
	res = s.isAnagram("rat", "car");
	std::cout << "rat | car: " << res << std::endl;
	return 0;
}
