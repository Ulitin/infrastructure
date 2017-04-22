#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_
#include <stdexcept>
#include <iostream>

using std::cout;

struct heap {
  std::pair<int, int> *var = nullptr;
  int size = 0;

  void add_down(std::pair<int, int> input);
  void raise(int ptr);
  int parent(int ptr);
  void swap(int ptr1, int ptr2);  //  input ptr on sheet!
  int find_ptr(std::pair<int, int>* el);
  int min_child(int ptr);  //  output ptr on min child
  int child(int ptr);
  void fix_down(int ptr);
  void fix_up(int ptr);
  int side_child(int ptr);
  void del_el();

public:

  std::pair<int, int>* find(int first);
  void insert(std::pair<int, int> input);
  void remove(std::pair<int, int>* del);
  std::pair<int, int>* begin() { return var; }
  bool empty();
  void* end() { return nullptr; }
};

#endif  // INCLUDE_HEAP_H_
