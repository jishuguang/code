/* source: 10 https://leetcode-cn.com/problems/regular-expression-matching/
 * input: a string & a pattern
 * output: bool, the matching should cover the entire input string (not partial).
 * author: jishuguang
 * time: 20200823
 */

#include <string>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    vector<pair<char, bool>> getPattern(const string& p) {
        vector<pair<char, bool>> pattern;  // {char, is_star}
        int p_len = p.size();
        for (int i = 0; i < p_len; ++i) {
            bool is_star = (i < p_len - 1) && (p[i + 1] == '*');
            pattern.push_back({p[i], is_star});
            if (is_star) {
                ++i;
            }
        }
        return pattern;
    }
    bool isCharMatch(char& s, char& p) {
        return p == '.' || s == p;
    }
    bool isMatch(string s, string p) {
        int s_len = s.size();
        auto pattern = getPattern(p);
        int p_len = pattern.size();
        // special case: empty pattern
        if (p_len == 0) {
            return s_len == 0;
        }        
        // empty s is the first row
        vector<vector<bool>> is_match(s_len + 1, vector<bool>(p_len, false));
        // handle first row
        is_match[0][0] = pattern[0].second;
        for (int i = 1; i < p_len; ++i) {
            is_match[0][i] = pattern[i].second && is_match[0][i - 1];
        }
        // handle first clomn
        for (int i = 0; i < s_len; ++i) {
            if (pattern[0].second) {
                is_match[i + 1][0] = is_match[i][0] && isCharMatch(s[i], pattern[0].first);
            } else {
                is_match[i + 1][0] = (i == 0) && isCharMatch(s[i], pattern[0].first);
            }
        }
        // handle real chars in s
        for (int i = 0; i < s_len; ++i) {
            for (int j = 1; j < p_len; ++j) {
                if (pattern[j].second) {
                    if (is_match[i + 1][j - 1]) {
                        is_match[i + 1][j] = true;
                    } else {
                        is_match[i + 1][j] =  (is_match[i][j - 1] || is_match[i][j]) && isCharMatch(s[i], pattern[j].first);
                    }
                } else {
                    is_match[i + 1][j] = is_match[i][j - 1] && isCharMatch(s[i], pattern[j].first);
                }                
            }
        }
        return is_match[s_len][p_len - 1];
    }
};

int main() {
    Solution sl;
    string s, p;
    while (cin >> s >> p) {
        cout << sl.isMatch(s, p);
    }
}