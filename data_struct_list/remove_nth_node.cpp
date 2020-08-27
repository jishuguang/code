/* source: 19 https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * input: linked list and n
 * output: its head
 * author: jishuguang
 * time: 20200828
 */

struct ListNode {    
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* right = head;
        int i = 0;
        while (right->next != nullptr) {
            right = right->next;
            if (++i > n) {
                left = left->next;
            }
        }
        if (i == n - 1) {
            head = head->next;
        } else {
            left->next = left->next->next;
        }
        return head;
    }
};