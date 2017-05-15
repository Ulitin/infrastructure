#include "alg.h"
#include "percolation.h"
#include "graph.h"

bool confl(int group, percolation *sociaty, int size, int people, vertex *list) {
  for (int i = 0; i < size; i++) {
    if (sociaty->items[i] == group)
      if (list->rib_in(i, people)) return true;
  }
}

void add_people(percolation *sociaty, int size, int group, vertex *list) {
  for (int i = 0; i < size; i++) {
    if (!confl(sociaty->find_(group), sociaty, size, i, list)) {
      sociaty->union_(group, size);
    }
  }
}

percolation* alg(percolation *sociaty, int size, vertex *list) {
  int sizeGroup = 0;
  int ptr = 0;
  if (ptr == size) return sociaty;
  for (; ptr < size; ptr++) {
    if (sociaty->items[ptr] == ptr) {
      add_people(sociaty, size, ptr, list);
    }
  }
  return sociaty;
}
 