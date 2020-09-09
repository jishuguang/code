/* source: 29 https://leetcode-cn.com/problems/divide-two-integers/
 * input: two ints
 * output: Return the quotient 
 * author: jishuguang
 * time: 20200909
 */

#include <climits>
#include <cstdlib>
using namespace std;

class Solution {
public:
    unsigned convertToUnsigned(const int& i) {
        unsigned u = 0;
        if (i == INT_MIN) {
            u = 1u << 31;
        } else {
            u = abs(i);
        }
        return u;        
    }
    int getMaxBit(unsigned u) {
        int max = 0;
        while (u != 0) {
            u >>= 1;
            ++max;
        }
        return max;
    }
    int convertToSigned(const unsigned& u, const bool& negetive) {
        int result = 0;
        if (u == 1u << 31) {
            result = negetive ? INT_MIN : INT_MAX;
        } else {
            result = negetive ? -(int)u : u;
        }
        return result;
    }
    int divide(int dividend, int divisor) {
        bool negetive = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        unsigned udividend = convertToUnsigned(dividend);
        unsigned udivisor = convertToUnsigned(divisor);
        unsigned result = 0;
        if (udividend >= udivisor) {
            int shift = getMaxBit(udividend) - getMaxBit(udivisor);
            udivisor <<= shift;
            for (; shift >= 0; --shift) {
                result <<= 1;
                if (udividend >= udivisor) {
                    result += 1;
                    udividend -= udivisor; 
                }
                udivisor >>= 1;
            }
        }
        return convertToSigned(result, negetive);
    }
};