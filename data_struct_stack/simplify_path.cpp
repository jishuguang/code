#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> path_elems;
        auto pos = path.find_first_of('/');
        while(pos != string::npos) {
            
        }
        handle_str(path.substr(pos))
        return "";
    }
};

int main()
{
    Solution s;
    string str = "";
    cout << s.simplifyPath(str);
    return 0;
}