#include <GL/glut.h>

void display() {

  // apaga as informacoes de cor da renderizacao anterior
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void open_window(int width, int height) {
    // inicializar as funcoes GLUT
  //glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // define os metodos de renderizacao

  glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2, // posiciona a janela
                       (glutGet(GLUT_SCREEN_HEIGHT)-480)/2); // no centro da tela
  //700, 400
  glutInitWindowSize(width, height);
  glutCreateWindow("caxeiro viajante");

  glutDisplayFunc(display);
  glutMainLoop();
}
