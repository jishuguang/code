/* source: 30 https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
 * input: a string s and an array of strings words of the same length
 * output: all starting indices of substring
 * author: jishuguang
 * time: 20200916
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;


/* rabin karp based: 764 ms 73.9 MB
int simple_hash(const string& s, const int& base, const int& mod) {
    int hash = 0;
    for (const char& c : s) {
        hash = (hash * base + c - 'a') % mod;        
    }
    return hash;
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {        
        int s_len = s.size();
        int words_len = words.size();
        int word_len = words[0].size();
        int window = word_len * words_len;
        if (s_len < window) {
            return {};
        }

        const int base = 26;
        const int mod = (INT_MAX - base + 1) / base;
        unordered_multimap<int, const string&> words_map(5000);
        for (auto& word : words) {
            words_map.insert({simple_hash(word, base, mod), word});
        }

        vector<int> s_hash(s_len - word_len + 1, 0);        
        int max_weight = 1;
        for (int i = 0; i < word_len; ++i) {
            s_hash[0] = (s_hash[0] * base + s[i] - 'a') % mod;
            max_weight = max_weight * base % mod;
        }
        for (int i = 1; i <= s_len - word_len; ++i) {
            s_hash[i] = s_hash[i - 1] * base - max_weight * (s[i - 1] - 'a') + (s[i + word_len - 1] - 'a');
            while (s_hash[i] < 0) {
                s_hash[i] += mod;
            }
            s_hash[i] %= mod;
        }

        vector<int> result;
        for (int i = 0; i < word_len; ++i) {            
            queue<pair<int, const string&>> word_queue;
            auto words_map_copy = words_map;
            int start = i;
            int end = i;
            while (end <= s_len - word_len) {           
                const int cur_hash = s_hash[end];
                const string& cur_word = s.substr(end, word_len);

                bool find = false;
                auto find_range = words_map_copy.equal_range(cur_hash);
                if (find_range.first != words_map_copy.end()) {                    
                    for (auto it = find_range.first; it != find_range.second; ++it) {
                        if (cur_word == it->second) {
                            word_queue.push(*it);
                            words_map_copy.erase(it);
                            find = true;
                            break;
                        }
                    }
                }

                if (!find) {
                    start += word_len;
                    while(!word_queue.empty()) {
                        auto& front = word_queue.front();
                        if (front.first == cur_hash && front.second == cur_word) {                                
                            word_queue.push(front);
                            word_queue.pop();
                            break;
                        }                            
                        words_map_copy.insert(front);
                        word_queue.pop();
                        start += word_len;
                    }
                } else {
                    if (words_map_copy.empty()) {
                        result.push_back(start);
                        words_map_copy.insert(word_queue.front());
                        word_queue.pop();
                        start += word_len;
                    }
                }
                end += word_len;
            }
        }
        return result;
    }
};
*/