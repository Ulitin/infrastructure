#ifndef INCLUDE_AVL_TREE_H_
#define INCLUDE_AVL_TREE_H_
#include <stdexcept>
#include <iostream>

using std::cout;

struct avl_tree {
  std::pair<int, int> var;
  unsigned int height;
  avl_tree* left;
  avl_tree* right;

  avl_tree() {
    left = nullptr;
    right = nullptr;
    height = 0;
  }
  avl_tree(std::pair<int, int> input) { 
    var = input;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

unsigned int height(avl_tree* p) {
  if (p == nullptr) return 0;
  return p->height;
}

int bfactor(avl_tree* p) {
  return height(p->right) - height(p->left);
}

void fixheight(avl_tree* p) {
  unsigned char hl = height(p->left);
  unsigned char hr = height(p->right);
  if (hl > hr) p->height = hl + 1;
  if (hl <= hr) p->height = hr + 1;
}

avl_tree* rotateright(avl_tree* p) {
  avl_tree* q = p->left;
  p->left = q->right;
  q->right = p;
  fixheight(p);
  fixheight(q);
  return q;
}

avl_tree* rotateleft(avl_tree* q) {
  avl_tree* p = q->right;
  q->right = p->left;
  p->left = q;
  fixheight(q);
  fixheight(p);
  return p;
}

avl_tree* balance(avl_tree* p) {
  fixheight(p);
  if (bfactor(p) == 2) {
    if (bfactor(p->right) < 0) p->right = rotateright(p->right);
    return rotateleft(p);
  }
  if (bfactor(p) == -2) {
    if (bfactor(p->left) > 0) p->left = rotateleft(p->left);
    return rotateright(p);
  }
  return p;
}

avl_tree* insert(avl_tree* p, std::pair<int, int> k) {
  if (!p) return new avl_tree(k);
  if (k.first < p->var.first) p->left = insert(p->left, k);
  if (k.first >= p->var.first) p->right = insert(p->right, k);
  return balance(p);
}

avl_tree* begin(avl_tree* p) {
  return p->left ? begin(p->left) : p;
}

avl_tree* removemin(avl_tree* p) {
  if (p->left == 0)
    return p->right;
  p->left = removemin(p->left);
  return balance(p);
}

avl_tree* remove(avl_tree* p, int k) {
  if (!p) return 0;
  if (k < p->var.first) {
    p->left = remove(p->left, k);
  }
  if (k > p->var.first) {
    p->right = remove(p->right, k);
  }
  if (k == p->var.first) {
    avl_tree* q = p->left;
    avl_tree* r = p->right;
    delete p;
    if (!r) return q;
    avl_tree* min = begin(r);
    min->right = removemin(r);
    min->left = q;
    return balance(min);
  }
  return balance(p);
}

avl_tree* end() { return nullptr; }

#endif  // INCLUDE_AVL_TREE_H_
