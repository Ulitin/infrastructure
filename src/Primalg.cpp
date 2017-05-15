#include "Primalg.h"
#include "heap.h"
#include "Dijkstra.h"

void add_ribs(heap *ribs, vertex *vrt, int road) { //  add vertices in ribs from vrt
  vertex *ptr = vrt;
  rib rb;
  rb.ribStart = ptr->vrt->first;
  ptr = ptr->next;
  while (ptr != nullptr) {
    rb.lenght = road + ptr->vrt->second;
    rb.ribFinish = ptr->vrt->first;
    ribs->insert(rb);
    ptr = ptr->next;
  }
}

int* vrt_in_graph(graph *g) {  //  generates an array of vertices of the graph
  int size = g->size_vrt();
  int *vrt = new int[size];
  graph *ptr = g;
  for (int i = 0; i < size; i++) {
    vrt[i] = ptr->vrts->vrt->first;
    ptr = ptr->next;
  }
  return vrt;
}

//graph* prim_step(graph *g) {
//  return nullptr;
//}

bool find_vrt(int *vrtGraph, rib *rb, int size) {
  for (int i = 0; i < size; i++) {
    if (vrtGraph[i] == rb->ribFinish) {
      vrtGraph[i] = -1;
      return true;
    }
  }
  return false;
}

graph* prim(graph *g) {
  if (g == nullptr) {
    std::logic_error("me is not eat empty graph)");
  }
  int size = g->size_vrt();
  heap *ribs = new heap;  //  for store missed vertices
  int *vrtGraph = vrt_in_graph(g);  //  vertex which don't tree
  int vrt = vrtGraph[0]; //  vrtGraph[0];
  vrtGraph[0] = -1;
  graph *tree = new graph(vrt);
  for (int i = 1; i < size; i++) {
    int road = dijkstra(1, vrt, g);
    add_ribs(ribs, g->find(vrt), road);
    rib *rb = ribs->begin();
    while (!find_vrt(vrtGraph, rb, size)) {
      ribs->remove(ribs->begin());
    };
    tree->add(rb->ribStart, rb->ribFinish, rb->lenght);
    vrt = rb->ribFinish;
    ribs->remove(ribs->begin());
  }
  return tree;
}
