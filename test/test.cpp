#include <gtest/gtest.h>
#include "alg.h"
#include "percolation.h"

TEST(fun_bypass, test1) {
  int **arr = new int*[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = new int[5];
    for (int j = 0; j < 5; j++)arr[i][j] = 0;
  }
  arr[0][0] = 1;
  arr[1][0] = 1;
  arr[2][0] = 1;
  arr[2][1] = 1;
  arr[3][2] = 1;
  arr[4][4] = 1;
  arr[5][4] = 1;
  arr[6][4] = 1;
  arr[6][3] = 1;
  arr[7][2] = 1;
  arr = fun_bypass(arr, 10, 5);
  EXPECT_EQ(arr[0][0], 1);
  EXPECT_EQ(arr[1][0], 1);
  EXPECT_EQ(arr[2][0], 1);
  EXPECT_EQ(arr[2][1], 1);
  EXPECT_EQ(arr[3][2], 0);
  EXPECT_EQ(arr[4][4], 1);
  EXPECT_EQ(arr[5][4], 1);
  EXPECT_EQ(arr[6][4], 1);
  EXPECT_EQ(arr[6][3], 1);
  EXPECT_EQ(arr[7][2], 0);
  for (int i = 0; i < 10; i++) delete arr[i];
  delete arr;
}

TEST(percolation, test1) {
  percolation p(10);
  p.union_(0, 1);
  p.union_(1, 5);
  p.union_(5, 9);
  p.union_(2, 9);
  p.union_(2, 7);
  EXPECT_EQ(p.find_(7), p.find_(0));
}

TEST(fun_uf, test1) {
  int **arr = new int*[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = new int[5];
    for (int j = 0; j < 5; j++)arr[i][j] = 0;
  }
  arr[0][0] = 1;
  arr[1][0] = 1;
  arr[2][0] = 1;
  arr[2][1] = 1;
  arr[3][2] = 1;
  arr[4][4] = 1;
  arr[5][4] = 1;
  arr[6][4] = 1;
  arr[6][3] = 1;
  arr[7][2] = 1;
  fun_uf(arr, 10, 5);
  EXPECT_EQ(arr[0][0], 1);
  EXPECT_EQ(arr[1][0], 1);
  EXPECT_EQ(arr[2][0], 1);
  EXPECT_EQ(arr[2][1], 1);
  EXPECT_EQ(arr[3][2], 0);
  EXPECT_EQ(arr[4][4], 1);
  EXPECT_EQ(arr[5][4], 1);
  EXPECT_EQ(arr[6][4], 1);
  EXPECT_EQ(arr[6][3], 1);
  EXPECT_EQ(arr[7][2], 0);
  for (int i = 0; i < 10; i++) delete arr[i];
  delete arr;
}
