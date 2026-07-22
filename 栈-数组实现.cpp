#include <iostream>
using namespace std;
template <typename T> class stack {
  T *arr;
  int top;
  int capacity;

public:
  stack(int capacity = 10) {
    arr = new T[capacity];
    top = -1;
    this->capacity = capacity;
  }
//入栈  
  void push(T element) {
    if (top == capacity - 1) {
      T *newArr = new T[capacity * 2];
      for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];
      }
      delete[] arr;
      arr = newArr;
      capacity *= 2;
    }
    arr[++top] = element;
  }
//出栈  
  T pop() {
    if (top == -1) {
      cout << "栈为空，无法弹出元素。" << endl;
      return T();
    }
    return arr[top--];
  }
//获取栈顶元素  
  T peek() {
    if (top == -1) {
      cout << "栈为空，无法获取栈顶元素。" << endl;
      return T();
    }
    return arr[top];
  }
// 打印栈表
  void print() {
    if (top == -1) {
      cout << "栈为空。" << endl;
      return;
    }
    cout << "栈中的元素为：";
    for (int i = 0; i <= top; i++) {
      cout << arr[i] << " ";
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