#include <iostream>
#include <string>
#include <vector>
#include "caxe.hpp"
#include "gl_wrapper.hpp"
#include "parser.hpp"
using namespace std;

extern vector<VerticePosition*> global_var_vertices;
extern vector<ArestaPosition*> global_var_arestas;

VerticePosition *obterPointer(string nome);
void montarArestas(vector<Vertice*>);

int main(int argc, char const *argv[]) {
  if (argc == 2) {
    string arquivo = argv[1];
    vector<Vertice*> vertices = ler_arquivo(arquivo);

    bool breaked = false;
    int x_axis = 50;
    int y_axis = 50;
    int index = 0;

    while (true) {
      for (int x=0; x < 3; x++) {
        if (index < vertices.size()) {
          VerticePosition *v = new VerticePosition;
          v->x = x_axis;
          if (x == 1) {
            // deslocar a segunda coluna
            v->y = y_axis-18;
          } else {
            v->y = y_axis;
          }
          v->nome = vertices[index]->nome;
          v->cor = vertices[index]->cor;
          global_var_vertices.push_back(v);

          x_axis += 90;
          index++;

        } else {
          breaked = true;
          break;
        }
      }

      if (breaked) {
        break;
      } else {
        x_axis = 50;
        y_axis += 100;
      }
    }
    montarArestas(vertices);
    open_window(700, 500, "string");
  }

  return 0;
}

VerticePosition *obterPointer(string nome) {
  VerticePosition *p = nullptr;
  for (int it = 0; it < global_var_vertices.size(); it++) {
    if(global_var_vertices[it]->nome == nome) {
      p = global_var_vertices[it];
    }
  }
  return p;
}

void montarArestas(vector<Vertice*> vertices) {
  for (int x = 0; x != vertices.size(); x++) {
    VerticePosition *v = obterPointer(vertices[x]->nome);

    map<string, Adj<Vertice>*>::iterator it;
    for (it = vertices[x]->adjacentes.begin(); it != vertices[x]->adjacentes.end(); it++) {
      VerticePosition *v_adjacente = obterPointer(it->first);
      ArestaPosition *aresta = new ArestaPosition;
      aresta->x_begin = v->x;
      aresta->y_begin = v->y;
      aresta->x_end = v_adjacente->x;
      aresta->y_end = v_adjacente->y;
      aresta->dist = it->second->dist_aresta;
      global_var_arestas.push_back(aresta);
    }
  }
}
