#include "alg.h"
#include "percolation.h"
#include "rib.h"

bool confl(int people, percolation *sociaty, int size, int group, vertex *list) {
  for (int i = 0; i < size; i++) {
    if (sociaty->items[i] == group) {
      for (int j = 0; j < size; j++) {
        if (sociaty->items[j] == sociaty->find_(people)) {
          if (list->rib_in(i, j)) return true;
        }
      }
    }
  }
  return false;
}

void add_people(percolation *sociaty, int size, int people, vertex *list, int sizeG) {
  for (int i = 0; i < size; i++) {
    if (people != i) {
      if (!confl(people, sociaty, size, sociaty->find_(i), list)) {
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
