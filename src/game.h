#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <utility>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"


class Game {
 public:
  Game(const std::size_t screen_width, const std::size_t screen_height, const std::size_t kPlayfieldWidth, const std::size_t kPlayfieldHeight);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

 private:
  Player player;
  std::vector<std::pair<SDL_Point, SDL_Point>> lines;


  std::random_device dev;
  std::mt19937 engine;

  int score{0};
  void Update();

};

#endif