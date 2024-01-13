#include "../include/keyboard.hpp"
#include "../include/matrix_transformations.hpp"

bool KeyStates::keyStates[256] = {false};

void KeyboardHandler::onKeyDown(unsigned char key, int x, int y) {
  KeyStates::keyStates[key] = true;
}

void KeyboardHandler::onKeyUp(unsigned char key, int x, int y) {
  KeyStates::keyStates[key] = false;
}

void KeyboardHandler::reset() {
  if (KeyStates::keyStates[' ']) {
    Transform::identity();
  }
}

void KeyboardHandler::rotate() {
  if (KeyStates::keyStates['l']) {
    Transform::rotate(3.0f, 0.0f, 1.0f, 0.0f);
  }

  if (KeyStates::keyStates['h']) {
    Transform::rotate(-3.0f, 0.0f, 1.0f, 0.0f);
  }

  if (KeyStates::keyStates['k']) {
    Transform::rotate(3.0f, 1.0f, 0.0f, 0.0f);
  }

  if (KeyStates::keyStates['j']) {
    Transform::rotate(-3.0f, 1.0f, 0.0f, 0.0f);
  }
}

void KeyboardHandler::translate() {
  if (KeyStates::keyStates['L']) {
      Transform::translate(0.1f, 0.0f, 0.0f);
  }

  if (KeyStates::keyStates['H']) {
      Transform::translate(-0.1f, 0.0f, 0.0f);
  }

  if (KeyStates::keyStates['K']) {
      Transform::translate(0.0f, 0.1f, 0.0f);
  }

  if (KeyStates::keyStates['J']) {
      Transform::translate(0.0f, -0.1f, 0.0f);
  }
}
