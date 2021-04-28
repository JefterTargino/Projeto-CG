#include <string>
#include <vector>
using std::string;
using std::vector;

class Vertice {
  private:
      vector<Vertice> vertices;

  public:
    string nome;

    void add_vertice(Vertice v) {
      vertices.push_back(v);
    }
};
