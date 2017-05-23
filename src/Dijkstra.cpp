#include "graph.h"
#include "map"
#include "Dijkstra.h"

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
      if (vrt->second >(len + ptr->vrt->second) || vrt->second < 0) {
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

int dijkstra(int start, int end, graph *g) {
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
