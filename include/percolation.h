#ifndef INCLUDE_PERCOLATION_H_
#define INCLUDE_PERCOLATION_H_

struct Node {
  Node *next = this;
};

struct percolation {
  Node *items = nullptr;

  explicit percolation(int size = 0);
  void union_(int el1, int el2);
  Node* find_(int key);
};

#endif  // INCLUDE_PERCOLATION_H_
