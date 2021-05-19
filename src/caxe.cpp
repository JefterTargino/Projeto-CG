#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "caxe.hpp"
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

// definicao da classe Vertice
Vertice::Vertice(string n) {
  nome = n;
}

void Vertice::add_vertice(Vertice *other_vertice, int aresta) {
  Adj<Vertice> *ptr = new Adj<Vertice>;
  ptr->ptr_vertice = other_vertice;
  ptr->dist_aresta = aresta;
  adjacentes.emplace(other_vertice->nome, ptr);
}

void Vertice::mostrar_adjacentes() {
  map<string, Adj<Vertice>*>::iterator x;
  for (x = adjacentes.begin(); x != adjacentes.end(); x++) {
    cout << nome << "->" << x->first << " distancia: " << x->second->dist_aresta << endl;
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

void Grafo::add(string v1, string v2, int aresta) {
  int search_v1 = find_vertice(v1);
  int search_v2 = find_vertice(v2);

  if (search_v1 >= 0) {
    if (search_v2 >= 0) {
      // quando tanto v1 quanto v2 já estão dentro do vector
      vertices[search_v1]->add_vertice(vertices[search_v2], aresta);

    } else {
      // quando apenas v1 está dentro do vector
      Vertice* new_v2 = new Vertice(v2);
      vertices[search_v1]->add_vertice(new_v2, aresta);
      new_v2->add_vertice(vertices[search_v1], aresta);
      vertices.push_back(new_v2);
    }
  } else {
    // quando v1 e v2 não estão dentro do vector
    Vertice *new_v1 = new Vertice(v1), *new_v2 = new Vertice(v2);
    new_v1->add_vertice(new_v2, aresta);
    new_v2->add_vertice(new_v1, aresta);
    vertices.push_back(new_v1);
    vertices.push_back(new_v2);
  }
}

int get_index(string value, vector<string> v) {
  for (int x = 0; x < v.size(); x++) {
    if (v[x] == value) {
      return  x;
    }
  }
  return -1;
}

vector<string> vertices_disponiveis(vector<string> v_passados, map<string, Adj<Vertice>*> adj) {
  vector<string> v_disponiveis;
  map<string, Adj<Vertice>*>::iterator it;
  for (it=adj.begin(); it != adj.end(); it++) {
    v_disponiveis.push_back(it->first);
  }

  for (int x=0; x < v_passados.size(); x++) {
    int seach_result = get_index(v_passados[x], v_disponiveis);
    if (seach_result > -1) {
      v_disponiveis.erase(v_disponiveis.begin() +seach_result);
    }
  }

  return v_disponiveis;
}

void menor_caminho(Vertice v, vector<string> &v_passados) {
  v_passados.push_back(v.nome);
  vector<string> v_disponiveis = vertices_disponiveis(v_passados, v.adjacentes);

  string v_menor = "";
  int dist_menor = 0;
  for (int x=0; x < v_disponiveis.size(); x++) {
    if (dist_menor == 0) {
      v_menor = v_disponiveis[x];
      dist_menor = v.adjacentes[v_disponiveis[x]]->dist_aresta;

    } else if (dist_menor > v.adjacentes[v_disponiveis[x]]->dist_aresta) {
      v_menor = v_disponiveis[x];
      dist_menor = v.adjacentes[v_disponiveis[x]]->dist_aresta;
    }
  }

  if (v_menor != "") {
    menor_caminho(*v.adjacentes[v_menor]->ptr_vertice, v_passados);
  } else {
    v_passados.push_back(v_passados[0]);
  }

}
