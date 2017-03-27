#include "queue"
using std::queue;

char* min_road(int x1, int y1, int x2, int y2) {
  char* road = new char[9999];
  int shift = 1;
  while (x1 != x2) {
    if (x1 < x2) {
      x1 += shift;
      road[shift - 1] = 'W';
    }
    if (x1 > x2) {
      x1 -= shift;
      road[shift - 1] = 'E';
    }
    shift++;
  }
  while (y1 != y2) {
    if (y1 < y2) {
      y1 += shift;
      road[shift - 1] = 'N';
    }
    if (y1 > y2) {
      y1 -= shift;
      road[shift - 1] = 'S';
    }
    shift++;
  }
  road[shift - 1] = 0;
  return road;
}
