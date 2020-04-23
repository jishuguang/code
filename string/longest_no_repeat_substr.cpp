/* source: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * input: a string
 * output: the length of the longest substring without repeating characters.
 * keyword: slide window
 * author: jishuguang
 * time: 20200423
 */

#include <iostream>
#include <map>
using namespace std;

class Solution {
    using char_dict = map<char, size_t>;
    int longest = 0;
    void updateLongest(int cur_length)
    {
        if (longest < cur_length) {
            longest = cur_length;
        }
    }
public:
    int lengthOfLongestSubstring(string s)
    {
        size_t win_start = 0;
        size_t win_end = 0;
        char_dict cd;
        for (const auto& c : s) {
            auto cd_pair = cd.find(c);
            if (cd_pair != cd.end()) {
                size_t new_start = cd_pair->second + 1;
                for (size_t i = win_start; i < new_start; ++i) {
                    cd.erase(s[i]);
                }
                updateLongest(win_end - win_start);
                win_start = new_start;
            }
            cd[c] = win_end++;
        }
        updateLongest(win_end - win_start);
        return longest;
    }
};