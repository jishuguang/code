
# Source: https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&tqId=21224&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
# Problem: 计算字符串最后一个单词的长度，单词以空格隔开。
# Input: 一行字符串，非空，长度小于5000。
# Output: 整数N，最后一个单词的长度。

# Author: jishuguang
# Email: shuguangj@126.com
# CreateTime: 20190915

def main():
    print(len(input().strip().split()[-1]))

if __name__ == '__main__' :
    main()