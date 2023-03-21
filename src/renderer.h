#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "player.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height, const std::size_t kPlayfieldWidth, const std::size_t kPlayfieldHeight);
  ~Renderer();

  void Render(Player const player);
  void UpdateWindowTitle(int score, int fps);
  void DrawCircle(int x, int y, int radius, SDL_Color color);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t kPlayfieldWidth;
  const std::size_t kPlayfieldHeight;
};

#endif