#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int first = 0;
        int second = 0;
        int len = arr.size();
        for (int i = 1; i < len; ++i) {
            if (arr[i] < arr[i - 1]) {
                if (first == 0) {
                    first = i;
                    second = i;
                } else {
                    second = i;
                }
            }
        }
        int result = 0;
        if (first == 0) {
            return result;
        }
        if (second != first) {
            second -= 1;
        }
        result = second - first + 1;
        if (second == len - 1) {
            return result;
        }
        int left = first - 1;   
        int left_amount = 0;             
        while (left > -1) {
            if (arr[left] > arr[second + 1]) {
                ++left_amount;
            } else {
                break;
            }
            --left;
        }
        int right = second + 1;   
        int right_amount = 0;             
        while (right < len) {
            if (arr[right] < arr[first - 1]) {
                ++right_amount;
            } else {
                break;
            }
            ++right;
        }
        result += right_amount < left_amount ? right_amount : left_amount;
        return result;
    }
};

int main() {
    int i1 = 1 + 2;
    int *i2(&i1);
    int *i3(i2);
    cout << *i3 << endl;
    cout << i3[0] << endl;
    cout << i3[1] << endl;
    cout << i3[2] << endl;
    cin >> i1;
}