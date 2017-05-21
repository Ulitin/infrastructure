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
  EXPECT_EQ(sociaty->items[0], 0);
  EXPECT_EQ(sociaty->items[1], 1);
  EXPECT_EQ(sociaty->items[2], 2);
}

TEST(alg, test2) {
  int size = 6;
  percolation *pr = new percolation(size);
  vertex *list = new vertex(0, 1);
  list->add(1, 2);
  list->add(2, 5);
  list->add(4, 3);
  int *sizeGroup = new int;
  percolation *sociaty = alg(pr, size, list, sizeGroup);
  EXPECT_EQ(sociaty->items[0], 0);
  EXPECT_EQ(sociaty->items[1], 1);
  EXPECT_EQ(sociaty->items[2], 0);
  EXPECT_EQ(sociaty->items[3], 0);
  EXPECT_EQ(sociaty->items[4], 1);
  EXPECT_EQ(sociaty->items[5], 1);
}
