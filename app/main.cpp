#include "Primalg.h"
#include "Kruskal.h"
#include "graph.h"

int main() {
  printf("Which algorithm to use?\n");
  int numAlg = -1;
  while (numAlg != 1 && numAlg != 2) {
    printf("\n1 - Kruskal\n2 - Prim\n");
    scanf("%d", &numAlg);
  }

  FILE *fp = fopen("Graph", "r");
  if (fp == 0) {
    printf("Error open file \n");
    return 0;
  }
  if (numAlg == 2) {
    graph g;
    g.input_via_txt(fp);
    graph *res = prim(&g);
    //res->out_via_txt("Resalt.gv");
    delete res;
  }
  if (numAlg == 2) {
    graphMI g;
    g.input_via_txt(fp);
    graphMI *res = kruskal(g);
    //res->out_via_txt("Resalt.gv");
    delete res;
  }
  fclose(fp);
  printf("Resalt in Resalt.gv");
}
