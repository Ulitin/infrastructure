#include <gtest/gtest.h>
#include "task.h"

TEST(Addition, test1) {
  int a[] = {1, 2, 3};
  int *b = fun(a, 3);
  EXPECT_EQ(b[0], 6);
  EXPECT_EQ(b[1], 3);
  EXPECT_EQ(b[2], 2);
}

TEST(Addition, test2) {
  int a[] = { 1, 0, 3};
  int *b = fun(a, 3);
  EXPECT_EQ(b[0], 0);
  EXPECT_EQ(b[1], 3);
  EXPECT_EQ(b[2], 0);
}

TEST(Addition, test3) {
  int a[] = { 0};
  int *b = fun(a, 1);
  EXPECT_EQ(b[0], 0);
}
