#include <iostream>
#include <map>
#include <string>
#include "caxe.hpp"
using std::cout;
using std::endl;
using std::map;
using std::string;

// definicao da classe Vertice
Vertice::Vertice(string n) {
  nome = n;
}

void Vertice::add_vertice(Vertice *other_vertice) {
  adjacentes.emplace(other_vertice->nome, other_vertice);
}

void Vertice::mostrar_adjacentes() {
  map<string, Vertice*>::iterator x;
  for (x = adjacentes.begin(); x != adjacentes.end(); x++) {
    cout << nome << "->" << x->first << endl;
  }
}

// definicao da classe Grafo
int Grafo::find_vertice(string v) {
  int index = 0;
  while (index < vertices.size()) {
    if (vertices[index]->nome == v) {
      return index;
    } else {
      index++;
    }
  }

  return -1;
}

void Grafo::add(string v1, string v2) {
  int search_v1 = find_vertice(v1);
  int search_v2 = find_vertice(v2);

  if (search_v1 >= 0) {
    if (search_v2 >= 0) {
      // quando tanto v1 quanto v2 já estão dentro do vector
      vertices[search_v1]->add_vertice(vertices[search_v2]);

    } else {
      // quando apenas v1 está dentro do vector
      Vertice* new_v2 = new Vertice(v2);
      vertices[search_v1]->add_vertice(new_v2);
      new_v2->add_vertice(vertices[search_v1]);
      vertices.push_back(new_v2);
    }
  } else {
    // quando v1 e v2 não estão dentro do vector
    Vertice *new_v1 = new Vertice(v1), *new_v2 = new Vertice(v2);
    new_v1->add_vertice(new_v2);
    new_v2->add_vertice(new_v1);
    vertices.push_back(new_v1);
    vertices.push_back(new_v2);
  }
}
