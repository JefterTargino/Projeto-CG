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
    map<string, Vertice*> adjacentes;
    string nome;
    int cor;

    Vertice(string);
    void add_vertice(Vertice*);
    void mostrar_adjacentes();
};

class Grafo {
  private:
    int find_vertice(string);
  public:
    vector<Vertice*> vertices;
    void add(string, string);
};

#endif
