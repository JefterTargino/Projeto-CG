#include <fstream>
#include <string>
#include <vector>
#include "caxe.hpp"
#include "parser.hpp"
using namespace std;

string ler_objeto(ifstream &arquivo) {
  vector<char> v_char;
  char c;
  while (arquivo.get(c)) {
    if (c != '"') {
      v_char.push_back(c);
    } else {
      break;
    }
  }
  string nome_objeto(v_char.begin(), v_char.end());
  return nome_objeto;
}

vector<Vertice*> ler_arquivo(string filename) {
  Grafo grafo;
  string nome_vertice, nome_adjacente, aresta;
  bool vertice_saved = false, adjacente_saved = false;

  char c;
  ifstream arquivo(filename);
  while (arquivo.get(c)) {
    if (c == '"' && vertice_saved == false) {
      nome_vertice = ler_objeto(arquivo);
      vertice_saved = true;

    } else if (c == '"' && adjacente_saved == false) {
      nome_adjacente = ler_objeto(arquivo);
      adjacente_saved = true;

    } else if (c == '"') {
      aresta = ler_objeto(arquivo);
      grafo.add(nome_vertice, nome_adjacente, stoi(aresta));
      vertice_saved = adjacente_saved = false;
    }
  }
  return grafo.vertices;
}
