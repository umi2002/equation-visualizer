#include "../include/matrix_transformations.hpp"
#include <glm/gtc/matrix_transform.hpp>

void Transform::saveMatrix() { matrixStack.push(matrixStack.top()); }

void Transform::restoreMatrix() { matrixStack.pop(); }

void Transform::identity() { matrixStack.top() = glm::mat4(1.0f); }

void Transform::translate(GLfloat x, GLfloat y, GLfloat z) {
  matrixStack.top() = glm::translate(matrixStack.top(), glm::vec3(x, y, z));
}

void Transform::rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
  matrixStack.top() =
      glm::rotate(matrixStack.top(), glm::radians(angle), glm::vec3(x, y, z));
}

std::stack<glm::mat4> Transform::matrixStack({glm::mat4(1.0f)});
