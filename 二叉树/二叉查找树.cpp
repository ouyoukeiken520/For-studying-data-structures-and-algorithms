#include <iostream>
using namespace std;

class Tree {
public:
  int element;
  Tree *left;
  Tree *right;
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
      if (right != nullptr) {
        right = right->remove(ele);
      }
    } else if (ele < element) {
      if (left != nullptr) {
        left = left->remove(ele);
      }
    } else {
      if (left && right) {
        Tree *max = left->findMax();
        element = max->element;
        left = left->remove(max->element);
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

void printFindResult(Tree *root, int ele) {
  Tree *res = root->find(ele);
  if (res) {
    cout << "查找 " << ele << " 成功!" << endl;
  } else {
    cout << "查找 " << ele << " 失败 (树中不存在该节点)。" << endl;
  }
}
int main() {
  cout << "========== 阶段 1: 构建二叉搜索树 ==========" << endl;
  Tree *root = new Tree(50);
  root->insert(30);
  root->insert(70);
  root->insert(20);
  root->insert(40);
  root->insert(60);
  root->insert(80);
  root->insert(35);
  root->insert(45);
  root->insert(90);

  cout << "中序遍历 (期望升序: 20 30 35 40 45 50 60 70 80 90):" << endl;
  root->inOrder();
  cout << "\n\n";

  cout << "========== 阶段 2: 测试极值与查找功能 ==========" << endl;
  cout << "最小值 (期望 20): " << root->findMin()->element << endl;
  cout << "最大值 (期望 90): " << root->findMax()->element << endl;

  printFindResult(root, 45);  // 存在的节点
  printFindResult(root, 100); // 不存在的节点
  cout << "\n";

  cout << "========== 阶段 3: 测试删除功能 ==========" << endl;

  // 测试 3.1: 删除叶子节点
  cout << "--- 3.1 删除叶子节点 (35) ---" << endl;
  root = root->remove(35);
  root->inOrder();
  cout << " (期望缺少 35)" << endl;

  // 测试 3.2: 删除只有一个子节点的节点
  cout << "\n--- 3.2 删除单子节点 (80，只有右子节点90) ---" << endl;
  root = root->remove(80);
  root->inOrder();
  cout << " (期望缺少 80，90 被提升)" << endl;

  // 测试 3.3: 删除有两个子节点的节点
  cout << "\n--- 3.3 删除双子节点 (30) ---" << endl;
  // 30的左子树最大值是20（30被替换为20，然后20被删除）
  root = root->remove(30);
  root->inOrder();
  cout << " (期望缺少 30)" << endl;

  // 测试 3.4: 删除根节点 (最复杂的情况)
  cout << "\n--- 3.4 删除根节点 (50) ---" << endl;
  root = root->remove(50);
  if (root) {
    root->inOrder();
    cout << " (期望缺少 50，新根节点应为 45)" << endl;
    cout << "当前根节点的值: " << root->element << endl;
  }

  cout << "\n========== 阶段 4: 测试异常/边界情况 ==========" << endl;
  cout << "--- 尝试删除不存在的节点 (999) ---" << endl;
  // 如果没有上面 remove 中的 != nullptr 判断，这一步会引发段错误崩溃
  root = root->remove(999);
  cout << "程序未崩溃！删除不存在的节点测试通过。" << endl;
  root->inOrder();
  cout << "\n";

  return 0;
}