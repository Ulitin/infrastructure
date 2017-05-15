#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_
#include <stdexcept>
#include <iostream>
#include <graph.h>

using std::cout;

class heap {
  rib *var = nullptr;
  int size = 0;

  void add_down(rib input);
  void raise(int ptr);
  int parent(int ptr);
  void swap(int ptr1, int ptr2);  //  input ptr on sheet!
  int find_ptr(rib* el);
  int min_child(int ptr);  //  output ptr on min child
  int child(int ptr);
  void fix_down(int ptr);
  void fix_up(int ptr);
  int side_child(int ptr);
  void del_el();

 public:
  rib* find(int first);
  void insert(rib input);
  void remove(rib* del);
  rib* begin() { return var; }
  bool empty();
  void* end() { return nullptr; }
};

#endif  // INCLUDE_HEAP_H_
