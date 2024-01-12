#include "../include/keyboard.hpp"
#include <GL/gl.h>

bool KeyStates::keyStates[256] = {false};

void KeyboardHandler::onKeyDown(unsigned char key, int x, int y) {
  KeyStates::keyStates[key] = true;
}

void KeyboardHandler::onKeyUp(unsigned char key, int x, int y) {
  KeyStates::keyStates[key] = false;
}

void KeyboardHandler::reset() {
  if (KeyStates::keyStates[' ']) {
    glLoadIdentity();
  }
}

void KeyboardHandler::rotate() {
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

void KeyboardHandler::translate() {
  if (KeyStates::keyStates['L']) {
    glTranslatef(0.1f, 0.0f, 0.0f);
  }

  if (KeyStates::keyStates['H']) {
    glTranslatef(-0.1f, 0.0f, 0.0f);
  }

  if (KeyStates::keyStates['K']) {
    glTranslatef(0.0f, 0.1f, 0.0f);
  }

  if (KeyStates::keyStates['J']) {
    glTranslatef(0.0f, -0.1f, 0.0f);
  }
}
