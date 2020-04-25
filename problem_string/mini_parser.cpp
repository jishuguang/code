/* source: https://leetcode-cn.com/problems/mini-parser/
 * input: a nested list of integers represented as a string
 * output: deserialize it
 * author: jishuguang
 * time: 20200425
 */

#include <string>
#include <vector>

#include <sstream>
#include <cctype>
using namespace std;

class NestedInteger {
   public:
     // Constructor initializes an empty nested list.
     NestedInteger();

     // Constructor initializes a single integer.
     NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};

class Solution {
    bool isDigit(char& c) {
        return isdigit(c) || c == '-';
    }
    NestedInteger deserializeInterger(stringstream &ss) {
        int value;
        ss >> value;
        return NestedInteger(value);
    }
    NestedInteger deserializeList(stringstream &ss) {        
        NestedInteger ni;
        char c;
        ss >> c; // [
        while ((c = ss.peek()) != ']') {            
            if (isDigit(c)) {
                ni.add(deserializeInterger(ss));
            } else if (c == '[') {
                ni.add(deserializeList(ss));
            } else {
                // just ignore
                ss >> c;
            }
        }
        ss >> c; // ]
        return ni;
    }
public:
    NestedInteger deserialize(string s) {
        stringstream ss(s);
        char c = ss.peek();
        NestedInteger ni;
        if (isDigit(c)) {    
            ni = deserializeInterger(ss);
        } else {
            ni = deserializeList(ss);
        }
        return ni;
    }
};