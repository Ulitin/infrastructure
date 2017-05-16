#ifndef INCLUDE_PERCOLATION_H_
#define INCLUDE_PERCOLATION_H_

struct percolation {
  int *items;

  explicit percolation(int size) {
    items = new int[size];
    for (int i = 0; i < size; i++)
      items[i] = i;
  }

  void union_(int el1, int el2);
  int find_(int key);
};

#endif  // INCLUDE_PERCOLATION_H_
