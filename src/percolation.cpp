#include "percolation.h"
#include <stdexcept>

percolation::percolation(int size) {
  if (size <= 0) throw std::logic_error("don't correct size element");
  if (size > 0) items = new Node[size];
}

Node* percolation::find_(int key) {
  Node *ptr = items[key - 1].next;
  while (ptr != ptr->next) ptr = ptr->next;
    return ptr;
}

void percolation::union_(int el1, int el2) {
  Node *root1 = find_(el1);
  Node *root2 = find_(el2);
  root2->next = root1;
}
