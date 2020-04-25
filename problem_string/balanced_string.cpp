/* source: https://leetcode-cn.com/problems/replace-the-substring-for-balanced-string/
 * input: a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'
 * output: Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.
 * author: jishuguang
 * time: 20200426 
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    using char_map = unordered_map<char, int>;
    char_map cm = {
        {'Q', 0},
        {'W', 0},
        {'E', 0},
        {'R', 0}
    };
    unsigned minimum = 100000;
    void updateMinimum(const int &start, const int &end) {
        auto current_num = end - start + 1;
        if (current_num < minimum) {
            minimum = current_num;
        }
    }
    bool isBalanced() {
        if (!cm.empty()) {
            for (auto &cm_pair : cm) {
                if (cm_pair.second > 0) {
                    return false;
                }
            }            
        }
        return true;
    }
    void setCharMap(const string &s) {
        for (auto &c: s) {
            ++cm[c];
        }
        int average = s.size() / 4;
        for (auto it = cm.begin(); it != cm.end();) {
            if (it->second <= average) {
                it = cm.erase(it);
            } else {
                it++->second -= average;                
            }
        }                
    }
public:
    int balancedString(string s) {
        setCharMap(s);
        if (isBalanced()) {
            return 0;
        }
        int win_start = 0;
        int win_end = 0;
        auto win_max = s.size();
        bool end_updated = true;
        while (win_end != win_max) {                        
            if (end_updated) {
                char c_end = s[win_end];
                if (cm.find(c_end) != cm.end()) {                
                    cm[c_end] -= 1;
                }
            }
            if (isBalanced()) {
                updateMinimum(win_start, win_end);                
                char c_start = s[win_start];
                if (cm.find(c_start) != cm.end()) {                
                    cm[c_start] += 1;
                }
                ++win_start;
                end_updated = false;
            } else {
                ++win_end;
                end_updated = true;
            }
        }
        return minimum;
    }
};

int main() {    
    string str;
    while(cin >> str) {
        Solution s;
        cout << s.balancedString(str) << endl;
    }
    return 0;
}