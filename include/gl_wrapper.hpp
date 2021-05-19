#ifndef GL_WRAPPER
#define GL_WRAPPER

#include <string>
using std::string;

struct VerticePosition {
  int x;
  int y;
  string nome;
  int cor;
};

struct ArestaPosition {
  int x_begin;
  int y_begin;
  int x_end;
  int y_end;
  int dist;
  int cor;
};

void open_window(int, int, string);

#endif
