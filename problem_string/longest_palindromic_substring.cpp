/* source: 5 https://leetcode-cn.com/problems/longest-palindromic-substring/
 * input: a string
 * output: the longest palindromic substring
 * author: jishuguang
 * time: 20200819
 */

#include <string>
using namespace std;

class Solution {
public:
    void updatePalindrome(int start, int end, const string& s, string& palindrome) {
        int length = s.size();
        while (start - 1 >= 0 && end + 1 < length && s[start - 1] == s[end + 1]) {
            --start;
            ++end;
        }
        int palindrome_length = end - start + 1;
        if (palindrome_length > palindrome.size()) {
            palindrome = s.substr(start, palindrome_length);
        }
    }
    string longestPalindrome(string s) {
        int length = s.size();
        if (length < 2) {
            return s;
        }        
        string longest_palindrome = s.substr(0, 1);
        int index = 0;
        while (++index < length) {
            if (s[index] == s[index - 1]) {
                updatePalindrome(index - 1, index, s, longest_palindrome);
            }
            if (index > 1 && s[index] == s[index - 2]) {
                updatePalindrome(index - 2, index, s, longest_palindrome);
            }
        }   
        return longest_palindrome;
    }
};