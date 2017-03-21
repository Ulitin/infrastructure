#include"tree.h"
#include <queue>
#include <tuple>
#include <stdexcept>

CNode* build_tree(int *mas, int size) {
  if (size == 0) return 0;
  CNode* root = new CNode (mas[size/2]);
  //  std::queue <int> s;
  int ptr_mas = size / 2 - 1;
  CNode* ptr_tree = root;
  while (ptr_mas >= 0) {
    ptr_tree->left = new CNode(mas[ptr_mas]);
    ptr_tree = ptr_tree->left;
    ptr_mas--;
  }
  ptr_tree = root;
  ptr_mas = size / 2 + 1;
  while (ptr_mas < size) {
    ptr_tree->right = new CNode(mas[ptr_mas]);
    ptr_tree = ptr_tree->right;
    ptr_mas++;
  }
  return root;
}

//  CNode* build_normal_tree(int *mas, int size) {
//  std::queue<CNode**> q;
//  std::queue<int> left;
//  std::queue<int> right;
//  if (size == 0) return nullptr;
//  CNode* root = nullptr;
//  q.push(&root);
//  left.push(0);
//  right.push(size);
//  int center = int (size / 2 + 1);
//  while (!left.empty()) {
//    CNode** leave = q.front();
//    int l = left.front();
//    int r = right.front();
//    q.pop();
//    left.pop();
//    right.pop();
//    center = (l + r) / 2;
//    if (l < r) {
//      (*leave) = new CNode(mas[center]);
//      q.push(&((*leave)->left));
//      left.push(l);
//      right.push(center + 1);
//      q.push(&((*leave)->right));
//      left.push(center);
//      right.push(r);
//    }
//  }
//  return root;
//  }
