/* source: lcp18 https://leetcode-cn.com/problems/2vYnGI/
 * input: staples, drinks and money x
 * output: return the amount of combination (single staple and single drink)
 * author: jishuguang
 * create: 20200912
 */

#include <vector>
using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        const int len_max = 1e5;
        const int money_max = 1e5;
        const int mod = 1e9 + 7;

        vector<int> staple_count(len_max, 0);
        for (int& i : staple) {
            staple_count[i - 1] += 1;
        }
        for (int i = 1; i < len_max; ++i) {
            staple_count[i] += staple_count[i - 1];
        }

        int result = 0;
        for (int& i : drinks) {
            int staple_max = x - i;
            if (staple_max <= 0) {
                continue;
            }
            if (staple_max > money_max) {
                staple_max = money_max;
            }
            result += staple_count[staple_max - 1];
            if (result >= mod) {
                result -= mod;
            }
        }
        return result;
    }
};