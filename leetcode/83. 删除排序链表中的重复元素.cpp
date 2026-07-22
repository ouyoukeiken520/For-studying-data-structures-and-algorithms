struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *node = new ListNode;
    node = head;
    while (node->next != nullptr && node->next->next != nullptr) {
      if (node->val == node->next->val) {
        ListNode *tmp = new ListNode;
        tmp = node->next;
        node->next = node->next->next;
        delete tmp;
        continue;
      }
      node = node->next;
    }
    return head;
  }
};