#include <string>
using namespace std;
class link {
  struct Node {
    char ele;
    Node *next;
    Node(char s) {
      ele = s;
      next = nullptr;
    }
  };
  Node *head;

public:
  link() { head = nullptr; }

  void push(char s) {
    Node *newnode = new Node(s);
    newnode->next = head;
    head = newnode;
  }

  char pop() {
    if (!head)
      return '\0';
    Node *tmp = head;
    head = head->next;
    char a = tmp->ele;
    delete tmp;
    return a;
  }

  bool isEmpty() { return head == nullptr; }
};

class Solution {
public:
  bool isValid(string s) {
    int len = s.length();
    if (len % 2 == 1)
      return false;
    class link llink;
    for (int i = 0; i < len; ++i) {
      char c = s[i];
      if (c == '(' || c == '[' || c == '{') {
        llink.push(c);
      } else {
        if (llink.isEmpty())
          return false;
        if (c == ')') {
          if (llink.pop() != '(')
            return false;
        } else if (c == ']') {
          if (llink.pop() != '[')
            return false;
        } else {
          if (llink.pop() != '{')
            return false;
        }
      }
    }
    return llink.isEmpty();
  }
};