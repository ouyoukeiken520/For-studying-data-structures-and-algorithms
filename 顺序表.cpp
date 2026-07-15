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
//随机插入
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
};

int main() {
  List<int> list;
  return 0;
}