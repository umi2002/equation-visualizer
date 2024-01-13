#include "../include/shapes.hpp"
#include "../include/colors.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <glm/glm.hpp>

void drawTetrahedron() {
  const GLfloat radius = sqrt(3.0f) / 2.0f;
  const GLfloat height = sqrt(2.0f / 3.0f);
  const GLfloat centerDistance = sqrt(3.0f / 4.0f) / 2.0f;

  const glm::vec3 apexVertex = glm::vec3(0, height / 2.0f, 0);
  const glm::vec3 baseFrontLeftVertex =
      glm::vec3(-0.5f, -centerDistance, -radius / 3.0f);
  const glm::vec3 baseFrontRightVertex =
      glm::vec3(0.5f, -centerDistance, -radius / 3.0f);
  const glm::vec3 baseBackVertex =
      glm::vec3(0, -centerDistance, 2.0f * radius / 3.0f);

  glBegin(GL_TRIANGLES);

  glColor3fv(colors::RED);
  glVertex3fv(&baseFrontLeftVertex[0]);
  glVertex3fv(&baseFrontRightVertex[0]);
  ;
  glVertex3fv(&apexVertex[0]);

  glColor3fv(colors::GREEN);
  glVertex3fv(&baseBackVertex[0]);
  glVertex3fv(&baseFrontLeftVertex[0]);
  glVertex3fv(&apexVertex[0]);

  glColor3fv(colors::BLUE);
  glVertex3fv(&baseFrontRightVertex[0]);
  glVertex3fv(&baseBackVertex[0]);
  glVertex3fv(&apexVertex[0]);

  glColor3fv(colors::WHITE);
  glVertex3fv(&baseFrontRightVertex[0]);
  glVertex3fv(&baseFrontLeftVertex[0]);
  ;
  glVertex3fv(&baseBackVertex[0]);

  glEnd();
}

void drawCube() {
  const glm::vec3 bottomFrontLeft = glm::vec3(-0.5, -0.5, -0.5);
  const glm::vec3 bottomFrontRight = glm::vec3(0.5, -0.5, -0.5);
  const glm::vec3 topFrontRight = glm::vec3(0.5, 0.5, -0.5);
  const glm::vec3 topFrontLeft = glm::vec3(-0.5, 0.5, -0.5);
  const glm::vec3 bottomBackLeft = glm::vec3(-0.5, -0.5, 0.5);
  const glm::vec3 bottomBackRight = glm::vec3(0.5, -0.5, 0.5);
  const glm::vec3 topBackRight = glm::vec3(0.5, 0.5, 0.5);
  const glm::vec3 topBackLeft = glm::vec3(-0.5, 0.5, 0.5);

  glBegin(GL_TRIANGLES);

  glColor3fv(colors::RED);
  glVertex3fv(&bottomFrontLeft[0]);
  glVertex3fv(&bottomFrontRight[0]);
  glVertex3fv(&topFrontLeft[0]);
  glVertex3fv(&bottomFrontRight[0]);
  glVertex3fv(&topFrontRight[0]);
  glVertex3fv(&topFrontLeft[0]);

  glColor3fv(colors::GREEN);
  glVertex3fv(&bottomBackLeft[0]);
  glVertex3fv(&bottomFrontLeft[0]);
  glVertex3fv(&topBackLeft[0]);
  glVertex3fv(&bottomFrontLeft[0]);
  glVertex3fv(&topFrontLeft[0]);
  glVertex3fv(&topBackLeft[0]);

  glColor3fv(colors::BLUE);
  glVertex3fv(&bottomFrontRight[0]);
  glVertex3fv(&bottomBackRight[0]);
  glVertex3fv(&topFrontRight[0]);
  glVertex3fv(&bottomBackRight[0]);
  glVertex3fv(&topBackRight[0]);
  glVertex3fv(&topFrontRight[0]);

  glColor3fv(colors::WHITE);
  glVertex3fv(&bottomBackRight[0]);
  glVertex3fv(&bottomBackLeft[0]);
  glVertex3fv(&topBackRight[0]);
  glVertex3fv(&bottomBackLeft[0]);
  glVertex3fv(&topBackLeft[0]);
  glVertex3fv(&topBackRight[0]);

  glColor3fv(colors::YELLOW);
  glVertex3fv(&bottomFrontRight[0]);
  glVertex3fv(&bottomFrontLeft[0]);
  glVertex3fv(&bottomBackRight[0]);
  glVertex3fv(&bottomFrontLeft[0]);
  glVertex3fv(&bottomBackLeft[0]);
  glVertex3fv(&bottomBackRight[0]);

  glColor3fv(colors::CYAN);
  glVertex3fv(&topFrontLeft[0]);
  glVertex3fv(&topFrontRight[0]);
  glVertex3fv(&topBackLeft[0]);
  glVertex3fv(&topFrontRight[0]);
  glVertex3fv(&topBackRight[0]);
  glVertex3fv(&topBackLeft[0]);

  glEnd();
}
