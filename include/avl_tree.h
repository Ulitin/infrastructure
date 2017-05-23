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

  explicit avl_tree(std::pair<int, int> input) {
    var = input;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

unsigned int height(avl_tree* p);

int bfactor(avl_tree* p);

void fixheight(avl_tree* p);

avl_tree* rotateright(avl_tree* p);

avl_tree* rotateleft(avl_tree* q);

avl_tree* balance(avl_tree* p);

avl_tree* insert(avl_tree* p, std::pair<int, int> k);

avl_tree* begin(avl_tree* p);

avl_tree* find(avl_tree* p, int key);

avl_tree* removemin(avl_tree* p);

avl_tree* remove(avl_tree* p, int k);

avl_tree* end();

bool empty(avl_tree* p);

#endif  // INCLUDE_AVL_TREE_H_
