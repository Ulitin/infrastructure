#include <stdio.h>
#include <limits.h>
#include "graph.h"
#include "Dijkstra.h"

void main() {
  //FILE* fp = fopen("graph", "r");
  //if (fp == 0) {
  //  printf("Error open file\n");
  //  return 0;
  //}
  //graph *g = new graph(1);

  //int ch = 0;
  //int i = 1;
  //int vertex = 1;
  //while (ch = fgetc(fp) != EOF) {
  //  if (ch == '#') {
  //    ch = fgetc(fp);
  //    while (ch != '\n') ch = fgetc(fp);
  //    ch = fgetc(fp);
  //  }
  //  if (ch == ' ') ch = fgetc(fp);
  //  if (ch == '\n') {
  //    vertex++;
  //    i = 1;
  //  }
  //  if (i != vertex) g->add(vertex, i, ch - 10);
  //  i++;
  //}
  //fclose(fp);
  graph *g = new graph(1);
  g->add(1, 2, 5);
  g->add(1, 3, 8);
  g->add(1, 5, 2);
  g->add(2, 1, 5);
  g->add(2, 5, 3);
  g->add(3, 1, 8);
  g->add(3, 4, 8);
  g->add(3, 6, 1);
  g->add(4, 3, 8);
  g->add(4, 6, 8);
  g->add(5, 7, 2);
  g->add(6, 1, 5);
  g->add(6, 4, 8);
  g->add(7, 5, 2);
  g->add(7, 3, 1);
  int mode = -1;
  while (mode == -1) {
    printf("\n1 - Heap\n2 - AVL-tree\n");
    scanf("%d", &mode);
  }
  int road;
  if (mode == 1) road = alg_dijkstra(1, 7, g);
  if (mode == 2) road = alg_dijkstra(1, 7, g);
  printf("road - %d\n", road);
}
