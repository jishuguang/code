/* source: 6 https://leetcode-cn.com/problems/zigzag-conversion/
 * input: a string
 * output: zigzag string
 * author: jishuguang
 * time: 20200820
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void update(string& result, const string& s, const int& index) {
        if (index < s.size()) {
            result += s[index];
        }
    }
    string convert(string s, int numRows) {
        if (s.empty() || numRows == 1) {
            return s;
        }
        int length = s.size();
        int seed = 0;
        int segment = 2 * (numRows - 1);
        vector<int> seeds;
        while(seed < length) {
            seeds.push_back(seed);
            seed += segment;
        }
        string result;
        int row = 0;
        while(row < numRows) {
            for (const int& seed : seeds) {                
                if (row == 0 || row == numRows - 1) {                    
                    update(result, s, seed + row);
                } else {
                    update(result, s, seed + row);
                    update(result, s, seed + (segment - row));
                }
            }
            ++row;
        }
        return result;
    }
};