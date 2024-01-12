#pragma once

class KeyStates {
public:
  static bool keyStates[256];
};

class KeyboardHandler {
public:
  static void onKeyDown(unsigned char key, int x, int y);
  static void onKeyUp(unsigned char key, int x, int y);
  
  static void reset();
  static void rotate();
  static void translate();
};
