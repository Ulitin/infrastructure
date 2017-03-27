#include <gtest/gtest.h>
#include "road.h"

TEST(Addition, road) {
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;
  for (int i = 0; i < 50; i++, x2 = i, y2 = i) {
    char* road = min_road(x1, y1, x2, y2);
    int j = 1;
    while (road[j - 1] != 0) {
      if (road[j - 1] == 'N') y1 += j;
      if (road[j - 1] == 'S') y1 -= j;
      if (road[j - 1] == 'E') x1 -= j;
      if (road[j - 1] == 'W') x1 += j;
      j++;
    }
    if (x1 != x2 || y1 != y2) {
      EXPECT_EQ(1,2);
    }
    x1 = 0;
    y1 = 0;
  }
}
