#include <iostream>
using namespace std;
template <class T>
class Queue {
  struct Node {
    T element;
    Node *next;
    Node() : next(nullptr) {}
    Node(const T &element) : element(element), next(nullptr) {}
  };
  Node *rear;
  Node *front;

public:
  Queue() {
    Node *node = new Node;
    rear = front = node;
  }
  ~Queue() {
    while (front != nullptr) {
      Node *temp = front;
      front = front->next;
      delete temp;
    }
  }
  void offerQueue(T ele) {
    Node *node = new Node(ele);
    rear->next = node;
    rear = node;
  }
  T pollQueue() {
    if (rear == front) {
      cout << "队列为空" << endl;
      return T();
    } else if (front->next == rear) {
      rear = front;    
    }
    Node *tmp = front->next;
    T ele = tmp->element;
    front->next = front->next->next;
    delete tmp;
    return ele;
  }
};

int main() {
  Queue<int> myQueue;

  cout << "=== 测试 1：大规模连续排队 (For 循环) ===" << endl;
  cout << "让 1 号到 10 号顾客依次排队..." << endl;
  for (int i = 1; i <= 10; ++i) {
    myQueue.offerQueue(i); // 1, 2, 3... 10
  }

  cout << "\n=== 测试 2：连续出队一部分 ===" << endl;
  cout << "前 5 个顾客买完离开: ";
  for (int i = 0; i < 5; ++i) {
    cout << myQueue.pollQueue() << " ";
  }
  cout << "(期望看到 1 2 3 4 5)" << endl;

  cout << "\n=== 测试 3：交替进出（模拟真实店铺客流） ===" << endl;
  // 此时队伍里还有：6, 7, 8, 9, 10
  cout << "新来 3 个人，同时走 3 个人: ";
  for (int i = 11; i <= 13; ++i) {
    myQueue.offerQueue(i);              // 11, 12, 13 入队
    cout << myQueue.pollQueue() << " "; // 6, 7, 8 出队
  }
  cout << "(期望看到 6 7 8)" << endl;

  cout << "\n=== 测试 4：打烊清场 (触发 rear = front 重置逻辑) ===" << endl;
  // 此时队伍里还有：9, 10, 11, 12, 13
  cout << "清空剩下的所有人: ";
  for (int i = 0; i < 5; ++i) {
    cout << myQueue.pollQueue() << " ";
  }
  cout << "(期望看到 9 10 11 12 13)" << endl;

  cout << "\n尝试在空店里叫号：" << endl;
  myQueue.pollQueue(); // 期望输出"队列为空"

  cout << "\n=== 测试 5：第二天重新开业 (验证指针是否安全复位) ===" << endl;
  cout << "顾客 99 和 100 排队..." << endl;
  myQueue.offerQueue(99);
  myQueue.offerQueue(100);
  cout << "出队: " << myQueue.pollQueue() << " (期望看到 99)" << endl;
  cout << "出队: " << myQueue.pollQueue() << " (期望看到 100)" << endl;

  cout << "\n=== 测试 6：泛型模板测试 (存字符串) ===" << endl;
  Queue<string> stringQueue; // T 变成了 string
  stringQueue.offerQueue("Alice");
  stringQueue.offerQueue("Bob");
  stringQueue.offerQueue("Charlie");

  cout << "字符串出队: " << stringQueue.pollQueue() << endl; // Alice
  cout << "字符串出队: " << stringQueue.pollQueue() << endl; // Bob

  return 0; // 程序结束时，~Queue() 会自动清理剩下的 "Charlie" 和虚拟节点
}