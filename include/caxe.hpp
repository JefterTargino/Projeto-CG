#ifndef CAXE_H
#define CAXE_H

#include <map>
#include <string>
#include <vector>
using std::map;
using std::string;
using std::vector;

class Vertice {
  public:
    struct Adj {
      Vertice *ptr_vertice;
      int dist_aresta;
    };
    map<string, Adj*> adjacentes;
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

#endif
