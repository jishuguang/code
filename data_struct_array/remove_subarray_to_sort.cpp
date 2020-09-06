/* source: 5493 https://leetcode-cn.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
 * input: an integer array
 * output: Return the length of the shortest subarray to remove.
 * author: jishuguang
 * create: 20200905
 */

#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // get first and last int that violates the rule
        int first = 0;
        int last = 0;
        int len = arr.size();
        for (int i = 1; i < len; ++i) {
            if (arr[i - 1] > arr[i]) {
                if (first == 0) {
                    first = i;
                    last = i - 1;
                } else {
                    last = i - 1;
                }
            }
        }

        int result = 0;
        if (first != 0) {
            result = last - first + 1; // first to last
            // left numbers we need to remove
            int left = first - 1;   
            int left_amount = 0;             
            while (left > -1) {
                if (arr[left] <= arr[last + 1]) {
                    break;
                }
                ++left_amount;
                --left;
            }
            // right numbers we need to remove
            int right = last + 1;   
            int right_amount = 0;             
            while (right < len) {
                if (arr[first - 1] <= arr[right]) {
                    break;
                }
                ++right_amount;
                ++right;
            }
            result += right_amount < left_amount ? right_amount : left_amount;
        }   
        return result;
    }
};