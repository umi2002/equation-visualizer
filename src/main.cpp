#include "../include/KeyStates.hpp"
#include <GL/glut.h>
#include <glm/glm.hpp>

void drawTetrahedron() {
  const float white[] = {1.0f, 1.0f, 1.0f, 1.0f};
  const float red[] = {1.0f, 0.0f, 0.0f, 1.0f};
  const float green[] = {0.0f, 1.0f, 0.0f, 1.0f};
  const float blue[] = {0.0f, 0.0f, 1.0f, 1.0f};

  const float basePoint1[] = {-0.5f, -0.288675134f,
                              0.0f}; // Bottom Left Vertex of the Base
  const float basePoint2[] = {0.5f, -0.288675134f,
                              0.0f}; // Bottom Right Vertex of the Base
  const float basePoint3[] = {0.0f, 0.577350269f,
                              0.0f}; // Top Middle Vertex of the Base
  const float apexPoint[] = {0.0f, 0.0f, 0.816496581f}; // Apex Vertex

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_TRIANGLES);

  glColor3fv(red);
  glVertex3fv(basePoint1);
  glVertex3fv(basePoint2);
  glVertex3fv(apexPoint);

  glColor3fv(green);
  glVertex3fv(basePoint3);
  glVertex3fv(basePoint1);
  glVertex3fv(apexPoint);

  glColor3fv(blue);
  glVertex3fv(basePoint2);
  glVertex3fv(basePoint3);
  glVertex3fv(apexPoint);

  glColor3fv(white);
  glVertex3fv(basePoint2);
  glVertex3fv(basePoint1);
  glVertex3fv(basePoint3);

  glEnd();
}

void onKeyDown(unsigned char key, int x, int y) {
  KeyStates::keyStates[key] = true;
}

void onKeyUp(unsigned char key, int x, int y) {
  KeyStates::keyStates[key] = false;
}

void rotate() {
  if (KeyStates::keyStates['l']) {
    glRotatef(3.0f, 0.0f, 1.0f, 0.0f);
  }

  if (KeyStates::keyStates['h']) {
    glRotatef(-3.0f, 0.0f, 1.0f, 0.0f);
  }

  if (KeyStates::keyStates['k']) {
    glRotatef(3.0f, 1.0f, 0.0f, 0.0f);
  }

  if (KeyStates::keyStates['j']) {
    glRotatef(-3.0f, 1.0f, 0.0f, 0.0f);
  }
}

void display() {
  drawTetrahedron();
  rotate();
  glutSwapBuffers();
  glFlush();
}

void init() {
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Test");
  glm::vec4 bgColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearColor(bgColor.r, bgColor.g, bgColor.b, bgColor.a);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutKeyboardFunc(onKeyDown);
  glutKeyboardUpFunc(onKeyUp);
  glutIgnoreKeyRepeat(1);

  glutMainLoop();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  init();

  return 0;
}
