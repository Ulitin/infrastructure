int* fun(int *mas, int size) {
  int *n;
  n = new int[size];
  int res = 1;
  if (size == 1) {
    n[0] = mas[0];
    return n;
  }
  for (int i = 0; i < size; i++) {
    n[i] = res;
    res *= mas[i];
  }
  res = 1;
  for (int i = size - 1; i >= 0; i--) {
    n[i] *= res;
    res *= mas[i];
  }
  return n;
}
