#include "../include/init.hpp"
#include "../include/colors.hpp"
#include "../include/keyboard.hpp"
#include "../include/render.hpp"
#include <GL/glut.h>

void init() {
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Test");
  glClearColor(colors::BLACK[0], colors::BLACK[1], colors::BLACK[2],
               colors::BLACK[3]);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glutDisplayFunc(render);
  glutIdleFunc(render);
  glutKeyboardFunc(KeyboardHandler::onKeyDown);
  glutKeyboardUpFunc(KeyboardHandler::onKeyUp);
  glutIgnoreKeyRepeat(1);

  glutMainLoop();
}
