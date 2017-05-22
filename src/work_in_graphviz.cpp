#include "graph.h"

void start(FILE *fp) {
  fprintf(fp, "digraph G{\n");
}

void add_rib(FILE *fp, int vrt1, int vrt2, int len, char *color) {
  fprintf(fp, "%i -> %i [label = \"%i\"] [color = %s];\n", vrt1, vrt2, len, color);
}

void stop(FILE *fp) {
  fprintf(fp, "}\n");
}
