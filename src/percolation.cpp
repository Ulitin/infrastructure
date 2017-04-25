#include "percolation.h"

int percolation::find_(int key) {
  while (items[key] != key) key = items[key];
    return key;
}

void percolation::union_(int el1, int el2) {
  el1 = find_(el1);
  el2 = find_(el2);
  if(el1 != el2) items[el2] = el1;
}
