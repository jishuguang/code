/* source: 8 https://leetcode-cn.com/problems/string-to-integer-atoi/
 * input: a string
 * output: a integer
 * author: jishuguang
 * time: 20200822
 */

#include <string>
#include <cctype>
using namespace std;

enum State {
    START,
    DIGIT,
    END
};

class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        int mul = 1;
        State state = State::START;
        for (const char& c : str) {
            switch (state) {
                case State::START: {
                    if (c != ' ') {
                        if (c == '-') {                        
                            mul = -1;
                            state = State::DIGIT;
                        } else if (c == '+') {
                            mul = 1;
                            state = State::DIGIT;
                        } else if (isdigit(c)) {
                            result = c - '0';
                            state = State::DIGIT;
                        } else {
                            state = State::END;
                        }
                    }
                    break;   
                }
                case State::DIGIT: {
                    if (isdigit(c)) {
                        result = result * 10 + (c - '0') * mul;
                        if (result < INT_MIN) {
                            result = INT_MIN;
                            state = State::END;
                        } else if (result > INT_MAX) {
                            result = INT_MAX;
                            state = State::END;
                        }
                    } else {
                        state = State::END;
                    }
                    break;
                }
                case State::END:
                    return result;
            }
        }
        return result;
    }
};