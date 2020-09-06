/* source: 27 https://leetcode-cn.com/problems/remove-element/
 * input: a array
 * output: remove all instances of that value in-place and return the new length
 * author: jishuguang
 * create: 20200905
 */

#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int tail = nums.size();
        int i = 0;
        while (i < tail) {
            if (nums[i] == val) {
                --tail;
                int tmp = nums[tail];
                nums[tail] = nums[i];
                nums[i] = tmp;
            } else {
                ++i;
            }
        }
        return tail;
    }
};