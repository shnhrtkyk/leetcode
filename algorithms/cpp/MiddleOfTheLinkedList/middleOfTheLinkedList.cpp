/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
		ListNode *cur = head;
        int cnt = 0;
		while (cur) {
			++cnt;
            cur = cur->next;
		}
        cnt /= 2;
        while (cnt > 0) {
            --cnt;
            head = head->next;
        }
		return head;
    }
};

