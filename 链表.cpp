#include <iostream>
using namespace std;
template <typename T>
class Link {
    T element;
    Link<T> *next;
public:
    Link(){
        element = T();
        next = nullptr;
    }
    Link(T ele, Link<T> *nextNode = nullptr) {
        element = ele;
        next = nextNode;
    }
    ~Link() {
        delete next;
    }
// 插入元素
    void insert(T ele, int index) {
        Link<T> *newNode = new Link<T>(ele);
        Link<T> *current = this;
        for (int i = 1; i < index && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "插入失败：位序错误" << endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
// 删除元素
    void remove(int index) {
        Link<T> *current = this;
        for (int i = 1; i < index && current->next != nullptr; i++) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "删除失败：位序错误" << endl;
            return;
        }
        Link<T> *temp = current->next;
        current->next = temp->next;
        temp->next = nullptr;
        delete temp;
    }
// 获取元素
    T get(int index) {
        Link<T> *current = this;
        for (int i = 1; i < index && current->next != nullptr; i++) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "获取失败：位序错误" << endl;
            return T();
        }
        return current->next->element;
    }
// 查找元素
    int find(T ele) {
        Link<T> *current = this;
        int index = 1;
        while (current->next != nullptr) {
            if (current->next->element == ele) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }  
// 打印链表
    void print() {
        Link<T> *current = this;
        current = current->next; // 跳过头节点
        while (current != nullptr) {
            cout << current->element;
            if (current->next != nullptr) {
                cout << "->";
            }
            current = current->next;
        }
        cout << endl;
    }    
};

void printTitle(const string &title) {
    cout << "\n========================================" << endl;
    cout << "  " << title << endl;
    cout << "========================================" << endl;
}
int main() {
// 测试链表
    cout << "=== 1. 初始化链表 ===" << endl;
    Link<int> *head = new Link<int>();
    head->print(); // 预期: 空链表

    cout << "\n=== 2. 测试 insert (插入功能) ===" << endl;
    head->insert(10, 1);
    head->insert(20, 1);
    head->insert(30, 1);
    cout << "在头部连续插入后 (预期: 30->20->10):" << endl;
    head->print();

    head->insert(25, 2);
    cout << "在位序 2 插入 25 (预期: 30->25->20->10):" << endl;
    head->print();

    head->insert(5, 5);
    cout << "在尾部插入 5 (预期: 30->25->20->10->5):" << endl;
    head->print();

    cout << "测试越界插入:" << endl;
    head->insert(99, 10); // 预期: 打印错误提示，程序不崩溃

    cout << "\n=== 3. 测试 find (查找功能) ===" << endl;
    cout << "元素 20 的位序: " << head->find(20) << " (预期: 3)" << endl;
    cout << "元素 5 的位序:  " << head->find(5) << " (预期: 5)" << endl;
    cout << "元素 100 的位序: " << head->find(100) << " (预期: -1，不存在)" << endl;

    cout << "\n=== 4. 测试 get (获取功能) ===" << endl;
    cout << "位序 4 的元素: " << head->get(4) << " (预期: 10)" << endl;
    cout << "测试越界获取:" << endl;
    try {
    head->get(10); // 预期: 抛出异常被捕获，程序不崩溃
    } catch (const out_of_range &e) {
    cout << "成功捕获异常 -> " << e.what() << endl;
    }

    cout << "\n=== 5. 测试 remove (删除功能) ===" << endl;
    head->remove(1);
    cout << "删除位序 1 的元素后 (头删，删掉 30):" << endl;
    head->print(); // 预期: 25->20->10->5

    head->remove(3);
    cout << "删除位序 3 的元素后 (中间删，删掉 10):" << endl;
    head->print(); // 预期: 25->20->5

    head->remove(3);
    cout << "删除位序 3 的元素后 (尾删，删掉 5):" << endl;
    head->print(); // 预期: 25->20

    cout << "测试越界删除:" << endl;
    head->remove(5); // 预期: 打印错误提示，程序不崩溃

    cout << "\n=== 6. 测试 析构函数 (内存清理) ===" << endl;
    delete head;
    cout << "链表已彻底删除" << endl;

    return 0;
}