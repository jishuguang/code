/* source: https://leetcode-cn.com/problems/simplify-path/
 * author: jishuguang
 * create: 20200417
 * input: an absolute path for a file, e.g., /home//foo/
 * output: the canonical path, e.g. /home/foo
 */

#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void pushStr(stack<string>& elems, string str) {
        if (str.empty() || str == ".") {
            return;
        }
        if (str == "..") {
            if (!elems.empty()) {
                elems.pop();
            }
            return;
        }
        elems.push(str);
    }
    string toString(stack<string>& elems) {
        string path = "";
        while(!elems.empty()) {
            path = "/" + elems.top() + path;
            elems.pop();
        }
        if (path == "") {
            return "/";
        } else {
            return path;
        }
    }
    string simplifyPath(string path) {
        stack<string> path_elems;
        string::size_type cur_pos = 0;
        string::size_type next_pos = 0;
        while((next_pos = path.find_first_of('/', cur_pos + 1)) != string::npos) {
            pushStr(path_elems, path.substr(cur_pos + 1, next_pos - cur_pos - 1));
            cur_pos = next_pos;
        }
        pushStr(path_elems, path.substr(cur_pos + 1));
        return toString(path_elems);
    }
};

int main()
{
    Solution s;
    string str;
    while(cin >> str) {
        cout << s.simplifyPath(str) << endl;
    }
    getchar();
    return 0;
}