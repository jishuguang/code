/* source: 18 https://leetcode-cn.com/problems/4sum/
 * input: an array of integers
 * output: all unique quadruplets
 * author: jishuguang
 * create: 20200827
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int size = nums.size();
        if (size < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int first = 0;
        while (first < size - 3) {
            int first_value = nums[first];
            int second = first + 1;
            while (second < size - 2) {
                int second_value = nums[second];
                int left = second + 1;
                int right = size - 1;
                while (left < right) {
                    int left_value = nums[left];
                    int right_value = nums[right];
                    int cur_sum = first_value + second_value + left_value + right_value;
                    if (cur_sum == target) {
                        result.push_back({first_value, second_value, left_value, right_value});
                    }
                    if (cur_sum >= target) {
                        while (--right > left && nums[right] == right_value) { }
                    } 
                    if (cur_sum <= target) {
                        while (right > ++left && nums[left] == left_value) { }
                    }
                }
                while (++second < size - 2 && nums[second] == second_value) { }
            }
            while (++first < size - 3 && nums[first] == first_value) { }
        }
        return result;
    }
};