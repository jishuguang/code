/* source: 7 https://leetcode-cn.com/problems/reverse-integer/
 * input: a 32-bit signed integer
 * output: reversed integer.
 * author: jishuguang
 * create: 20200821 
 */

#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while(x != 0) {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        if (result < INT_MIN || result > INT_MAX) {
            result = 0;
        }
        return result;
    }
};