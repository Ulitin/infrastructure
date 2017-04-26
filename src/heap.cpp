#include "heap.h"


int dev(double x1, double x2) {
  if (x2 == 0) return 0;
  int i = 0;
  while (x1 > x2) {
    x1 = x1 - x2;
    i++;
  }
  return i;
}

int heap::child(int ptr) {
  return 7 * ptr + 1;
}

bool heap::empty() {
  if (var == nullptr) return true;
  return true;
}

void heap::swap(int ptr1, int ptr2) {
  if (ptr1 == ptr2) return;
  std::pair<int, int> tmp = var[ptr1];
  var[ptr1] = var[ptr2];
  var[ptr2] = tmp;
}

int heap::parent(int ptr) {
  return dev((ptr-1), 7);
}

void heap::add_down(std::pair<int, int> input) {
  std::pair<int, int> *new_var = new std::pair<int, int>[size + 1];
  for (int i = 0; i < size; i++) {
    new_var[i] = var[i];
  }
  new_var[size++] = input;
  delete var;
  var = new_var;
}

void heap::raise(int ptr) {
  int p = this->parent(ptr);
  if (p != ptr) {
    if (var[p].first > var[ptr].first) swap(p, ptr);
    this->raise(p);
  }
}

int heap::find_ptr(std::pair<int, int>* el) {
  int i = 0;
  while (&var[i] != el) { i++; }
  return i;
}

std::pair<int, int>* heap::find(int first) {
  int i = 0;
  while (var[i].first != first) { i++; }
  return &var[i];
}

int heap::min_child(int ptr) {
  int ch = this->child(ptr);
  if (ch >= size) return -1;
  int res = var[ch].first;
  int ptrRes = ch;
  for (int i = ch; i < ch + 7 && i < size; i++) {
    if (res > var[i].first) {
      ptrRes = i;
      res = var[i].first;
    }
  }
  return ptrRes;
}

void heap::fix_down(int ptr) {
  int Mchild = min_child(ptr);
  if (Mchild == -1) return;
  if (var[Mchild].first >= var[ptr].first) return;
  swap(Mchild, ptr);
  fix_down(Mchild);
}

void heap::fix_up(int ptr) {
  int pr = parent(ptr);
  if (pr == ptr) return;
  if (var[pr].first <= var[ptr].first) return;
  swap(pr, ptr);
  fix_down(pr);
}

int heap::side_child(int ptr) {
  if (child(ptr) == -1) return -1;
  int side = child(ptr) + 6;
  if (side < size) return side;
  return size - 1;
}

void heap::del_el() {
  size--;
  if (size != 0) return;
  delete var;
  var = nullptr;
}

void heap::remove(std::pair<int, int>* del) {
  int ptr = find_ptr(del);
  swap(ptr, size - 1);
  del_el();
  fix_down(ptr);
  fix_up(ptr);
}

void heap::insert(std::pair<int, int> input) {
  this->add_down(input);
  this->raise(size - 1);
}
