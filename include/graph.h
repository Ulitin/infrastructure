#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_
#include <stdexcept>
#include <iostream>

using std::cout;

struct vertex {
  std::pair<int, int> *vrt;
  vertex *next = nullptr;

  explicit vertex(int number = 1, int lenghts = 0) {
    vrt = new std::pair<int, int>;
    vrt->first = number;
    vrt->second = lenghts;
  }

  void add(int number, int lengths) {
    bool flag = true;
    vertex* ptr = this;
    while (flag && ptr->next != nullptr) {
      if (ptr->vrt->first == number) {
        flag = false;
        ptr->vrt->first = number;
        ptr->vrt->second = lengths;
      }
      ptr = ptr->next;
    }
    if (flag) {
      ptr->next = new vertex(number, lengths);
    }
  }

  void del(int number) {
    auto ptr = this;
    vertex *buf = nullptr;
    while (ptr != nullptr) {
      if (ptr->vrt->first == number) {
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
      if ((ptr->vrt->first = a) && (ptr->vrt->second = b)) return true;
      if ((ptr->vrt->first = b) && (ptr->vrt->second = a)) return true;
      ptr = ptr->next;
    }
    return false;
  }

  ~vertex() {
    vertex *tmp = nullptr;
    vertex *del = this;
    while (del != nullptr) {
      tmp = del->next;
      delete del->vrt;
      del = tmp;
    }
  }
};

#endif  // INCLUDE_GRAPH_H_