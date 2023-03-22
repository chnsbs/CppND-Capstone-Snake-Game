#ifndef PLAYER_H
#define PLAYER_H

#include "SDL.h"
#include <vector>

class Player {
public:
  enum class Direction { kUp, kDown, kLeft, kRight, kStop};
   struct GameField
  {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
  };
  // Constructor
  Player(const int x, const int y);

  // Set player position
  void SetX(int x);
  void SetY(int y);
  void SetDirection(const Direction direction);
  void SetGameField(int min_x, int max_x, int min_y, int max_y);

  // Update player
  void Update();

  // Get player position
  int GetX() const;
  int GetY() const;
  int GetRadius() const;
  SDL_Color GetColor() const;
  
  Direction GetDirection() const;


  bool alive{true};

private:
  int x;
  int y;
  int radius = 10;
  int speed = 1;
  GameField gamefield_;
  Direction direction = Direction::kStop;
  bool isPLayerInGameField(); 
  SDL_Color color = {255, 0, 0, 255};
  
;
};

#endif