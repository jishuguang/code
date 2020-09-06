#include <string>
#include <vector>
#include <iostream>
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