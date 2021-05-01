#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Vertice {
  map<string, int> adjacentes;

  public:
    string nome;

    Vertice(string n) {
      nome = n;
    }

    void add_vertice(string nome, int aresta) {
      adjacentes[nome] = aresta;
    }

    void mostrar_adjacentes() {
      map<string, int>::iterator x;
      for (x = adjacentes.begin(); x != adjacentes.end(); x++) {
        cout << nome << "->" << x->first << endl;
      }
    }
};

class Grafo {
  vector<Vertice> vertices;

  public:
    void add(string v1, string v2, int aresta) {
      bool break_called = false;

      vector<Vertice>::iterator x;
      for (x = vertices.begin(); x != vertices.end(); x++) {
        if (x->nome == v1) {
          x->add_vertice(v2,  aresta);
          break_called = true;
          break;
        }
      }

      if (!break_called) {
        Vertice novo_vertice(v1);
        novo_vertice.add_vertice(v2, aresta);
        vertices.push_back(novo_vertice);
      }
    }
};
