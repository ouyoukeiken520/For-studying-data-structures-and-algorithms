#include <iostream>
using namespace std;

class Tree {
public:
  int element;
  Tree *left;
  Tree *right;

public:
  Tree(int e) {
    element = e;
    left = right = NULL;
  }
  void insert(int ele) {
    if (ele < element) {
      if (left == nullptr) {
        left = new Tree(ele);
      } else {
        left->insert(ele);
      }
    } else if (ele > element) {
      if (right == nullptr) {
        right = new Tree(ele);
      } else {
        right->insert(ele);
      }
    };
  }
  void inOrder() {
    if (left != nullptr) {
      left->inOrder();
    }
    cout << element << " ";
    if (right != nullptr) {
      right->inOrder();
    }
  }
  Tree *find(int ele) {
    if (ele == element) {
      return this;
    }
    if (ele > element && right) {
      return right->find(ele);
    } else if (ele < element && left) {
      return left->find(ele);
    }
    return nullptr;
  }
  Tree *findMin() {
    if (left == nullptr) {
      return this;
    } else {
      return left->findMin();
    }
  }
  Tree *findMax() {
    if (right == nullptr) {
      return this;
    } else {
      return right->findMax();
    }
  }
  Tree *remove(int ele) {
    if (ele > element) {
      right = right->remove(ele);
    } else if (ele < element) {
      left = left->remove(ele);
    } else {
      if (left && right) {
        Tree *max = left->findMax();
        element = max->element;
        left = left->remove(ele);
      } else {
        Tree *tmp = this;
        Tree *node = (left != nullptr) ? left : right;
        delete tmp;
        return node;
      }
    }
    return this;
  };
};

// ==========================================
//                 测试代码
// ==========================================
int main() {
  // 1. 初始化（必须用 new，以配合 remove 里的 delete）
  cout << "=== 1. 测试初始化与插入 (Insert) ===" << endl;
  Tree *root = new Tree(20);

  // 构造一棵稍微复杂的树
  //        20
  //      /    \
  //    10      30
  //   /  \    /  \
  //  5   15  25  35
  //      /    \
  //     12    28
  root->insert(10);
  root->insert(30);
  root->insert(5);
  root->insert(15);
  root->insert(25);
  root->insert(35);
  root->insert(12);
  root->insert(28);
  cout << "节点插入完成！" << endl;

  // 2. 测试中序遍历
  cout << "\n=== 2. 测试中序遍历 (InOrder) ===" << endl;
  cout << "预期结果: 5 10 12 15 20 25 28 30 35 " << endl;
  cout << "实际结果: ";
  root->inOrder();
  cout << endl;

  // 3. 测试查找
  cout << "\n=== 3. 测试查找 (Find) ===" << endl;
  Tree *search1 = root->find(15);
  if (search1)
    cout << "[成功] 找到了元素: " << search1->element << endl;
  else
    cout << "[失败] 未找到元素 15" << endl;

  Tree *search2 = root->find(99);
  if (search2)
    cout << "[失败] 找到了元素: 99" << endl;
  else
    cout << "[成功] 元素 99 不存在，返回正常" << endl;

  // 4. 测试极值
  cout << "\n=== 4. 测试极值查找 (FindMin / FindMax) ===" << endl;
  cout << "最小值 (预期 5)  : " << root->findMin()->element << endl;
  cout << "最大值 (预期 35) : " << root->findMax()->element << endl;

  // 5. 测试删除 (三种不同情况)
  cout << "\n=== 5. 测试删除 (Remove) ===" << endl;

  // 5.1 删除叶子节点 (没有孩子的节点，例如 12)
  cout << "--> 删除叶子节点 12: ";
  root->remove(12);
  root->inOrder();
  cout << endl;

  // 5.2 删除只有一个孩子的节点 (例如 25，它只有右孩子 28)
  cout << "--> 删除单孩节点 25: ";
  root->remove(25);
  root->inOrder();
  cout << endl;

  // 5.3 删除有两个孩子的节点 (例如 10，它有左孩 5 和右孩 15)
  cout << "--> 删除双孩节点 10: ";
  root->remove(10);
  root->inOrder();
  cout << endl;

  // 5.4 删除根节点 (终极测试，删除 20)
  cout << "--> 删除根节点 20:   ";
  root->remove(20);
  root->inOrder();
  cout << endl;

  return 0;
}