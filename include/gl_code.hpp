#ifndef GL_CODE
#define GL_CODE

#include <string>
using std::string;

struct VerticeStruct {
  int x;
  int y;
  string nome;
  int cor;
};

struct ArestaStruct {
  int x_begin;
  int y_begin;
  int x_end;
  int y_end;
  int dist;
  int cor;
};

void window(int, int);

#endif
