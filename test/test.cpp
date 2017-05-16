#include <gtest/gtest.h>
#include "alg.h"
#include "percolation.h"
#include "rib.h"

TEST(alg, test1) {
  int size = 3;
  percolation *pr = new percolation(size);
  vertex *list = new vertex(0, 1);
  list->add(1, 2);
  list->add(2, 0);
  int *sizeGroup = new int;
  percolation *sociaty = alg(pr, size, list, sizeGroup);
}
