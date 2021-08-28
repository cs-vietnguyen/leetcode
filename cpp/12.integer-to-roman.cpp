/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
    vector<char> symbols = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<int> values = {1, 5, 10, 50, 100, 500, 1000};
public:
    string calc(int &num) {
        string result;

        while (num) {
            for (int i = this->values.size() - 1; i >= 0; i--) {
                int count = num / this->values[i];

                if (count > 0) {
                    num -= this->values[i] * count;
                    while(count--) {
                        result.push_back(this->symbols[i]);
                    }
                    break;
                }

                if (i % 2 && num >= this->values[i] * 0.8) {
                    result.push_back(this->symbols[i - 1]);
                    result.push_back(this->symbols[i]);
                    num -= this->values[i] - this->values[i - 1];
                    break;
                }
                else if (!(i % 2) && num >= this->values[i] * 0.9) {
                    result.push_back(this->symbols[i - 2]);
                    result.push_back(this->symbols[i]);
                    num -= this->values[i] - this->values[i - 2];
                    break;
                }
            }
        }

        return result;
    }

    string intToRoman(int num) {
        return calc(num);
    }
};
// @lc code=end

