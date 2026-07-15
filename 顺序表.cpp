#include <iostream>
using namespace std;
template <typename T> class List {
  T *array;
  int capacity;
  int size;
public:
  List(int cap = 10) {
    capacity = cap;
    size = 0;
    array = new T[capacity];
  }
  ~List() {
    delete[] array;
  }
  // 随机插入
  void app(T ele, int index){
    if (size >= capacity) {
      capacity *= 2;
      T *newArray = new T[capacity];
      for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
      }
      delete[] array;
      array = newArray;
    }
    for (int i = size; i > index - 1; i--) {
      array[i] = array[i - 1];
    }
    array[index - 1] = ele;
    size++;
  }
//尾部添加
  void append(T ele) {
    if (size >= capacity) {
      capacity *= 2;
      T *newArray = new T[capacity];
      for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
      }
      delete[] array;
      array = newArray;
    }
    array[size] = ele;
    size++;
  }
//删除元素
  void remove(int index) {
    if (index < 1 || index > size) {
      cout << "错误位序" << endl;
      return;
    }
    for (int i = index - 1; i < size - 1; i++) {
      array[i] = array[i + 1];
    }
    size--;
  }
// 查找元素
  int find(T ele) {
    for (int i = 0; i < size; i++) {
      if (array[i] == ele) {
        return i + 1;
      }
    }
    return -1;
  }  
//获取元素
  T get(int index) {
    if (index < 1 || index > size) {
      cout << "错误位序" << endl;
      return T();
    }
    return array[index - 1];
  }
//获取长度
  int getSize() {
    return size;
  }
//打印顺序表
  void print() {
    cout << "[";
    for (int i = 0; i < size-1; i++) {
      cout << array[i] << ",";
    }
    if (size > 0) {
      cout << array[size-1];
    }
    cout << "]" << endl;
  }
//清空顺序表
  void clear() {
    size = 0;
  }
};

int main() {
  List<int> list;
  // 测试功能
  list.append(1);
  list.append(2);
  list.append(3);
  list.print(); // 输出: [1,2,3]
  list.app(4, 2);
  list.print(); // 输出: [1,4,2,3]
  list.remove(3);
  list.print(); // 输出: [1,4,3]
  cout << "元素 4 的位置: " << list.find(4) << endl; // 输出: 元素 4 的位置: 2
  cout << "获取位置 2 的元素: " << list.get(2) << endl; // 输出: 获取位置 2 的元素: 4
  cout << "顺序表长度: " << list.getSize() << endl; //  输出: 顺序表长度: 3
  list.clear();
  list.print(); // 输出: [ ]
  return 0;
}