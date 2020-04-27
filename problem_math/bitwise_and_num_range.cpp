/* source: https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
 * input: Given a range [m, n] where 0 <= m <= n <= 2147483647
 * output: return the bitwise AND of all numbers in this range, inclusive
 * author: jishuguang
 * create: 20200427
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        m <<= i;
        return m;
    }
};

int main()
{
    int m, n;
    Solution s;
    while (cin >> m >> n) {
        cout << s.rangeBitwiseAnd(m, n) << endl;
    }
}