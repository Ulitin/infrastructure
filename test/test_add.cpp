#include <gtest/gtest.h>
#include "tree.h"

TEST(Addition, test_one) {
  int mas[] = { 1, 2, 3, 4, 5 };
  CNode *tree = build_tree(mas, 5);
  EXPECT_EQ(tree->inf, 3);
  EXPECT_EQ(tree->right->inf, 4);
  EXPECT_EQ(tree->right->right->inf, 5);
  EXPECT_EQ(tree->left->inf, 2);
  EXPECT_EQ(tree->left->left->inf, 1);
}

TEST(Addition, test_two) {
  int mas[] = { 1, 2, 3, 4, 5, 6 };
  CNode *tree = build_tree(mas, 6);
  EXPECT_EQ(tree->inf, 4);
  EXPECT_EQ(tree->right->inf, 5);
  EXPECT_EQ(tree->right->right->inf, 6);
  EXPECT_EQ(tree->left->inf, 3);
  EXPECT_EQ(tree->left->left->inf, 2);
  EXPECT_EQ(tree->left->left->left->inf, 1);
}
