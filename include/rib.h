#ifndef INCLUDE_RIB_H_
#define INCLUDE_RIB_H_
#include <stdexcept>
#include <iostream>

using std::cout;

struct vertex {
  std::pair<int, int> *ribs;
  vertex *next = nullptr;

  explicit vertex(int x = 1, int y = 0) {
    ribs = new std::pair<int, int>;
    ribs->first = x;
    ribs->second = y;
  }

  void add(int x, int y) {
    bool flag = true;
    vertex* ptr = this;
    while (flag && ptr->next != nullptr) {
      if (ptr->ribs->first == x) {
        flag = false;
        ptr->ribs->first = x;
        ptr->ribs->second = y;
      }
      ptr = ptr->next;
    }
    if (flag) {
      ptr->next = new vertex(x, y);
    }
  }

  void del(int x, int y) {
    auto ptr = this;
    vertex *buf = nullptr;
    while (ptr != nullptr) {
      if (ptr->ribs->first == x  && ptr->ribs->second == y) {
        if (buf != nullptr) buf->next = ptr->next;
        ptr->next = nullptr;
        delete ptr;
        ptr = nullptr;
      }
      buf = ptr;
      ptr = ptr->next;
    }
  }

  bool rib_in(int a, int b) {
    vertex *ptr = this;
    while (ptr != nullptr) {
      if ((ptr->ribs->first == a) && (ptr->ribs->second == b)) return true;
      if ((ptr->ribs->first == b) && (ptr->ribs->second == a)) return true;
      ptr = ptr->next;
    }
    return false;
  }

  ~vertex() {
    vertex *tmp = nullptr;
    vertex *del = this;
    while (del != nullptr) {
      tmp = del->next;
      delete del->ribs;
      del = tmp;
    }
  }
};

#endif  // INCLUDE_RIB_H_