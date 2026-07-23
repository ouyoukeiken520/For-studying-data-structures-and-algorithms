struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *node = head;
    ListNode *newhead = head;
    while (node->next != nullptr) {
      node = node->next;
    }
    newhead = node;
    node = head;
    while (node->next != nullptr) {
      while (node->next->next != nullptr) {
        node = node->next;
      }
      node->next->next = node;
      node->next = nullptr;
      node = head;
    }
    return newhead;
  }
};