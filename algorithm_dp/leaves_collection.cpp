/* source: lcp19 https://leetcode-cn.com/problems/UlBDOe/
 * input: leaves string
 * output: minimum operations
 * author: jishuguang
 * time: 20200912
 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// dp: O(n)
class Solution {
public:
    int minimumOperations(string leaves) {
        const int len = leaves.size();
        vector<int> dp_r(len, 0);  // all red
        vector<int> dp_ry(len, 0); // red + yellow
        vector<int> dp_ryr(len, 0); // red + yellow + red 
        for (int i = 0; i < len; ++i) {
            bool is_red = leaves[i] == 'r';
            // dp_r
            dp_r[i] = is_red ? 0 : 1;
            if (i > 0) {
                dp_r[i] += dp_r[i - 1];
            }

            // dp_ry
            if (i > 0) {
                dp_ry[i] = is_red ? 1 : 0;
                if (i == 1) {
                    dp_ry[i] += dp_r[i - 1];
                } else {
                    dp_ry[i] += min(dp_r[i - 1], dp_ry[i - 1]);
                }
            }

            // dp_ryr
            if (i > 1) {
                dp_ryr[i] = is_red ? 0 : 1;
                if (i == 2) {
                    dp_ryr[i] += dp_ry[i - 1];
                } else {
                    dp_ryr[i] += min(dp_ry[i - 1], dp_ryr[i - 1]);
                }
            }
        }
        return dp_ryr[len - 1];
    }
};

// O(n^2): too slow.
/*
class Solution {
public:
    int minimumOperations(string leaves) {
        const int len = leaves.size();
        int result = 0;
        // begin and end should be 'r'
        if (leaves[len - 1] != 'r') {
            ++result;
            leaves[len - 1] = 'r';
        }
        if (leaves[0] != 'r') {
            ++result;
            leaves[0] = 'r';
        }

        vector<pair<int, int>> amount(len, {0, 0});
        vector<int> ry_pos;
        vector<int> yr_pos;
        for (int i = 0; i < len; ++i) {
            if (leaves[i] == 'r') {
                amount[i].first = 1;
                if (i > 0 && leaves[i - 1] == 'y') {
                    yr_pos.push_back(i);
                }
            } else {
                amount[i].second = 1;
                if (i > 0 && leaves[i - 1] == 'r') {
                    ry_pos.push_back(i);
                }
            }
            if (i > 0) {
                amount[i].first += amount[i - 1].first;
                amount[i].second += amount[i - 1].second;
            }
        }

        //specail case
        int increment = INT_MAX;
        if (ry_pos.size() == 0) {
            increment = 1;
        } else if (ry_pos.size() == 1) {
            increment = 0;
        } else {
            int ry_len = ry_pos.size();
            int yr_len = yr_pos.size();
            for (int i = 0; i < ry_len; ++i) {
                for (int j = 0; j < yr_len; ++j) {
                    int ry = ry_pos[i];
                    int yr = yr_pos[j];
                    if (yr < ry) {
                        continue;
                    }
                    int cur_increment = (amount[ry].second - 1) + 
                        (amount[yr].first - 1 - amount[ry].first) + 
                        (amount[len - 1].second - amount[yr].second);
                    increment = cur_increment < increment ? cur_increment : increment;
                }
            }
        }
        result += increment;
        return result;
    }
};
*/