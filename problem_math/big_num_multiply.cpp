/* source: https://leetcode-cn.com/problems/multiply-strings/
 * input: Given two non-negative integers num1 and num2 represented as strings
 * output: return the product of num1 and num2, also represented as a string
 * author: jishuguang
 * time: 20200424
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // setup
        auto max_size = num1.size() + num2.size();
        string result(max_size, 0);
        // calculate from low weight to high weight
        for (auto rit1 = num1.rbegin(); rit1 != num1.rend(); ++rit1) {
            for (auto rit2 = num2.rbegin(); rit2 != num2.rend(); ++rit2) {
                auto weight1 = rit1 - num1.rbegin();
                auto weight2 = rit2 - num2.rbegin();
                auto current_it = result.rbegin() + weight1 + weight2;
                *current_it += (*rit1 - '0') * (*rit2 - '0');
                *(current_it + 1) += *current_it / 10;
                *current_it %= 10;
            }
        }
        // change num to 'num'
        for (auto& c : result) {
            c += '0';
        }
        // trim leading '0'
        auto pos = result.find_first_not_of('0');
        if (pos != string::npos) {
            result = result.substr(pos);
        } else {
            result = '0';
        }
        return result;
    }
};

int main()
{
    Solution s;
    string num1, num2;
    while(cin >> num1 >> num2) {
        cout << s.multiply(num1, num2);
    }
}
