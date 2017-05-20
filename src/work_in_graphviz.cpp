#include "graph.h"

void start(FILE *fp) {
  fprintf(fp, "digraph G{\n");
}

void add_rib(FILE *fp, int vrt1, int vrt2, int len) {
  fprintf(fp, "%i -> %i [label = \"%i\"];\n", vrt1, vrt2, len);
}

void stop(FILE *fp) {
  fprintf(fp, "}\n");
}
