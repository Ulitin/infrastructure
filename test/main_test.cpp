#include <gtest/gtest.h>
#include "tree.h"

TEST(Addition, Test_on_correct_store) {
  CNode tree(8);
  tree.right = new CNode(15);
  tree.right->right = new CNode(20);
  tree.right->left = new CNode(10);
  tree.left = new CNode(4);
  tree.left->right = new CNode(7);
  tree.left->left = new CNode(2);
  EXPECT_EQ(tree.inf, 8);
  EXPECT_EQ(tree.right->inf, 15);
  EXPECT_EQ(tree.right->right->inf, 20);
  EXPECT_EQ(tree.right->left->inf, 10);
  EXPECT_EQ(tree.left->inf, 4);
  EXPECT_EQ(tree.left->right->inf, 7);
  EXPECT_EQ(tree.left->left->inf, 2);
}

TEST(Addition, Test_on_find) {
  CNode* tree = new CNode(8);
  CNode* find_el;
  tree->right = new CNode(15);
  tree->right->right = new CNode(20);
  tree->right->left = new CNode(10);
  tree->left = new CNode(4);
  tree->left->right = new CNode(7);
  tree->left->left = new CNode(2);
  find_el = find_or_add_el(tree, 7);
  EXPECT_EQ(tree->inf, 8);
  EXPECT_EQ(tree->right->inf, 15);
  EXPECT_EQ(tree->right->right->inf, 20);
  EXPECT_EQ(tree->right->left->inf, 10);
  EXPECT_EQ(tree->left->inf, 4);
  EXPECT_EQ(tree->left->right->inf, 7);
  EXPECT_EQ(tree->left->left->inf, 2);
  EXPECT_EQ(7, find_el->inf);
}

TEST(Addition, Test_on_add) {
  CNode* tree = new CNode(8);
  CNode* find_el;
  tree->right = new CNode(15);
  tree->right->right = new CNode(20);
  tree->right->left = new CNode(10);
  tree->left = new CNode(4);
  tree->left->left = new CNode(2);
  find_el = find_or_add_el(tree, 7);
  EXPECT_EQ(tree->inf, 8);
  EXPECT_EQ(tree->right->inf, 15);
  EXPECT_EQ(tree->right->right->inf, 20);
  EXPECT_EQ(tree->right->left->inf, 10);
  EXPECT_EQ(tree->left->inf, 4);
  EXPECT_EQ(tree->left->right->inf, 7);
  EXPECT_EQ(tree->left->left->inf, 2);
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
