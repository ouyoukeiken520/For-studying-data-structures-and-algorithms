#include <iostream>
#include <ostream>
using namespace std;
template <typename T> class stack {
  struct Node {
    T element;
    Node *next;
    Node(T value) : element(value), next(nullptr) {}
  };
  Node *topNode;

public:
  stack() : topNode(nullptr) {}
  // 入栈
  void push(T element) {
    Node *newNode = new Node(element);
    newNode->next = topNode;
    topNode = newNode;
  }
  // 出栈
  T pop() {
    if (topNode == nullptr) {
      cout << "栈为空，无法弹出元素。" << endl;
      return T();
    }
    Node *temp = topNode;
    topNode = topNode->next;
    T value = temp->element;
    delete temp;
    return value;
  }
  // 获取栈顶元素
  T peek() {
    if (topNode == nullptr) {
      cout << "栈为空，无法获取栈顶元素。" << endl;
      return T();
    }
    return topNode->element;
  }
  // 打印栈表
  void print() {
    if (topNode == nullptr) {
      cout << "栈为空。" << endl;
      return;
    }
    cout << "栈中的元素为：";
    Node *current = topNode;
    while (current != nullptr) {
      cout << current->element << " ";
      current = current->next;
    }
    cout << endl;
  }
};

int main() {
  // 测试代码
  stack<int> myStack;
  myStack.push(10);
  myStack.push(20);
  myStack.push(30);
  myStack.print(); // 输出 30 20 10
  myStack.pop();
  myStack.print(); // 输出 20 10
  return 0;
}