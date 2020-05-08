// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if (!head || k == 1) return head;
//         ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = head;
//         dummy->next = head;
//         for (int i = 1; cur; ++i) {
//             if (i % k == 0) {
//                 pre = reverseOneGroup(pre, cur->next);
//                 cur = pre->next;
//             } else {
//                 cur = cur->next;
//             }
//         }
//         return dummy->next;
//     }
//     ListNode* reverseOneGroup(ListNode* pre, ListNode* next) {
//         ListNode *last = pre->next, *cur = last->next;
//         while(cur != next) {
//             last->next = cur->next;
//             cur->next = pre->next;
//             pre->next = cur;
//             cur = last->next;
//         }
//         return last;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre;
//         dummy->next = head;
//         int num = 0;
//         while (cur = cur->next) ++num;
//         while (num >= k) {
//             cur = pre->next;
//             for (int i = 1; i < k; ++i) {
//                 ListNode *t = cur->next;
//                 cur->next = t->next;
//                 t->next = pre->next;
//                 pre->next = t;
//             }
//             pre = cur;
//             num -= k;
//         }
//         return dummy->next;
//     }
// };


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        for (int i = 0; i < k; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        ListNode *new_head = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = tail;
        while (head != tail) {
            ListNode *t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
};
