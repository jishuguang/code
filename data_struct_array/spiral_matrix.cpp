/* source: https://leetcode-cn.com/problems/spiral-matrix/
 * input: a matrix of m x n elements
 * output: return all elements of the matrix in spiral order
 * author: jishuguang
 * create: 20200426
 */

#include <vector>
using namespace std;

class Solution {
    using mtx = vector<vector<int>>;
    int x_min = 0;
    int x_max = 0;
    int y_min = 0;
    int y_max = 0;
    int cur_x = 0;
    int cur_y = 0;
    mtx cur_matrix;
    vector<int> result;
    void addCurrent() {
        result.push_back(cur_matrix[cur_y][cur_x]);
    }
    void setup(mtx& matrix) {
        cur_matrix = matrix;
        y_max = cur_matrix.size() - 1;
        if (y_max >= 0) {
            x_max = cur_matrix[0].size() - 1;
        }
    }
    bool goRight() {
        if (cur_x >= x_max) {
            return false;
        }
        while (cur_x < x_max) {
            ++cur_x;
            addCurrent();
        }
        ++y_min;
        return true;
    }
    bool goDown() {
        if (cur_y >= y_max) {
            return false;
        }
        while (cur_y < y_max) {
            ++cur_y;
            addCurrent();
        }
        --x_max;
        return true;
    }
    bool goLeft() {
        if (cur_x <= x_min) {
            return false;
        }        
        while (cur_x > x_min) {
            --cur_x;
            addCurrent();
        }
        --y_max;
        return true;
    }    
    bool goUp() {
        if (cur_y <= y_min) {
            return false;
        }                
        while (cur_y > y_min) {
            --cur_y;
            addCurrent();
        }
        ++x_min;
        return true;
    }    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        setup(matrix);
        // empty
        if (y_max < 0 || x_max < 0) {
            return result;
        }
        // not empty
        addCurrent();  // [0][0]
        // single clomn
        if (x_max == 0) {
            goDown();
            return result;
        }
        // normal 
        while (goRight() && goDown() && goLeft() && goUp()); // null statement
        return result;
    }
};