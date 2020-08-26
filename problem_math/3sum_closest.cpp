/* source: 16 https://leetcode-cn.com/problems/3sum-closest/
 * input: an array of integers
 * output: the sum which is closest to target
 * author: jishuguang
 * create: 20200827
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];
        int size = nums.size();
        for (int begin = 0; begin < size - 2;) {
            int cur_num = nums[begin];
            int left = begin + 1;
            int right = size - 1;
            while (left < right) {
                int left_value = nums[left];
                int right_value = nums[right];
                int cur_sum = cur_num + right_value + left_value;
                if (abs(cur_sum - target) < abs(closest_sum - target)) {
                    closest_sum = cur_sum;
                }
                if (cur_sum == target) {
                    return target;
                } else if (cur_sum < target) {
                    while (++left < right && nums[left] == left_value) { }
                } else {
                    while (left < --right && nums[right] == right_value) { }
                }
            }
            while (++begin < size - 2 && nums[begin] == cur_num) { }
        }
        return closest_sum;
    }
};