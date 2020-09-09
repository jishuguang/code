/* source: 5492 https://leetcode-cn.com/problems/number-of-ways-to-split-a-string/
 * input: a binary string
 * output: Return the number of ways s can be split such that the number of characters '1' is the same in s1, s2, and s3.
 * author: jishuguang
 * time: 20200905
 */

#include <string>
using namespace std;

class Solution {
public:
    int mul(const int& first, const int& second) {
        int max_sec = MOD / first;
        int sec = second % max_sec;
        return sec * first - (MOD - max_sec * first) * (second / max_sec);
    }
    int numWays(string s) {
        // get the amount of one
        int ones = 0;
        for (char& c : s) {
            ones += c - '0';
        }

        int len = s.size();
        int result = 0;
        if (ones > 0) {
            if (ones % 3 == 0) {
                int first_zeros = 0;
                int second_zeros = 0;
                int third = ones / 3;
                int k = 0;
                for (int i = 0; i < len; i++) {
                    if (s[i] == '1') {
                        ++k;
                    } else if (k == third) {
                        ++first_zeros;
                    } else if (k == 2 * third) {
                        ++second_zeros;
                    }
                }
                result = mul(first_zeros + 1, second_zeros + 1);
            }
        } else {
            result = (len - 1) % 2 == 0 ? mul((len - 1) / 2, len - 2) : mul((len - 2) / 2, len - 1);
        }
        return result;
    }
private:
    static const int MOD = 1000000007;
};