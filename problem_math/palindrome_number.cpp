/* source: 9 https://leetcode-cn.com/problems/palindrome-number/
 * input: a number
 * output: bool
 * author: jishuguang
 * time: 20200823
 */

#include <deque>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        bool is_palindrome = true;
        deque<int> nums;
        while (x != 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
        while (!nums.empty()) {
            if (nums.back() != nums.front()) {
                is_palindrome = false;
                break;
            }
            nums.pop_back();
            if (!nums.empty()) {
                nums.pop_front();
            }
        }
        return is_palindrome;
    }
};