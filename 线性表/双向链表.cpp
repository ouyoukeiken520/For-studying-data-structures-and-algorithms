#include <iostream>
using namespace std;
template <typename T>
class LinkedList {
    struct node {
        T element;
        node *next;
        node *prev;
        node(const T &element) : element(element), next(nullptr), prev(nullptr) {}
    };
    node *head;
    node *tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    LinkedList(const LinkedList &other) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        node *current = other.head;
        while (current != nullptr) {
            insert(current->element, size + 1);
            current = current->next;
        }
    }
    LinkedList& operator=(const LinkedList &other) {
        if (this != &other) {
            // 先清空当前链表
            while (size > 0) {
                remove(1);
            }
            // 复制其他链表的元素
            node *current = other.head;
            while (current != nullptr) {
                insert(current->element, size + 1);
                current = current->next;
            }
        }
        return *this;
    }
    ~LinkedList() {
        node *current = head;
        while (current != nullptr) {
            node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

// 插入元素
    void insert(const T &element, int index) {
        if(index < 1 || index > size + 1) {
            cout<<"位序越界"<<endl;
            return;
        }
        node *newNode = new node(element);
        if (size == 0) {
            head = tail = newNode;
        } else if (index == 1) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }else if (index == size + 1) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            node *current = head;
            for (int i = 1; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
        size++;
    }
// 删除元素
    void remove(int index) {
        if(index < 1 || index > size) {
            cout<<"位序越界"<<endl;
            return;
        }
        node *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
        size--;
    }
//正向打印链表
    void print() const {
        if (head == nullptr) {
            cout << "链表为空" << endl;
            return;
        }
        node *current = head;
        while (current->next != nullptr) {
            cout << current->element << "->";
            current = current->next;
        }
        if (current != nullptr) {
            cout << current->element;
        }
        cout << endl;
    }
// 反向打印链表
    void Reprint() const {
        if (tail == nullptr) {
            cout << "链表为空" << endl;
            return;
        }
        node *current = tail;
        while (current->prev != nullptr) {
            cout << current->element << "<-";
            current = current->prev;
        }
        if (current != nullptr) {
            cout << current->element;
        }
        cout << endl;
    }
// 查找元素    
    int find(const T &element) const {
        node *current = head;
        int index = 1;
        while (current) {
            if (current->element == element) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
// 获取元素
    T get(int index) const {
        if(index < 1 || index > size) {
            cout<<"位序越界"<<endl;
            return T();
        }
        node *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        return current->element;
    }
// 获取链表长度
    int getSize() const {
        return size;
    }    
};

int main() {
    LinkedList<int> list;

    cout << "--- 1. 测试插入功能 ---" << endl;
    list.insert(10, 1); // 空链表插入 (场景1)
    list.insert(20, 2); // 尾部插入 (场景3)
    list.insert(5, 1);  // 头部插入 (场景2)
    list.insert(15, 3); // 中间插入 (场景4)

    // 预期顺序: 5 -> 10 -> 15 -> 20
    cout << "正向打印: ";
    list.print();
    cout << "反向打印: ";
    list.Reprint();

    cout << "\n--- 2. 测试查找与获取功能 ---" << endl;
    cout << "元素 15 的位序是: " << list.find(15) << " (预期为 3)" << endl;
    cout << "元素 100 的位序是: " << list.find(100) << " (预期为 -1)" << endl;
    cout << "第 4 个元素是: " << list.get(4) << " (预期为 20)" << endl;

    cout << "\n--- 3. 测试删除功能 ---" << endl;
    list.remove(1); // 删除头部 (5)
    cout << "删除头部后: ";
    list.print(); // 预期: 10 -> 15 -> 20

    list.remove(3); // 删除尾部 (20)
    cout << "删除尾部后: ";
    list.print(); // 预期: 10 -> 15

    // 再验证一下双向指针是否在删除后依然正确
    cout << "反向打印验证双向指针: ";
    list.Reprint(); // 预期: 15 <- 10

    list.insert(12, 2); // 重新插入一个中间值，变成 10 -> 12 -> 15
    cout << "插入中间值(12)后: ";
    list.print(); // 预期: 10 -> 12 -> 15
    list.remove(2);     // 删除中间部位 (12)
    cout << "删除中间部位后: ";
    list.print(); // 预期: 10 -> 15

    cout << "\n--- 4. 测试越界防护机制 ---" << endl;
    cout << "当前链表长度: " << list.getSize() << endl; // 预期: 2
    list.insert(99, 5); // 越界插入，size 目前是 2，合法位序是 1~3
    list.remove(5);     // 越界删除
    list.get(0);        // 越界获取
    return 0;
}