#include "../include/render.hpp"
#include "../include/keyboard.hpp"
#include "../include/shapes.hpp"
#include <GL/gl.h>
#include <GL/glut.h>

void render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawCube();
  KeyboardHandler::reset();
  KeyboardHandler::rotate();
  KeyboardHandler::translate();
  glutSwapBuffers();
  glFlush();
}
