#include "Kruskal.h"
#include "percolation.h"

void add(graphMI *g, int rib, percolation *vertex, graphMI *tree) {
  int bufA = g->ribin(rib);
  int bufB = g->ribout(rib);
  tree->add(bufA, bufB, g->mas[rib][bufA - 1]);
  vertex->union_(bufA, bufB);
}

bool test_on_add(int vrA, int vrB, percolation *vertex) {
  if (vertex->find_(vrA) == vertex->find_(vrB)) return false;
  return true;
}

graphMI* kruskal(graphMI g) {
  graphMI *tree = new graphMI(g.sizeVrt);
  g.sort();
  percolation *vertex = new percolation(g.sizeVrt);
  add(&g, 0, vertex, tree);
  add(&g, 1, vertex, tree);
  for (int rib = 2; tree->sizeRib + 1 != g.sizeVrt; rib++) {
    if (test_on_add(g.ribin(rib), g.ribout(rib), vertex)) {
      add(&g, rib, vertex, tree);
    }
  }
  return tree;
}
