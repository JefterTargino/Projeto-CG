#include <iostream>
#include <ostream>
#include "gl_wrapper.hpp"
using std::cout;
using std::endl;

void menu() {
  cout << "caixeiro viajante - projeto da disciplina de comp. grafica" << endl;
  cout << "Uso: caxe <arquivo de entrada>" << endl;
}

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    menu();
  }

  // teste
  wrapper::open_window(600, 600);

  return 0;
}
