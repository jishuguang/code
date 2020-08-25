/* source: 15 https://leetcode-cn.com/problems/3sum/
 * input: an array of integers
 * output: all unique triplets
 * author: jishuguang
 * create: 20200825
 */

#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

// two pointer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int begin = 0;     
        while (begin < len - 2) {
            int cur_value = nums[begin];
            int two_sum = 0 - cur_value;
            int left = begin + 1;
            int right = len - 1;
            while (left < right) {
                int left_value = nums[left];
                int right_value = nums[right];
                if (nums[left] + nums[right] == two_sum) {
                    result.push_back({cur_value, left_value, right_value});
                    while (++left < right && nums[left] == left_value) {}
                    while (--right > left && nums[right] == right_value) {}
                } else if (nums[left] + nums[right] > two_sum) {
                    while (--right > left && nums[right] == right_value) {}
                } else {
                    while (++left < right && nums[left] == left_value) {}
                }
            }
            while (++begin < len - 2 && nums[begin] == cur_value) {}
        }
        return result;
    }
};

// unordered_map
/* 执行用时：2896 ms, 在所有 C++ 提交中击败了5.00% 的用户
 * 内存消耗：263.6 MB, 在所有 C++ 提交中击败了5.02% 的用户
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> num_map;
        for (const int& n : nums) {
            num_map[n] += 1;
        }
        vector<vector<int>> result;
        for(auto it = num_map.begin(); it != num_map.end(); ++it) {
            it->second--;
            // two sum
            unordered_map<int, int> tmp_map(it, num_map.end());
            for (auto iit = tmp_map.begin(); iit != tmp_map.end(); ++iit) {
                if (iit->second == 0) {
                    continue;
                }
                iit->second--;
                auto find_it = tmp_map.find(0 - it->first - iit->first);
                if (find_it != tmp_map.end() && find_it->second != 0) {
                    result.push_back({it->first, iit->first, find_it->first});
                }
                iit->second = 0;
            }

            it->second = 0;
        }
        return result;
    }
};