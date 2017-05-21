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
  return 3 * ptr + 1;
}

bool heap::empty() {
  if (var == nullptr) return true;
  return false;
}

void heap::swap(int ptr1, int ptr2) {
  if (ptr1 == ptr2) return;
  rib tmp = var[ptr1];
  var[ptr1] = var[ptr2];
  var[ptr2] = tmp;
}

int heap::parent(int ptr) {
  return dev((ptr-1), 3);
}

void heap::add_down(rib input) {
  rib *new_var = new rib[size + 1];
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
    if (var[p].lenght > var[ptr].lenght) swap(p, ptr);
    this->raise(p);
  }
}

int heap::find_ptr(rib *el) {
  int i = 0;
  while (&var[i] != el) { i++; }
  return i;
}

rib* heap::find(int rb) {  //  find finish on rib
  int i = 0;
  while (var[i].ribFinish != rb) { i++; }
  return &var[i];
}

int heap::min_child(int ptr) {
  int ch = this->child(ptr);
  if (ch >= size) return -1;
  int res = var[ch].lenght;
  int ptrRes = ch;
  for (int i = ch; i < ch + 3 && i < size; i++) {
    if (res > var[i].lenght) {
      ptrRes = i;
      res = var[i].lenght;
    }
  }
  return ptrRes;
}

void heap::fix_down(int ptr) {
  int Mchild = min_child(ptr);
  if (Mchild == -1) return;
  if (var[Mchild].lenght >= var[ptr].lenght) return;
  swap(Mchild, ptr);
  fix_down(Mchild);
}

void heap::fix_up(int ptr) {
  int pr = parent(ptr);
  if (pr == ptr) return;
  if (var[pr].lenght <= var[ptr].lenght) return;
  swap(pr, ptr);
  fix_down(pr);
}

int heap::side_child(int ptr) {
  if (child(ptr) == -1) return -1;
  int side = child(ptr) + 2;
  if (side < size) return side;
  return size - 1;
}

void heap::del_el() {
  size--;
  if (size != 0) return;
  delete var;
  var = nullptr;
}

void heap::remove(rib* del) {
  int ptr = find_ptr(del);
  swap(ptr, size - 1);
  del_el();
  fix_down(ptr);
  fix_up(ptr);
}

void heap::insert(rib input) {
  this->add_down(input);
  this->raise(size - 1);
}
