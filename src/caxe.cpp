#include <map>
#include <string>
using std::map;
using std::string;

class Vertice {
  map<string, int> adjacentes;

  public:
    string nome;

    void add_vertice(Vertice v, int aresta) {
      adjacentes[v.nome] = aresta;
    }
};
