#include "alg.h"
#include "percolation.h"
#include "rib.h"

bool confl(int group, percolation *sociaty, int size, int people, vertex *list) {
  for (int i = 0; i < size; i++) {
    if (sociaty->items[i] == group)
      if (list->rib_in(i, people)) return true;
  }
  return false;
}

void add_people(percolation *sociaty, int size, int people, vertex *list, int sizeG) {
  for (int i = 0; i < size; i++) {
    if (people != i) {
      if (!confl(sociaty->find_(people), sociaty, size, i, list)) {
        sociaty->union_(people, i);
        sizeG--;
      }
    }
  }
}

percolation* alg(percolation *sociaty, int size, vertex *list, int *sizeGroup) {
  int sizeG = size;
  int ptr = 0;
  if (ptr == size) return sociaty;
  for (; ptr < size; ptr++) {
    if (sociaty->items[ptr] == ptr) {
      add_people(sociaty, size, ptr, list, sizeG);
    }
  }
  sizeGroup[0] = sizeG;
  return sociaty;
}
 