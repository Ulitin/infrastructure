#include <gtest/gtest.h>
#include "graph.h"
#include "Dijkstra.h"
#include "avl_tree.h"
#include "heap.h"
#include "Primalg.h"
#include "percolation.h"
#include "Kruskal.h"

TEST(vertex, smoke_and_input) {
  vertex v1;
  vertex v2(2);
  vertex v3(3, 3);
  EXPECT_EQ(v1.vrt->first, 1);
  EXPECT_EQ(v1.vrt->second, 0);
  EXPECT_EQ(v2.vrt->first, 2);
  EXPECT_EQ(v2.vrt->second, 0);
  EXPECT_EQ(v3.vrt->first, 3);
  EXPECT_EQ(v3.vrt->second, 3);
}

TEST(vertex, create_vertex) {
  vertex *v1 = new vertex(1);
  v1->add(2, 5);
  vertex *ptr = v1->next;
  EXPECT_EQ(v1->vrt->first, 1);
  EXPECT_EQ(v1->vrt->second, 0);
  EXPECT_EQ(ptr->vrt->first, 2);
  EXPECT_EQ(ptr->vrt->second, 5);
  }

TEST(graph, smoke_and_input) {
  graph g1;
  graph g2(2);
  graph g3(3, 3);
  EXPECT_EQ(g1.vrts->vrt->first, 0);
  EXPECT_EQ(g1.vrts->vrt->second, 0);
  EXPECT_EQ(g2.vrts->vrt->first, 2);
  EXPECT_EQ(g2.vrts->vrt->second, 0);
  EXPECT_EQ(g3.vrts->vrt->first, 3);
  EXPECT_EQ(g3.vrts->vrt->second, 3);
  //  EXPECT_EQ(g1.ribs, 0);
  //  EXPECT_EQ(g2.ribs, 0);
  //  EXPECT_EQ(g3.ribs, 0);
}

TEST(graph, find_size_vrt) {
  graph g1(1);
  g1.add(1, 2, 5);
  g1.add(1, 3, 8);
  g1.add(2, 1, 5);
  g1.add(3, 1, 8);
  EXPECT_EQ(g1.size_vrt(), 3);
}

TEST(graph, enter_graph_manually) {
  graph g1(1);
  g1.add(1, 2, 5);
  g1.add(1, 3, 8);
  g1.add(2, 1, 5);
  g1.add(3, 1, 8);
  EXPECT_EQ(g1.vrts->vrt->first, 1);
  EXPECT_EQ(g1.vrts->vrt->second, 0);
  EXPECT_EQ(g1.vrts->next->vrt->first, 2);
  EXPECT_EQ(g1.vrts->next->vrt->second, 5);
  EXPECT_EQ(g1.vrts->next->next->vrt->first, 3);
  EXPECT_EQ(g1.vrts->next->next->vrt->second, 8);
  EXPECT_EQ(g1.next->vrts->vrt->first, 2);
  EXPECT_EQ(g1.next->vrts->vrt->second, 0);
  EXPECT_EQ(g1.next->vrts->next->vrt->first, 1);
  EXPECT_EQ(g1.next->vrts->next->vrt->second, 5);
  EXPECT_EQ(g1.next->next->vrts->vrt->first, 3);
  EXPECT_EQ(g1.next->next->vrts->vrt->second, 0);
  EXPECT_EQ(g1.next->next->vrts->next->vrt->first, 1);
  EXPECT_EQ(g1.next->next->vrts->next->vrt->second, 8);
  //  EXPECT_EQ(g1.ribs, 2);
}

TEST(graph, test_add_and_find) {
  graph g(1);
  g.add(1, 2, 5);
  g.add(1, 3, 8);
  g.add(2, 1, 5);
  g.add(3, 1, 8);
  vertex *f = g.find(3);
  EXPECT_EQ(f->vrt->first, 3);
  EXPECT_EQ(f->vrt->second, 0);
  EXPECT_EQ(f->next->vrt->first, 1);
  EXPECT_EQ(f->next->vrt->second, 8);
  f = g.find(2);
  EXPECT_EQ(f->vrt->first, 2);
  EXPECT_EQ(f->vrt->second, 0);
  EXPECT_EQ(f->next->vrt->first, 1);
  EXPECT_EQ(f->next->vrt->second, 5);
  f = g.find(1);
  EXPECT_EQ(f->vrt->first, 1);
  EXPECT_EQ(f->vrt->second, 0);
  EXPECT_EQ(f->next->vrt->first, 2);
  EXPECT_EQ(f->next->vrt->second, 5);
  EXPECT_EQ(f->next->next->vrt->first, 3);
  EXPECT_EQ(f->next->next->vrt->second, 8);
  //  ;
  EXPECT_EQ(g.vrts->vrt->first, 1);
  EXPECT_EQ(g.vrts->vrt->second, 0);
  EXPECT_EQ(g.vrts->next->vrt->first, 2);
  EXPECT_EQ(g.vrts->next->vrt->second, 5);
  EXPECT_EQ(g.vrts->next->next->vrt->first, 3);
  EXPECT_EQ(g.vrts->next->next->vrt->second, 8);
  EXPECT_EQ(g.next->vrts->vrt->first, 2);
  EXPECT_EQ(g.next->vrts->vrt->second, 0);
  EXPECT_EQ(g.next->vrts->next->vrt->first, 1);
  EXPECT_EQ(g.next->vrts->next->vrt->second, 5);
  EXPECT_EQ(g.next->next->vrts->vrt->first, 3);
  EXPECT_EQ(g.next->next->vrts->vrt->second, 0);
  EXPECT_EQ(g.next->next->vrts->next->vrt->first, 1);
  EXPECT_EQ(g.next->next->vrts->next->vrt->second, 8);
  //  EXPECT_EQ(g.ribs, 2);
}

TEST(graph, find_min) {
  graph *g1 = new graph(1);
  g1->add(1, 2, 5);
  g1->add(1, 3, 8);
  g1->add(1, 4, 1);
  g1->add(1, 5, 2);
  g1->add(1, 6, 5);
  g1->add(2, 1, 5);
  g1->add(2, 5, 3);
  g1->add(3, 1, 8);
  g1->add(3, 4, 8);
  g1->add(3, 6, 1);
  g1->add(3, 7, 1);
  g1->add(4, 3, 8);
  g1->add(4, 6, 8);
  g1->add(5, 1, 2);
  g1->add(5, 2, 3);
  g1->add(5, 7, 2);
  g1->add(6, 1, 5);
  g1->add(6, 4, 8);
  rib res = g1->vrts->min_();
  EXPECT_EQ(res.lenght, 1);
  EXPECT_EQ(res.ribStart, 1);
  EXPECT_EQ(res.ribFinish, 4);
  res = g1->next->next->vrts->min_();
  EXPECT_EQ(res.lenght, 1);
  EXPECT_EQ(res.ribStart, 3);
  EXPECT_EQ(res.ribFinish, 6);
  delete g1;
}

TEST(graphMI, test_on_smoke) {
  graphMI g(3);
  g.add(1, 2, 5);
  g.add(1, 3, 8);
  int **mas = g.mas;
  EXPECT_EQ(mas[0][0], 5);
  EXPECT_EQ(mas[0][1], 5);
  EXPECT_EQ(mas[1][0], 8);
  EXPECT_EQ(mas[1][2], 8);
  mas[0][0] = 0;
  mas[0][1] = 0;
  mas[1][0] = 0;
  mas[1][2] = 0;
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      EXPECT_EQ(mas[i][j], 0);
}

TEST(graphMI, test_on_sort) {
  graphMI g(3);
  g.add(1, 3, 2);
  g.add(2, 3, 1);
  g.sort();
  int **mas = g.mas;
  EXPECT_EQ(mas[0][1], 1);
  EXPECT_EQ(mas[0][2], 1);
  EXPECT_EQ(mas[1][0], 2);
  EXPECT_EQ(mas[1][2], 2);
  mas[0][1] = 0;
  mas[0][2] = 0;
  mas[1][0] = 0;
  mas[1][2] = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      EXPECT_EQ(mas[i][j], 0);
}

TEST(avl_tree, test_on_smoke) {
  avl_tree *tree = new avl_tree(std::make_pair(1, 0));
  for (int i = 10; i > 1; i--) tree = insert(tree, std::make_pair(i, 0));
  for (int i = 10; i > 0; i--) tree = removemin(tree);
  if (tree != nullptr) FAIL();
}

TEST(avl_tree, test_find) {
  avl_tree *tree = new avl_tree(std::make_pair(1, 0));
  tree = insert(tree, std::make_pair(2, 0));
  avl_tree *ptr = begin(tree);
  EXPECT_EQ(ptr->var.first, 1);
  tree = removemin(tree);
  tree = removemin(tree);
}

TEST(heap, add_del) {
  heap test;
  rib rb;
  for (int i = 1000; i > 0; i--) {
    test.insert(rb);
    rb.lenght++;
    rb.ribStart++;
    rb.ribFinish++;
  }
  for (int i = 1000; i > 0; i--) test.remove(test.begin());
  if (!test.empty()) FAIL();
}

TEST(heap, find) {
  heap test;
  rib rb;
  rb.lenght = 3;
  rb.ribStart = 1;
  rb.ribFinish = 5;
  test.insert(rb);
  rb.lenght = 1;
  rb.ribStart = 1;
  rb.ribFinish = 2;
  test.insert(rb);
  rb.lenght = 8;
  rb.ribStart = 5;
  rb.ribFinish = 3;
  test.insert(rb);
  rb.lenght = 2;
  rb.ribStart = 6;
  rb.ribFinish = 4;
  test.insert(rb);
  rib *f = test.find(5);
  rib *minEl = test.begin();
  EXPECT_EQ(f->lenght, 3);
  EXPECT_EQ(f->ribStart, 1);
  EXPECT_EQ(f->ribFinish, 5);
  EXPECT_EQ(minEl->lenght, 1);
  EXPECT_EQ(minEl->ribStart, 1);
  EXPECT_EQ(minEl->ribFinish, 2);
  for (int i = 4; i > 0; i--) test.remove(test.begin());
  if (!test.empty()) FAIL();
}

TEST(percolation, test1) {
  percolation p(10);
  p.union_(10, 1);
  p.union_(1, 5);
  p.union_(5, 9);
  p.union_(2, 9);
  p.union_(2, 7);
  EXPECT_EQ(p.find_(7), p.find_(10));
}

TEST(Primalg, test_on_smoke) {
  graph *g1 = new graph(1);
  g1->add(1, 2, 1);
  g1->add(1, 3, 1);
  g1->add(1, 4, 1);
  g1->add(1, 5, 1);
  g1->add(2, 1, 1);
  g1->add(2, 5, 3);
  g1->add(3, 1, 1);
  g1->add(3, 4, 8);
  g1->add(4, 1, 1);
  g1->add(4, 3, 8);
  g1->add(5, 1, 1);
  g1->add(5, 2, 3);
  graph *g = prim(g1);
  EXPECT_EQ(g->vrts->vrt->first, 1);
  EXPECT_EQ(g->vrts->vrt->second, 0);
  EXPECT_EQ(g->vrts->next->vrt->first, 2);
  EXPECT_EQ(g->vrts->next->vrt->second, 1);
  EXPECT_EQ(g->vrts->next->next->vrt->first, 5);
  EXPECT_EQ(g->vrts->next->next->vrt->second, 1);
  EXPECT_EQ(g->vrts->next->next->next->vrt->first, 3);
  EXPECT_EQ(g->vrts->next->next->next->vrt->second, 1);
  EXPECT_EQ(g->vrts->next->next->next->next->vrt->first, 4);
  EXPECT_EQ(g->vrts->next->next->next->next->vrt->second, 1);
  delete g1;
}

TEST(Primalg, test_in_normal_graph) {
  graph *g1 = new graph(1);
  g1->add(1, 2, 5);
  g1->add(1, 3, 8);
  g1->add(1, 4, 1);
  g1->add(1, 5, 2);
  g1->add(1, 6, 5);
  g1->add(2, 1, 5);
  g1->add(2, 5, 3);
  g1->add(3, 1, 8);
  g1->add(3, 4, 8);
  g1->add(3, 6, 1);
  g1->add(4, 3, 8);
  g1->add(4, 6, 8);
  g1->add(5, 1, 2);
  g1->add(5, 2, 3);
  g1->add(6, 1, 5);
  g1->add(6, 4, 8);
  graph *g = prim(g1);
  delete g1;
}

TEST(Kruskal, test_in_normal_graph) {
  graphMI g(6);
  g.add(1, 2, 5);
  g.add(1, 3, 8);
  g.add(1, 4, 1);
  g.add(1, 5, 4);
  g.add(1, 6, 5);
  g.add(2, 5, 3);
  g.add(3, 4, 8);
  g.add(3, 6, 2);
  g.add(4, 6, 8);
  g.add(6, 4, 3);
  graphMI *res = kruskal(g);
  int **mas = res->mas;
  EXPECT_EQ(mas[0][0], 1);
  EXPECT_EQ(mas[0][3], 1);
  EXPECT_EQ(mas[1][2], 2);
  EXPECT_EQ(mas[1][5], 2);
  EXPECT_EQ(mas[2][1], 3);
  EXPECT_EQ(mas[2][4], 3);
  EXPECT_EQ(mas[3][5], 3);
  EXPECT_EQ(mas[3][3], 3);
  EXPECT_EQ(mas[4][0], 4);
  EXPECT_EQ(mas[4][4], 4);
  mas[0][0] = 0;
  mas[0][3] = 0;
  mas[1][2] = 0;
  mas[1][5] = 0;
  mas[2][1] = 0;
  mas[2][4] = 0;
  mas[3][5] = 0;
  mas[3][3] = 0;
  mas[4][0] = 0;
  mas[4][4] = 0;
  for (int i = 0; i < res->sizeRib; i++)
    for (int j = 0; j < res->sizeVrt; j++)
      EXPECT_EQ(mas[i][j], 0);
}
