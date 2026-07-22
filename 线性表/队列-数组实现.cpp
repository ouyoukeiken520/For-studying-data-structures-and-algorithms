#include <iostream>
using namespace std;

template <class T>
class Queue {
  T *arr;
  int rear;
  int front;
  int capacty;

public:
  Queue(int capacty = 20) {
    arr = new T[capacty];
    this->capacty = capacty;
    rear = front = 0;
  }
  ~Queue() { delete[] arr; }

  // 入队
  void OfferQueue(T ele) {
    if ((rear + 1) % capacty == front) {
      cout << "队列已满，入队失败" << endl;
      return;
    }
    rear = (rear + 1) % capacty;
    arr[rear] = ele;
  }
  // 出队
  T pollQueue() {
    if (front == rear) {
      cout << "队列为空，出队失败" << endl;
      return T();
    }
    front = (front + 1) % capacty;
    return arr[front];
  }
  // 打印队列
  void print() {
    if (front == rear) {
      cout << "队列为空" << endl;
      return;
    }
    int i = (front + 1) % capacty;
    cout << "<<<";
    while (true) {
      cout << arr[i] << " ";
      if (i == rear) {
        break;
      }
      i = (i + 1) % capacty;
    }
    cout << "<<<" << endl;
  }
};
int main() {
  // 测试代码
  Queue<int> q(5);

  q.OfferQueue(10);
  q.OfferQueue(20);
  q.OfferQueue(30);
  q.OfferQueue(40);
  q.print(); // 输出: <<< 10 20 30 40 <<<

  q.OfferQueue(50); // 输出: 队列已满，入队失败

  cout << "出队元素: " << q.pollQueue() << endl; // 弹出 10
  q.print();                                     // 输出: <<< 20 30 40 <<<

  q.OfferQueue(50);   // 刚才弹出了一个，现在 50 可以正常入队（尾指针绕回数组头部）
  q.print(); // 输出: <<< 20 30 40 50 <<<
}