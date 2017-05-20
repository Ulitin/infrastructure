#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_
#include <stdexcept>
#include <iostream>

using std::cout;

struct rib {
  int lenght = 0;
  int ribStart = 0;
  int ribFinish = 0;
};

struct vertex {
  std::pair<int, int> *vrt;
  vertex *next = nullptr;

  explicit vertex(int number = 1, int lenghts = 0) {
    vrt = new std::pair<int, int>;
    vrt->first = number;
    vrt->second = lenghts;
  }

  void add(int number, int lengths) {
    bool flag = true;
    vertex* ptr = this;
    while (flag && ptr->next != nullptr) {
      if (ptr->vrt->first == number) {
        flag = false;
        ptr->vrt->first = number;
        ptr->vrt->second = lengths;
      }
      ptr = ptr->next;
    }
    if (flag) {
      ptr->next = new vertex(number, lengths);
    }
  }

  void del(int number) {
    auto ptr = this;
    vertex *buf = nullptr;
    while (ptr != nullptr) {
      if (ptr->vrt->first == number) {
        if (buf != nullptr) buf->next = ptr->next;
        ptr->next = nullptr;
        delete ptr;
        ptr = nullptr;
      }
      buf = ptr;
      ptr = ptr->next;
    }
  }

  rib min_() {
    auto ptr = this;
    if (ptr == nullptr) {
      throw std::logic_error("don't cry");
    }
    rib rb;
    rb.ribStart = ptr->vrt->first;
    while (ptr != nullptr) {
      if ((rb.lenght == 0) || (rb.lenght > ptr->vrt->second)) {
        rb.lenght = ptr->vrt->second;
        rb.ribFinish = ptr->vrt->first;
      }
      ptr = ptr->next;
    }
    return rb;
  }

  ~vertex() {
    vertex *tmp = nullptr;
    vertex *del = this;
    while (del != nullptr) {
      tmp = del->next;
      delete del->vrt;
      del = tmp;
    }
  }
};

struct graph {
  vertex *vrts;
  graph *next = nullptr;

  explicit graph(int number = 0, int lenghts = 0) {
    vrts = new vertex(number, lenghts);
  }

  void add(int vrt1, int vrt2 = 0, int lenghts = -1) {
    graph *ptr = this;
    if (&vrts->vrt->first == 0) vrts->add(vrt1, 0);
    if (vrt2 == 0) {
      while (ptr->vrts->vrt->first != vrt1 && ptr->next != nullptr) {
        ptr = ptr->next;
      }
      if (ptr->next == nullptr) ptr->next = new graph(vrt1);
      if (ptr->vrts->vrt->first == vrt1) {
        throw std::logic_error("vertex is created");
      }
    }
    if (vrt2 != 0) {
      while (ptr->vrts->vrt->first != vrt1 && ptr->next != nullptr) {
        ptr = ptr->next;
      }
      if (ptr->next == nullptr && ptr->vrts->vrt->first != vrt1) {
        //  ribs++;
        this->add(vrt1);
        ptr = ptr->next;
      }
      if (lenghts > 0) {
        ptr->vrts->add(vrt2, lenghts);
      } else if (lenghts < 0) {
        throw std::logic_error("way to the vertex is negative");
      }
    }
    ptr->vrts->del(0);  //  improve
  }

  int size_vrt() {
    int size = 0;
    graph *ptr = this;
    while (ptr != nullptr) {
      size++;
      ptr = ptr->next;
    }
    return size;
  }

  vertex* find(int vrt) {
    graph *ptr = this;
    if (ptr == nullptr) return nullptr;
    while (ptr->vrts->vrt->first != vrt) {
      ptr = ptr->next;
      if (ptr == nullptr) return nullptr;
    }
    return ptr->vrts;
  }

  void input_via_txt(FILE *fp) {
    delete this->next;
    this->next = nullptr;
    delete this->vrts;
    this->vrts = new vertex(1);
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
        this->add(vertex, i, ch - 48);
        i++;
      }
    }
  }

  //void out_via_txt(char *c) {

  //}

  ~graph() {
    graph *del = this;
    graph *ptr = nullptr;
    if (del != nullptr) {
      ptr = del->next;
      delete del->vrts;
      del = ptr;
    }
  }
};

struct graphMI {
  int **mas = nullptr;
  int sizeRib = 0;
  int sizeVrt;

  graphMI(int sizeV = 1) {
    sizeVrt = sizeV;
    mas = new int*[1];
    mas[0] = new int[sizeV];
    for (int j = 0; j < sizeVrt; j++) mas[0][j] = 0;
  }

  graphMI(graphMI &copy) {
    mas = new int*[copy.sizeRib];
    sizeRib = copy.sizeRib;
    sizeVrt = copy.sizeVrt;
    for (int i = 0; i < sizeRib; i++) {
      mas[i] = new int[sizeVrt];
      for (int j = 0; j < sizeVrt; j++) {
        mas[i][j] = copy.mas[i][j];
      }
    }
  }

  void add(int vrt1, int vrt2, int lenghts) {
    if (sizeRib != 0) {
      int **new_mas = new int*[sizeRib + 1];
      for (int i = 0; i < sizeRib; i++) {
        new_mas[i] = new int[sizeVrt];
        for (int j = 0; j < sizeVrt; j++) {
          new_mas[i][j] = mas[i][j];
        }
        delete mas[i];
      }
      delete mas;
      new_mas[sizeRib] = new int[sizeVrt];
      for (int i = 0; i < sizeVrt; i++) new_mas[sizeRib][i] = 0;
      new_mas[sizeRib][vrt1 - 1] = lenghts;
      new_mas[sizeRib][vrt2 - 1] = lenghts;
      mas = new_mas;
      sizeRib++;
    }
    if (sizeRib == 0) {
      mas[sizeRib][vrt1 - 1] = lenghts;
      mas[sizeRib][vrt2 - 1] = lenghts;
      sizeRib++;
    }
  }

  void sort() {  //  sort rib ascending
    for (int i = 0; i < sizeRib; i++)
      for (int j = i + 1; j < sizeRib; j++)
        if (this->greater(mas[i],mas[j])) this->swap(i, j);
  }

  bool greater(int *left, int *right) {
    int l = 0, r = 0;
    while (left[l] == 0) l++;
    while (right[r] == 0) r++;
    return left[l] > right[r];
  }

  void swap(int a, int b) {
    int *tmp = mas[a];
    mas[a] = mas[b];
    mas[b] = tmp;
  }

  int ribin(int rib) {
    int in = sizeVrt - 1;
    while (mas[rib][in] == 0) in--;
    return ++in;
  }

  int ribout(int rib) {
    int out = 0;
    while (mas[rib][out] == 0) out++;
    return ++out;
  }

  void input_via_txt(FILE *fp) {
    for (int i = sizeRib; i > 0; i--) delete mas[i];
    for (int j = 0; j < sizeVrt; j++) mas[0][j] = 0;
    sizeRib = 0;
    sizeVrt = 0;
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
        this->add(vertex, i, ch - 48);
        i++;
      }
    }
  }

  ~graphMI() {
    for (int i = 0; i < sizeRib; i++) {
      delete mas[i];
    }
    delete mas;
  }

};

#endif  // INCLUDE_GRAPH_H_
