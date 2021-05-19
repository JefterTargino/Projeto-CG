#ifndef CAXE_H
#define CAXE_H

#include <map>
#include <string>
#include <vector>
using std::map;
using std::string;
using std::vector;

template<typename T>
struct Adj {
  T *ptr_vertice;
  int dist_aresta;
};

class Vertice {
  public:
    map<string, Adj<Vertice>*> adjacentes;
    string nome;
    int cor;

    Vertice(string);
    void add_vertice(Vertice*, int);
    void mostrar_adjacentes();
};

class Grafo {
  private:
    int find_vertice(string);
  public:
    vector<Vertice*> vertices;
    void add(string, string, int);
};

void menor_caminho(Vertice, vector<string> &);

#endif
