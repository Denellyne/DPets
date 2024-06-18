#pragma once
#include "raylib.h"

class renderEngine {

public:
  renderEngine();
  ~renderEngine();

  void render();

private:
  void loadConfig(int &x, int &y);

  void nextFrame();

  char frame = 0;
  char accumulator = 0;

  int windowWidth, windowHeight;

  Rectangle spriteFrame;
  Rectangle spriteFrameOutput;
  Texture2D sprite;
};
