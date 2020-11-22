#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::swap;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int count = 0;
        for (int i = 0; count < nums.size(); i++) {
            int hold = nums[i];
            int start = i;
            int current = start;

            do {
                int next = (current + k) % nums.size();
                swap(hold, nums[next]);
                current = next;
                count++;
            } while (start != current);
        }
    }
};

void show_vector(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> vec = {1,2,3,4,5,6,7};
	s.rotate(vec, 3);
	show_vector(vec);
	return 0;
}
