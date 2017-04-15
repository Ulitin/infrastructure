#include <gtest/gtest.h>
#include "graph.h"
#include "Dijkstra.h"

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
}

TEST(Dijkstra, test_on_smoke) {
  graph *g1 = new graph(1);
  g1->add(1, 2, 5);
  g1->add(1, 3, 8);
  g1->add(2, 1, 5);
  g1->add(3, 1, 8);
  int res = alg_dijkstra(1, 3, g1);
  EXPECT_EQ(res, 8);
  delete g1;
}

TEST(Dijkstra, hard_test) {
  graph *g1 = new graph(1);
  g1->add(1, 2, 5);
  g1->add(1, 3, 8);
  g1->add(1, 5, 2);
  g1->add(2, 1, 5);
  g1->add(2, 5, 3);
  g1->add(3, 1, 8);
  g1->add(3, 4, 8);
  g1->add(3, 6, 1);
  g1->add(4, 3, 8);
  g1->add(4, 6, 8);
  g1->add(5, 7, 2);
  g1->add(6, 1, 5);
  g1->add(6, 4, 8);
  g1->add(7, 5, 2);
  g1->add(7, 3, 1);
  int res = alg_dijkstra(1, 7, g1);
  EXPECT_EQ(res, 4);
  delete g1;
}
