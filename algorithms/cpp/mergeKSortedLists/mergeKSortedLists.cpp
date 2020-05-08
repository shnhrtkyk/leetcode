class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    while (true) {
      ListNode** min_head = nullptr;
      for (auto& head : lists) {          
        if (!head) continue;        
        if (!min_head || head->val < (*min_head)->val)
          min_head = &head;
      }
      if (!min_head) break;
      cur->next = new ListNode((*min_head)->val);
      cur = cur->next;
      *min_head = (*min_head)->next;      
    }
    return dummy.next;
  }
};
