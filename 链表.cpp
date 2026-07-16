#include <iostream>
using namespace std;
template <typename T>
class Link {
    T element;
    Link<T> *next;

public:
    Link(T ele = 0, Link<T> *nextNode = nullptr) {
        element = ele;
        next = nextNode;
    }
// 插入元素
    void insert(T ele, int index) {
        Link<T> *newNode = new Link<T>(ele);
        Link<T> *current = this;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
// 删除元素
    void remove(int index) {
        Link<T> *current = this;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        Link<T> *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
// 获取元素
    T get(int index) {
        Link<T> *current = this;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        return current->next->element;
    }
// 查找元素
    T find(T ele) {
        Link<T> *current = this;
        int index = 1;
        while (current->next != nullptr) {
            if (current->next->element == ele) {
                return current->next->element;
            }
            current = current->next;
            index++;
        }
        return -1; // 未找到元素
    }  
// 打印链表
    void print() {
        Link<T> *current = this;
        while (current != nullptr) {
            cout << current->element << "->";
            current = current->next;
        }
        cout << endl;
    }    
};

int main() {
  // 测试链表
    Link<int> *head = new Link<int>(0); // 创建链表头节点
    head->insert(1, 1); // 在位置1插入元素1
    head->print();      // 打印链表
    head->insert(2, 2); // 在位置2插入元素2
    head->print();      // 打印链表
    head->insert(3, 3); // 在位置3插入元素3
    head->print();      // 打印链表
    head->remove(2);    // 删除位置2的元素
    head->print();      // 打印链表
    cout << "元素3的索引是: " << head->find(3) << endl;
    return 0;
}