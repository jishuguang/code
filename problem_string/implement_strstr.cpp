/* source: 28 https://leetcode-cn.com/problems/implement-strstr/
 * input: two string
 * output: Return the index of the first occurrence of needle in haystack
 * author: jishuguang
 * time: 20200907
 */

#include <string>
#include <cmath>
using namespace std;

// Rabin Karp
class Solution {
public:
    int strStr(string haystack, string needle) {                
        if (needle.empty()) {
            return 0;
        }
        int needle_len = needle.size();
        int haystack_len = haystack.size();
        if (haystack_len < needle_len) {
            return -1;
        }

        const int BASE = 26;
        const int MOD = INT_MAX;

        long needle_hash = 0;
        long haystack_hash = 0;
        long max_weight = 1;
        for (int i = 0; i < needle_len; ++i) {
            needle_hash = (needle_hash * BASE + (needle[i] - 'a')) % MOD;
            haystack_hash = (haystack_hash * BASE + (haystack[i] - 'a')) % MOD;
            max_weight = max_weight * BASE % MOD;
        }
        
        int index = -1;
        for (int i = 0; i <= haystack_len - needle_len; ++i) {
            if (needle_hash == haystack_hash && haystack.substr(i, needle_len) == needle) {
                index = i;
                break;
            } else {
                haystack_hash = (haystack_hash * BASE - (haystack[i] - 'a') * max_weight + (haystack[i + needle_len] - 'a')) % MOD;
            }
        }
        return index;
    }
};

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