#include <string>
#include <vector>
#include <iostream>
using namespace std;

// class Solution {
// public:
//     int abs(int& a, int& b) {
//         return a > b ? a - b : b - a;
//     }
//     void countRoutes(vector<int>& locations, int start, int finish, int fuel, long long& result) {
//         if (fuel <= 0) {
//             return;
//         }
//         int len = locations.size();
//         for (int i = 0; i < len; ++i) {
//             if (i == start) {
//                 continue;
//             }
//             int cost = abs(locations[i], locations[start]);
//             if (fuel < cost) {
//                 continue;
//             } 
//             if (i == finish) {
//               ++result;  
//             }
//             countRoutes(locations, i, finish, fuel - cost, result);
//         }
//     }
//     int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
//         long long result = 0;
//         if(start == finish) {
//             ++result;
//         }
//         countRoutes(locations, start, finish, fuel, result);
//         long long mod = 1;
//         for (int i = 0; i < 9; ++i) {
//             mod *= 10;
//         }
//         mod += 7;
//         return result % mod;
//     }
// };

class Solution {
public:
    int abs(int& a, int& b) {
        return a > b ? a - b : b - a;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {        
        int len = locations.size();
        long long result[len][len][fuel + 1];
        for (int k = 0; k < fuel + 1; ++k) {
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {                    
                    if (k == 0) {
                        result[i][j][k] = 0;
                    } else {
                        result[i][j][k] = 0;
                        if (i != j) {
                            int cost = abs(locations[i], locations[j]);
                            result[i][j][k] = cost > k ? 0 : 1;
                        }
                        for (int m = 0; m < len; ++m) {
                            if (m == i || m == j) {
                                continue;
                            }
                            int last = 0;
                            for (int n = 1; n < k; ++n) {
                                if (result[i][m][n] > last) {
                                    result[i][j][k] +=  result[m][j][k - n] * (result[i][m][n] - last);
                                    last = result[i][m][n];
                                }
                            }
                        }
                    }
                }
            }
        }
        long long mod = 1;
        for (int i = 0; i < 9; ++i) {
            mod *= 10;
        }
        mod += 7;
        return (result[start][finish][fuel] + (start == finish ? 1 : 0)) % mod;
    }
};

int main() {
    Solution s;
    vector<int> locations = {1,2,3};
    int a = s.countRoutes(locations, 0, 2, 3);
}