#include <fstream>
#include <string>
#include <vector>
#include "caxe.hpp"
#include "parser.hpp"
using std::ifstream;
using std::stoi;
using std::string;
using std::vector;

string ler_nome_vertice(ifstream &arquivo) {
  vector<char> variavel_char;
  char c;
  while (arquivo.get(c)) {
    if (c != '"') {
      variavel_char.push_back(c);
    } else {
      break;
    }
  }
  string nome_vertice(variavel_char.begin(), variavel_char.end());
  return nome_vertice;
}

vector<Vertice*> ler_arquivo(string filename) {
  Grafo grafo;
  string nome_vertice, nome_adjacente, aresta;
  bool vertice_saved = false, adjacente_saved = false;

  char c;
  ifstream arquivo(filename);
  while (arquivo.get(c)) {
    if (c == '"' && vertice_saved == false) {
      nome_vertice = ler_nome_vertice(arquivo);
      vertice_saved = true;

    } else if (c == '"' && adjacente_saved == false) {
      nome_adjacente = ler_nome_vertice(arquivo);
      adjacente_saved = true;

    } else if (c == '"') {
      aresta = ler_nome_vertice(arquivo);
      grafo.add(nome_vertice, nome_adjacente, stoi(aresta));
      vertice_saved = adjacente_saved = false;
    }
  }
  return grafo.vertices;
}
