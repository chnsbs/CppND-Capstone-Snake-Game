#ifndef PLAYER_H
#define PLAYER_H

#include "SDL.h"

class Player {
public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  // Constructor
  Player(int x, int y);

  // Set player position
  void SetX(int x);
  void SetY(int y);

  // Update player
  void Update();

  // Get player position
  int GetX() const;
  int GetY() const;
  int GetRadius() const;
  SDL_Color GetColor() const;
  bool alive{true};

private:
  int x;
  int y;
  int radius = 10;
  SDL_Color color = {255, 0, 0, 255};
;
};

#endif