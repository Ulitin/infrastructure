#include <gtest/gtest.h>
#include "alg.h"
#include "percolation.h"
#include "graph.h"

TEST(alg, test1) {
  int size = 3;
  percolation *pr = new percolation(size);
  vertex *list = new vertex(1, 2);
  list->add(2, 3);
  list->add(3, 1);
  //list->add();
  percolation *sociaty = alg(pr, size, list);
}
