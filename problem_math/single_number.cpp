/* source: https://leetcode-cn.com/problems/single-number-ii/
 * input: a non-empty array of integers, , every element appears three times except for one, which appears exactly once.
 * output: Find that single one.
 * author: jishuguang
 * create: 20200427 
 */

#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        uint32_t once_bits = 0;
        uint32_t twice_bits = 0;
        for (const auto& i : nums) {
            uint32_t cur_num = i;            
            once_bits ^= ~twice_bits & cur_num;
            twice_bits ^= ~once_bits & cur_num;
        }
        return once_bits;
    }
};