#include <stdio.h>
#include <limits.h>
#include "graph.h"
#include "Dijkstra.h"

void main() {
  printf("path to file: ");
  char path[150];
  scanf("%s", path);
  FILE* fp = fopen(path, "r");
  if (fp == 0) {
    printf("Error open file \n");
    return;
  }
  graph *g = new graph(1);

  int ch = 0;
  int i = 1;
  int vertex = 1;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '#') {
      ch = fgetc(fp);
      while (ch != '\n') ch = fgetc(fp);
      ch = fgetc(fp);
    }
    if (ch == ' ') ch = fgetc(fp);
    if (ch == '\n') {
      vertex++;
      i = 1;
    }
    if (ch >= 48 && ch <= 57) {
      g->add(vertex, i, ch - 48);
      i++;
    }
  }
  fclose(fp);
  int mode = -1;
  while (mode == -1) {
    printf("\n1 - Heap\n2 - AVL-tree\n");
    scanf("%d", &mode);
  }
  int road;
  if (mode == 1) road = dijkstra_heap(g);
  if (mode == 2) road = dijkstra_tree(g);
  printf("road - %d\n", road);
}
