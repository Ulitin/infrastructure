#include "alg.h"
#include "percolation.h"

int dev(int x, int y) {
  int res = 0;
  while (x - y > 0) {
    res++;
    x = x - y;
  }
  return res;
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

void test_on_grand(int **arr, percolation per, int i, int j, int n, int m) {
  if (arr[i][j] == 1) per.union_(n * m, i * m + j);
}

void find_earth(int** arr, percolation per, int i, int j, int n, int m) {
  if (arr[i][j] == 1) {
    if (arr[i - 1][j] == 1) per.union_(i * m + j, (i - 1) * m + j);
    if (arr[i + 1][j] == 1) per.union_(i * m + j, (i + 1) * m + j);
    if (arr[i][j - 1] == 1) per.union_(i * m + j, i * m + j - 1);
    if (arr[i][j + 1] == 1) per.union_(i * m + j, i * m + j + 1);
  }
}

void drown_grand(int** arr, percolation per, int i, int j, int n, int m) {
  int del = per.find_(i * m + j);
  for (int k = 0; k < (n - 1)*m - 1; k++) {
    if (per.items[k] == del) arr[dev(k, m)][k%m] = 0;
  }
}

void test_on_drown(int** arr, percolation per, int i, int j, int n, int m) {
  if (per.find_(i * m + j) != per.find_(n * m)) drown_grand(arr, per, i, j, n, m);
}

void fun_uf(int** arr, int n, int m) {
  percolation per(n*m + 1);  //  n*m - earth
  for (int i = 0; i < m; i++) test_on_grand(arr, per, 0, i, n, m);
  for (int i = 1; i < n; i++) test_on_grand(arr, per, i, 0, n, m);
  for (int i = 1; i < m; i++) test_on_grand(arr, per, n - 1, i, n, m);
  for (int i = 1; i < n - 1; i++) test_on_grand(arr, per, i, m - 1, n, m);
  int size = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      find_earth(arr, per, i, j, n, m);
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (arr[i][j] == 1) test_on_drown(arr, per, i, j, n, m);
    }
  }
}
