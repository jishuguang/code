/* source: 28 https://leetcode-cn.com/problems/implement-strstr/
 * input: two string
 * output: Return the index of the first occurrence of needle in haystack
 * author: jishuguang
 * time: 20200907
 */

#include <string>
using namespace std;

// two index
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }        
        int result = -1;
        int len_h = haystack.size();
        int len_n = needle.size();
        for (int i = 0; i < len_h - len_n + 1; ++i) {   
            if (haystack[i] != needle[0]) {
                continue;
            }
            bool find = true;
            for (int j = 1; j < len_n; ++j) {
                if (haystack[i + j] != needle[j]) {
                    find = false;
                    break;
                }
            }
            if (find) {
                result = i;
                break;
            }
        }
        return result;
    }
};

// substr
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }        
        int result = -1;
        int len_h = haystack.size();
        int len_n = needle.size();
        for (int i = 0; i < len_h - len_n + 1; ++i) {
            if (haystack.substr(i, len_n) == needle) {
                result = i;
                break;       
            }
        }
        return result;
    }
};