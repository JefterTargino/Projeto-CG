#include <fstream>
#include <string>
#include <vector>
using std::ifstream;
using std::string;
using std::vector;

vector<char> ler_arquivo(string filename) {
  // está função lê o arquivo e retorna o conteudo dele
  // em um vector do tipo char

  char c;
  vector<char> texto;
  ifstream file(filename);

  while (file.get(c)) {
    texto.push_back(c);
  }
  return texto;
}
