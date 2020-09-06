#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int numWays(string s) {
        int ones = 0;
        int len = s.size();
        for (char& c : s) {
            if (c == '1') {
                ++ones;
            }
        }
        if (ones > 0) {
            if (ones % 3 != 0) {
                return 0;
            }
        }
        long long mod = 1;
        for (int i = 0; i < 9; ++i) {
            mod *= 10;
        }
        mod += 7;
        long long result = 0;
        if (ones == 0) {
            result = (len - 2 + 1);
            result = (len - 2) * result / 2;
        }
        if (ones > 0) {
            int n = ones / 3;
            int first = 0;
            int second = 0;
            int k = 0;
            for (int i = 0; i < len; i++) {
                if (s[i] == '1') {
                    ++k;
                    continue;
                }
                if (k == n) {
                    ++first;
                }
                if (k == 2 * n) {
                    ++second;
                }
            }
            result = first + 1;
            result *= second + 1;            
        }
        return result % mod;
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