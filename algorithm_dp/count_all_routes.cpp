/* source: 5494 https://leetcode-cn.com/problems/count-all-possible-routes/
 * input: locations, start, finish and fuel
 * output: the count of all possible routes from start to finish
 * author: jishuguang
 * time: 20200906
 */

#include <vector>
#include <cstdlib>
using namespace std;

// dp
class Solution {
public:
    bool canDirect(vector<int>& locations, int start, int finish, int fuel) {
        return (start != finish) && (fuel >= abs(locations[start] - locations[finish]));
    }
    int add(const int& first, const int& second) {        
        int result = 0;
        if (second > MOD - first) {
            result = second - (MOD - first);
        } else {
            result = first + second;
        }
        return result;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {   
        int len = locations.size();
        int result[len][fuel + 1];
        for (int f = 0; f < fuel + 1; ++f) {
            for (int i = 0; i < len; ++i) {
                if (f == 0) { // no fuel
                    result[i][f] = 0;                        
                } else {
                    result[i][f] = canDirect(locations, start, i, f) ? 1 : 0;
                    for (int j = 0; j < len; ++j) {
                        if (canDirect(locations, j, i, f)) {
                            int cost = abs(locations[j] - locations[i]);
                            result[i][f] = add(result[i][f], result[j][f - cost]);
                        }                            
                    }
                }
            }
        }
        return add(result[finish][fuel], (start == finish ? 1 : 0));
    }
private:
    static const int MOD = 1000000007;    
};

// dp : extra calculation leads to beyond time limit
/*
class Solution {
public:
    int add(const int& first, const int& second) {        
        int result = 0;
        if (second > MOD - first) {
            result = second - (MOD - first);
        } else {
            result = first + second;
        }
        return result;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {   
        if (start > finish){
            return countRoutes(locations, finish, start, fuel);
        }
        int len = locations.size();
        bool can_direct[len][len][fuel + 1];
        for (int k = 0; k < fuel + 1; ++k) {
            for (int i = 0; i < len; ++i) {
                for (int j = i; j < len; ++j) {                    
                    can_direct[i][j][k] = (i != j) && (k >= abs(locations[i] - locations[j]));
                }
            }
        }
        int result[len][len][fuel + 1];
        for (int k = 0; k < fuel + 1; ++k) {
            for (int i = 0; i < len; ++i) {
                for (int j = i; j < len; ++j) {                    
                    if (k == 0) { // no fuel
                        result[i][j][k] = 0;                        
                    } else {
                        result[i][j][k] = can_direct[i][j][k] ? 1 : 0;
                        for (int m = 0; m < len; ++m) {
                            bool can_dir = m <= j ? can_direct[m][j][k] : can_direct[j][m][k];
                            if (can_dir) {
                                int cost = abs(locations[m] - locations[j]);
                                int increment = i <= m ? result[i][m][k - cost] : result[m][i][k - cost];
                                result[i][j][k] = add(result[i][j][k], increment);
                            }                            
                        }
                    }
                }
            }
        }
        return add(result[start][finish][fuel], (start == finish ? 1 : 0));
    }
private:
    static const int MOD = 1000000007;    
};
*/

// recursion: too slow
/*
class Solution {
public:
    void countRoutes(vector<int>& locations, int start, int finish, int fuel, long long& result) {
        if (fuel < 0) {
            return;
        }
        if(start == finish) {
            ++result;
        }
        int len = locations.size();
        for (int i = 0; i < len; ++i) {
            if (i == start) {
                continue;
            }
            int cost = abs(locations[i] - locations[start]);
            countRoutes(locations, i, finish, fuel - cost, result);
        }
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        long long result = 0;
        countRoutes(locations, start, finish, fuel, result);
        return result % MOD;
    }
private:
    static const int MOD = 1000000007;
};
*/