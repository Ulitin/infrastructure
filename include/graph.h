#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_
#include <utility>
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

struct graph {
  vertex *vrts;
  graph *next = nullptr;

  explicit graph(int number = 0, int lenghts = 0) {
    vrts = new vertex(number, lenghts);
  }

  void add(int vrt1, int vrt2 = 0, int lenghts = -1) {
    graph *ptr = this;
    if (&vrts->vrt->first == 0) vrts->add(vrt1, 0);
    if (vrt2 == 0) {
      while (ptr->vrts->vrt->first != vrt1 && ptr->next != nullptr) {
        ptr = ptr->next;
      }
      if (ptr->next == nullptr) ptr->next = new graph(vrt1);
      if (ptr->vrts->vrt->first == vrt1) {
        throw std::logic_error("vertex is created");
      }
    }
    if (vrt2 != 0) {
      while (ptr->vrts->vrt->first != vrt1 && ptr->next != nullptr) {
        ptr = ptr->next;
      }
      if (ptr->next == nullptr && ptr->vrts->vrt->first != vrt1) {
        this->add(vrt1);
        ptr = ptr->next;
      }
      if (lenghts > 0) ptr->vrts->add(vrt2, lenghts);
      else if (lenghts < 0) {
        throw std::logic_error("way to the vertex is negative");
      }
    }
    ptr->vrts->del(0);  //  improve
  }

  vertex *find(int vrt) {
    graph *ptr = this;
    if (ptr == nullptr) return nullptr;
    while (ptr->vrts->vrt->first != vrt) {
      ptr = ptr->next;
      if (ptr == nullptr) return nullptr;
    }
    return ptr->vrts;
  }

  ~graph() {
    graph *del = this;
    graph *ptr = nullptr;
    if (del != nullptr) {
      ptr = del->next;
      delete del->vrts;
      del = ptr;
    }
  }
};

#endif  // INCLUDE_GRAPH_H_
