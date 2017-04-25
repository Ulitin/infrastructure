#include "alg.h"

void fun_uf(int** arr, int n, int m) {
  return;
}

void rewrite(int **res, int **arr, int i, int j, int n, int m) {
  if (arr[i][j] == 1 && res[i][j] == 0) {
    res[i][j] = 1;
    if (i < n - 1) rewrite(res, arr, i + 1, j, n, m);
    if (j < m - 1) rewrite(res, arr, i, j + 1, n, m);
    if (i > 0) rewrite(res, arr, i - 1, j, n, m);
    if (j > 0) rewrite(res, arr, i, j - 1, n, m);
  }
}

int** fun_bypass(int** arr, int n, int m) {
  int **res = new int*[n];
  for (int i = 0; i < n; i++) {
    res[i] = new int[m];
    for (int j = 0; j < 5; j++)res[i][j] = 0;
  }
  for (int i = 0; i < n; i++) rewrite(res, arr, i, 0, n, m);
  for (int i = 0; i < n; i++) rewrite(res, arr, i, m - 1, n, m);
  for (int i = 0; i < m; i++) rewrite(res, arr, 0, i, n, m);
  for (int i = 0; i < m; i++) rewrite(res, arr, n - 1, i, n, m);
  for (int i = 0; i < 10; i++) {
    delete arr[i];
  }
  delete arr;
  return res;
}
