#include <iostream>
#include <ostream>
using std::cout;
using std::endl;

void menu() {
  cout << "caxeiro viajante - projeto da disciplina de comp. grafica" << endl;
  cout << "Uso: caxe <arquivo de entrada>" << endl;
}

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    menu();
  }

  return 0;
}
