#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include "stdio.h"

struct CNode {
  int inf;
  CNode* left;
  CNode* right;

 public:
  explicit CNode(const int v = 0) {
    this->left = 0;
    this->right = 0;
    this->inf = v;
  }

  CNode(const CNode &root) {
    if (this != &root) {
      this->inf = root.inf;
      while (root.right) {
        this->right = new CNode;
        this->right = root.right;
      }
      while (root.left) {
        this->left = new CNode;
        this->left = root.left;
      }
    }
  }

  // void print_tree();
  // void input_tree();
};

CNode* build_tree(int *mas, int size);
CNode* build_normal_tree(int *mas, int size);

#endif  // INCLUDE_TREE_H_
