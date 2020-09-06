/* source: 5491 https://leetcode-cn.com/problems/matrix-diagonal-sum/
 * input: a square matrix
 * output: the sum of the matrix diagonals.
 * author: jishuguang
 * create: 20200905
 */

#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int result = 0;
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            result += mat[i][i];
            if (i != n - 1 - i) {
                result += mat[i][n - 1 -i];
            }
        }
        return result;        
    }
};