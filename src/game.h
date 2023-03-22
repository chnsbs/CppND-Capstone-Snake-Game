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
   struct GameField
  {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
  };

  Game(const std::size_t screen_width, const std::size_t screen_height, const std::size_t kPlayfieldWidth, const std::size_t kPlayfieldHeight);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

 private:
  GameField gameField_;
  Player player;
  std::vector<std::pair<SDL_Point, SDL_Point>> border_lines_;


  std::random_device dev;
  std::mt19937 engine;

  int score{0};
  void Update();

};

#endif