#include "graph.h"
#include "map"
#include "heap.h"
#include "avl_tree.h"

void start_input(std::map<int, int> *prior_q, graph *g, int start) {
  vertex* ptr = g->find(start);
  int len = 0;
  if (ptr == nullptr) return;
  if (!prior_q->empty()) len = prior_q->begin()->second;
  if (len < 0) len = 0;
  ptr = ptr->next;
  while (ptr != nullptr) {
    auto vrt = prior_q->find(ptr->vrt->first);
    if (vrt != prior_q->end()) {
      if (vrt->second > (len + ptr->vrt->second) || vrt->second < 0) {
        (*prior_q)[ptr->vrt->first] = len + ptr->vrt->second;
      }
    }
    ptr = ptr->next;
  }
}

void recalculate(std::map<int, int> *prior_q, graph *g) {
  auto tmp = prior_q->begin();
  start_input(prior_q, g, tmp->first);
}

void initialization(std::map<int, int> *prior_q, graph *g) {
  graph *ptr = g;
  while (ptr != nullptr) {
    prior_q->insert(std::make_pair(ptr->vrts->vrt->first, -1));
    ptr = ptr->next;
  }
}

int alg_dijkstra(int start, int end, graph *g) {
  if (start == end) return 0;
  vertex* ptr = g->find(start);
  if (ptr == nullptr) throw std::logic_error("can't find vertex");
  std::map<int, int> *prior_q = new std::map<int, int>;
  initialization(prior_q, g);
  start_input(prior_q, g, start);
  while (true) {
    recalculate(prior_q, g);
    auto res = prior_q->begin();
    if (res->first == end) return res->second;
    prior_q->erase(prior_q->begin());
  }
}



heap* initialization_h(graph *g) {
  heap *prior_q = new heap;
  graph *ptr = g;
  while (ptr != nullptr) {
    prior_q->insert(std::make_pair(ptr->vrts->vrt->first, -1));
    ptr = ptr->next;
  }
  return prior_q;
}

void start_input_h(heap *prior_q, graph *g, int start) {
  vertex* ptr = g->find(start);
  int len = 0;
  if (ptr == nullptr) return;
  if (!prior_q->empty()) len = prior_q->begin()->second;
  if (len < 0) len = 0;
  ptr = ptr->next;
  while (ptr != nullptr) {
    auto vrt = prior_q->find(ptr->vrt->first);
    if (vrt != prior_q->end()) {
      if (vrt->second >(len + ptr->vrt->second) || vrt->second < 0) {
        prior_q->find(ptr->vrt->first)->second = len + ptr->vrt->second;
      }
    }
    ptr = ptr->next;
  }
}

void recalculate_h(heap *prior_q, graph *g) {
  auto tmp = prior_q->begin();
  start_input_h(prior_q, g, tmp->first);
}

int dijkstra_heap(graph *g) {
  vertex* ptr = g->find(1);
  if (ptr == nullptr) throw std::logic_error("can't find vertex");
  heap *prior_q = initialization_h(g);
  start_input_h(prior_q, g, 1);
  while (true) {
    recalculate_h(prior_q, g);
    auto res = prior_q->begin()->second;
    prior_q->remove(prior_q->begin());
    if (prior_q->begin() == nullptr) return res;
  }
}



avl_tree* initialization_t(graph *g) {
  avl_tree *prior_q = nullptr;
  graph *ptr = g;
  while (ptr != nullptr) {
    prior_q = insert(prior_q, std::make_pair(ptr->vrts->vrt->first, -1));
    ptr = ptr->next;
  }
  return prior_q;
}

void start_input_t(avl_tree *prior_q, graph *g, int start) {
  vertex* ptr = g->find(start);
  int len = 0;
  if (ptr == nullptr) return;
  if (!empty(prior_q)) len = begin(prior_q)->var.second;
  if (len < 0) len = 0;
  ptr = ptr->next;
  while (ptr != nullptr) {
    auto vrt = find(prior_q, ptr->vrt->first);
    if (vrt != end()) {
      if (vrt->var.second >(len + ptr->vrt->second) || vrt->var.second < 0) {
        find(prior_q, ptr->vrt->first)->var.second = len + ptr->vrt->second;
      }
    }
    ptr = ptr->next;
  }
}

void recalculate_t(avl_tree *prior_q, graph *g) {
  auto tmp = begin(prior_q);
  start_input_t(prior_q, g, tmp->var.first);
}


int dijkstra_tree(graph *g) {
  vertex* ptr = g->find(1);
  if (ptr == nullptr) throw std::logic_error("can't find vertex");
  avl_tree *prior_q = initialization_t(g);
  start_input_t(prior_q, g, 1);
  while (true) {
    recalculate_t(prior_q, g);
    auto res = begin(prior_q)->var.second;
    prior_q = removemin(prior_q);
    if (begin(prior_q) == nullptr) return res;
  }
}
