/* source: https://leetcode-cn.com/problems/two-sum/
 * input: an array of integers
 * output: return indices of the two numbers such that they add up to a specific target
 * author: jishuguang
 * create: 20200426
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_multimap<int, unsigned> num_map;
        auto size = nums.size();
        for (unsigned i = 0; i != size; ++i) {            
            num_map.insert({nums[i], i});
        }
        for (const auto &num_pair : num_map) {
            int partner = target - num_pair.first;
            if (partner == num_pair.first && num_map.count(partner) == 1) {
                continue;
            }
            auto equal_pair = num_map.equal_range(partner);            
            if (equal_pair.first != num_map.end()) {
                for(auto it = equal_pair.first; it != equal_pair.second; ++it) {
                    result.push_back(it->second);
                }
                if (num_map.count(partner) == 1) {
                    result.push_back(num_pair.second);
                }
                break;
            }
        }
        return result;
    }
};