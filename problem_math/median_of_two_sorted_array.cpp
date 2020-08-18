/* source: 4 https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * input: two sorted arrays nums1 and nums2 
 * output: the median
 * author: jishuguang
 * time: 20200817
 */

#include <vector>
#include <algorithm>
using namespace std;

// O(log(m+n))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        isEven = (m + n) % 2 == 0;
        int k = isEven ? (m + n) / 2 : (m + n) / 2 + 1;
        return findMedian(m, n, k, nums1, nums2);
    }
    double findMedian(int m, int n, int k, vector<int>& nums1, vector<int>& nums2)
    {   
        if (m == 0) {
            return isEven ? (nums2[n - k] + nums2[n - k - 1]) / 2.0 : nums2[n - k];
        }
        if (n == 0) {
            return findMedian(n, m, k, nums2, nums1);
        }
        if (k == 1) {
            if (nums1[m - 1] >= nums2[n - 1]) {
                int second_max = (m > 1 && nums1[m - 2] >= nums2[n - 1]) ? nums1[m - 2] : nums2[n - 1];
                return isEven ? (nums1[m - 1] + second_max) / 2.0 : nums1[m - 1];
            } else {
                return findMedian(n, m, k, nums2, nums1);
            }
        }
        int half_k = k / 2;
        if (half_k >= m) {
            if (nums1[0] >= nums2[n - half_k - (half_k - m)]) {
                int index = n - (k - m);
                return isEven ? (nums2[index] + nums2[index - 1]) / 2.0 : nums2[index];
            } else {
                n -= half_k;
            }
        } else if (half_k >= n) {
            return findMedian(n, m, k, nums2, nums1);
        } else {
            if (nums1[m - half_k] >= nums2[n - half_k]) {
                m -= half_k;
            } else {
                n -= half_k;
            }            
        }
        return findMedian(m, n, k - half_k, nums1, nums2);
    }
private:
    bool isEven;
};

// O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size =  size1 + size2;
        vector<int> nums(vector<int>(size, 0));        
        int i1 = 0;
        int i2 = 0;
        int i = 0;
        while (i1 < size1 && i2 < size2) {
            int current_int = nums1[i1] < nums2[i2] ? nums1[i1++] : nums2[i2++];            
            nums[i++] = current_int;
        }
        if (i1 < size1) {
            copy_backward(nums1.begin() + i1, nums1.end(), nums.end());
        }
        if (i2 < size2){
            copy_backward(nums2.begin() + i2, nums2.end(), nums.end());
        }
        double result = (size % 2 == 0) ? (nums[size / 2 - 1] + nums[size / 2]) / 2.0 : nums[size / 2];
        return result;
    }
};