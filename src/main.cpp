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
void montarArestas(vector<Vertice*>, vector<string>);

int main(int argc, char const *argv[]) {
  if (argc == 2) {
    string arquivo = argv[1];
    vector<Vertice*> vertices = ler_arquivo(arquivo);

    vector<string> v_passados;
    menor_caminho(*vertices[0], v_passados);

    for (int x = 0; x < v_passados.size(); x++) {
      cout << v_passados[x] << endl;
    }

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
    montarArestas(vertices, v_passados);
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

bool checkAresta(string v1, string v2, vector<string> vertices) {
  int search_v1 = get_index(v1, vertices);
  int search_v2 = get_index(v2, vertices);
  cout << "v1 " << search_v1 << " v2 " << search_v2 << endl;

  if (search_v1 > -1 && search_v2 > -1) {
    if ((search_v1 == search_v2+1) || (search_v1 == search_v2-1)) {
      cout << "true" << endl;
      return true;
    } else {
      cout << "false" << endl;
      return false;
    }
  } else {
    return false;
  }
}

void montarArestas(vector<Vertice*> vertices, vector<string> v_passados) {
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
      if (checkAresta(vertices[x]->nome, v_adjacente->nome, v_passados)) {
        aresta->cor = 1;
      } else {
        aresta->cor = 0;
      }
      global_var_arestas.push_back(aresta);
    }
  }
}
