/* source: lcp17 https://leetcode-cn.com/problems/nGK0Fy/
 * input: a string
 * output: the sum of x and y.
 * author: jishuguang
 * time: 20200912
 */

#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int x = 1;
        int y = 0;
        for (char& c : s) {
            if (c == 'A') {
                x = 2 * x + y;
            } else {
                y = 2 * y + x;
            }
        }
        return x + y;
    }
};