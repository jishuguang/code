/* source: https://leetcode-cn.com/problems/two-sum/
 * input: an array of integers
 * output: return indices of the two numbers such that they add up to a specific target
 * author: jishuguang
 * create: 20200426
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// unordered_map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> num_map;
        int size = nums.size();
        for (int i = 0; i != size; ++i) {
            auto it = num_map.find(target - nums[i]);
            if (it != num_map.end()) {
                result = {it->second, i};
                break;
            }
            num_map.insert({nums[i], i});
        }
        return result;
    }
};

// unordered_multimap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_multimap<int, int> num_map;
        auto size = nums.size();
        for (int i = 0; i != size; ++i) {            
            num_map.insert({nums[i], i});
        }
        for (const auto& num : num_map) {
            int partner = target - num.first;
            auto it_pair = num_map.equal_range(partner);
            if (it_pair.first != it_pair.second) {
                auto begin = it_pair.first;
                if (begin->first == num.first) {
                    if (++begin != it_pair.second) {
                        result = {it_pair.first->second, begin->second};
                        break;
                    }
                } else {
                    result = {num.second, begin->second};
                    break;
                }
            }            
        }
        return result;
    }
};

// two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result_nums;
        vector<int> result_indexs;
        vector<int> origin_nums = nums;
        sort(nums.begin(), nums.end());        
        int begin = 0;
        int end = nums.size() - 1;
        while (begin < end) {
            int sum = nums[begin] + nums[end];
            if (sum == target) {
                result_nums = {nums[begin], nums[end]};
                break;
            } else if (sum > target) {
                --end;
            } else {
                ++begin;
            }
        }
        int size = origin_nums.size();
        for (int i = 0; i < size; ++i) {
            if (origin_nums[i] == result_nums[0] || origin_nums[i] == result_nums[1]) {
                result_indexs.push_back(i);
            }
        }
        return result_indexs;
    }
};