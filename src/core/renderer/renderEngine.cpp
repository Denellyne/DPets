#include "renderEngine.h"
#include <fstream>

#define FPS 60

renderEngine::renderEngine() {

  SetTraceLogLevel(6);
  SetConfigFlags(
      FLAG_WINDOW_TRANSPARENT); // Configures window to be transparent
  InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "Desktop Pets");
  SetWindowPosition(0, -20);
  SetWindowState(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_MOUSE_PASSTHROUGH |
                 FLAG_WINDOW_TOPMOST); // Hide border/titlebar; omit

  SetTargetFPS(FPS);
  
  Image image = LoadImage("Graphics/sprite.png");
  sprite = LoadTextureFromImage(image);
  UnloadImage(image);

  image = LoadImage("Graphics/DPets.png");
  SetWindowIcon(image);
  UnloadImage(image);

  windowWidth = GetMonitorWidth(0);
  windowHeight = GetMonitorHeight(0);

  spriteFrame.x = 0;
  spriteFrame.y = 0;
  spriteFrame.height = 32;
  spriteFrame.width = 32;

  int xOffset = 150, yOffset = 120;

  loadConfig(xOffset, yOffset);

  spriteFrameOutput.x = windowWidth - xOffset;
  spriteFrameOutput.y = windowHeight - yOffset;
  spriteFrameOutput.height = 128;
  spriteFrameOutput.width = 128;
}

renderEngine::~renderEngine() {
  UnloadTexture(sprite);
  CloseWindow();
}

void renderEngine::loadConfig(int &x, int &y) {
  std::ifstream config("config.txt");
  if (config.good()) {
    std::string offset;
    config >> offset;
    x = atoi(offset.c_str());
    config >> offset;
    y = atoi(offset.c_str());
  }
  config.close();
}

void renderEngine::nextFrame() {
  accumulator = (accumulator + 1) % (FPS >> 2);

  if (accumulator == 0) {
    frame = (frame+1) % 4;
    spriteFrame.x = 32.0f * frame;
  }
}

void renderEngine::render() {
  while (!WindowShouldClose()) {

    BeginDrawing();
    DrawTexturePro(sprite, spriteFrame, spriteFrameOutput, {0, 0}, 0.0f, WHITE);
    EndDrawing();

    ClearBackground(BLANK);

    nextFrame();
  }
}
