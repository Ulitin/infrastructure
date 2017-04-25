//#include "matrixr.h"
////#include <iostream>  
////#include <random> 
////#include <ctime>
//
//matrix::matrix(int Nsize, int Msize) {
//  arr = new int*[Nsize];
//  for (int i = 0; i < Nsize; i++) {
//    arr[i] = new int[Msize];
//    for (int j = 0; j < Msize; j++) arr[i][j] = 0;
//  }
//  n = Nsize;
//  m = Msize;
//}
//
//int* matrix::find(int i, int j) {
//  return arr[i] + j;
//}
//
//void matrix::rand_input(int ini, int el) {
//  //for (int i = 0; i < el; i++) {
//  //  std::mt19937 gen(time(0));
//  //  std::uniform_int_distribution<> uid(0, n - 1);
//  //  int n_ = uid(gen);
//  //  std::uniform_int_distribution<> uid(0, m - 1);
//  //  int m_ = uid(gen);
//  //  if (arr[n_][m_] == ini) rand_input(ini, 1);
//  //  if (arr[n_][m_] != ini) arr[n_][m_] = ini;
//  //}
//  return;
//}
