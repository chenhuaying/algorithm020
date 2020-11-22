#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0) return digits;
        }
        digits.emplace_back(0);
        digits[0] = 1;
        return digits;
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
	Solution solution;
	vector<int> vec;
	auto result = solution.plusOne(vec);
	show_vector(vec);

	vec = {9};
	solution.plusOne(vec);
	show_vector(vec);

	vec = {9, 9};
	solution.plusOne(vec);
	show_vector(vec);

	vec = {1, 2, 3};
	solution.plusOne(vec);
	show_vector(vec);

	return 0;
}
