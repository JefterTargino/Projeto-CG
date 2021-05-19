#include <cmath>
#include <string>
#include <GL/glut.h>
#include <vector>
#include "gl_code.hpp"
using namespace std;

vector<VerticeStruct*> GLOBAL_VERTICES;
vector<ArestaStruct*> GLOBAL_ARESTAS;

void DesenhaCirculo(GLfloat raio, int posx, int posy) {
  int num_linhas = 100;
  GLfloat angulo = (GLfloat)(2 * 3.14) / num_linhas;

  glBegin(GL_POLYGON);
  for (int i = 1; i <= num_linhas; i++) {
    glVertex2f(posx + cos(i * angulo) * raio, posy + sin(i * angulo) * raio);
  }
  glEnd();
}

void drawText(const char* text, int length, int x, int y) {
  double* matrix = new double[16];
  glGetDoublev(GL_PROJECTION_MATRIX, matrix);
  glOrtho(0, 800, 0, 600, -5, 5);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glLoadIdentity();
  glRasterPos2i(x, y);
  for (int i=0; i < length; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
  }
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixd(matrix);
  glMatrixMode(GL_MODELVIEW);
}

void drawVertice(int x, int y, string text, int cor) {
// circulo externo
  glColor3f(0.0f, 0.0f, 0.0f);
  DesenhaCirculo(15, x, y);

  // circulo interno
  glColor3f(1.0f, 1.0f, 1.0f);
  DesenhaCirculo(13, x, y);

  // texto dentro do vertive
  glColor3f(0.0f, 0.0f, 0.0f);
  const char *str = text.c_str();
  drawText(str, text.size(), x-4, y-2);
}

void drawAresta(int x_begin, int y_begin, int x_end, int y_end, int dist, int cor) {
  glLineWidth(5.0f);
  glBegin(GL_LINES);
    if (cor == 0) {
      glColor3f(0.0f, 0.0f, 0.0f); // preto
    } else {
      glColor3f(1.0f, 0.0f, 0.0f); // vermelho
    }
    glVertex2f(x_begin, y_begin);
    glVertex2f(x_end, y_end);
  glEnd();

  string num = to_string(dist);
  drawText(num.c_str(),
               num.size(),
               x_begin+((x_end-x_begin)/2),
               y_begin+((y_end-y_begin)/2));
}

void Draw(void) {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);

  for (int i = 0; i < GLOBAL_ARESTAS.size(); i++) {
    drawAresta(GLOBAL_ARESTAS[i]->x_begin,
                  GLOBAL_ARESTAS[i]->y_begin,
                  GLOBAL_ARESTAS[i]->x_end,
                  GLOBAL_ARESTAS[i]->y_end,
                  GLOBAL_ARESTAS[i]->dist,
                  GLOBAL_ARESTAS[i]->cor);
  }

  for (int i = 0; i < GLOBAL_VERTICES.size(); i++) {
    drawVertice(GLOBAL_VERTICES[i]->x,
                   GLOBAL_VERTICES[i]->y,
                   GLOBAL_VERTICES[i]->nome,
                   GLOBAL_VERTICES[i]->cor);
  }

  glutSwapBuffers();
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // cor de fundo da janela
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
  if(h == 0) h = 1; // Evita a divisao por zero
  glViewport(0, 0, w, h); // Especifica as dimensões da Viewport

  // Inicializa o sistema de coordenadas
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h)
    gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
  else
    gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

void window(int width, int height) {
  int argc = 1; char *argv[1] = {(char*)""}; // parametros do glutinit
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(width, height);
  glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2,
                       (glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
  glutCreateWindow("caixeiro viajante");
  glutDisplayFunc(Draw);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutMainLoop();
}
