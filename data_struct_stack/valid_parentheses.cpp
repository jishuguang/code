/* source: 20 https://leetcode-cn.com/problems/valid-parentheses/
 * author: jishuguang
 * create: 20200828
 * input: a string containing just the characters '(', ')', '{', '}', '[' and ']'
 * output: if the input string is valid.
 */

#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool valid = true;     
        stack<char> parens;        
        for (auto& c : s) {
            auto find = par_map.find(c);
            if (find == par_map.end()) {
                parens.push(c);
            } else if (!parens.empty() && find->second == parens.top()) {
                parens.pop();
            } else {
                valid = false;
                break;
            }
        } 
        if (!parens.empty()) {
            valid = false;
        }
        return valid;
    }
private:
    static const unordered_map<char, char> par_map;
};

const unordered_map<char, char> Solution::par_map = {
    {')', '('},
    {']', '['},
    {'}', '{'}
};