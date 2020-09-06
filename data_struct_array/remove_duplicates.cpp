/* source: 26 https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * input: a sorted array
 * output: remove the duplicates in-place, and return the new length
 * author: jishuguang
 * create: 20200905
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        int i = 0;
        int j = 0;
        while (j < len) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
            ++j;
        }
        return i + 1;
    }
};