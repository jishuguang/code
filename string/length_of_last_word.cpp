/*
 * Source: https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&tqId=21224&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
 * Problem: 计算字符串最后一个单词的长度，单词以空格隔开。
 * Input: 一行字符串，非空，长度小于5000。
 * Output: 整数N，最后一个单词的长度。
 *
 * Author: jishuguang
 * Email: shuguangj@126.com
 * CreateTime: 20190915
 */
#include <Windows.h>

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	// getline(cin, s);
	unsigned i = s.size() - 1;
	unsigned length = 0;
	while (i > 0) {
		char c = s.at(i);
		if (length == 0 && c == ' ') {
			i--;
		}
		else if (c != ' ') {
			length += 1;
			i--;
		}
		else {
			break;
		}
	}
	if (i == 0) {
		length += 1;
	}
	cout << length << endl;
	system("pause");
	return 0;
}