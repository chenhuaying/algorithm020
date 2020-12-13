#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five <= 0) return false;
                 five--;
                 ten++;
            } else {
                if (five > 0 && ten > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> bills{5,5,5,10,20};
	bool result = s.lemonadeChange(bills);
	std::cout << result << std::endl;

	return 0;
}
