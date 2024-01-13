#pragma once
#include <glm/glm.hpp>
#include <GL/gl.h>
#include <stack>

class Transform {
public:
  static void saveMatrix();
  static void restoreMatrix();
  static void identity();
  static void translate(GLfloat x, GLfloat y, GLfloat z);
  static void rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);

private:
  static std::stack<glm::mat4> matrixStack;
};
