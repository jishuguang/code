/* source: 25 https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
 * input: linked list and k
 * output: modified list
 * author: jishuguang
 * time: 20200904
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reverseSingleGroup(ListNode* head, ListNode* tail) {        
        ListNode* post = tail->next;
        ListNode* cur = head->next;
        while (cur != post) {
            ListNode* next = cur->next;
            cur->next = head;
            head = cur;
            cur = next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2) {
            return head;
        }
        ListNode node(0);
        node.next = head;
        ListNode* pre = &node;        
        while(pre->next != nullptr) {
            // record head
            head = pre->next;
            // find tail
            ListNode* tail = pre;        
            for (int i = 0; i < k; ++i) {
                if (tail->next == nullptr) {
                    return node.next;
                }
                tail = tail->next;
            }
            // record post
            ListNode* post = tail->next;
            // reverse
            reverseSingleGroup(head, tail);
            pre->next = tail;
            head->next = post;
            pre = head;
        }
        return node.next;        
    }
};

int main() {
    Solution s;
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;
    s.reverseKGroup(&node1, 2);    
}