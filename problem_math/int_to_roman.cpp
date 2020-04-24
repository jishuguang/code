/* source: https://leetcode-cn.com/problems/integer-to-roman/
 * input: an integer
 * output: convert it to a roman numeral
 * author: jishuguang
 * time: 20200424
 */

#include <string>
#include <map>
using namespace std;

class Solution {
    const map<int, string> num_map = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };
public:
    string intToRoman(int num) {
        string result;
        auto it = num_map.crbegin();
        while (num != 0) {
            if (num >= it->first) {
                result += it->second;
                num -= it->first;
            } else {
                ++it;
            }
        }
        return result;
    }
};