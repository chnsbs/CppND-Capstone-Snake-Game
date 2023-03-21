#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "player.h"

void Controller::ChangeDirection(Player &player, Player::Direction input) const {
  //if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Player &player) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(player, Player::Direction::kUp);
          break;

        case SDLK_DOWN:
          ChangeDirection(player, Player::Direction::kDown);
          break;

        case SDLK_LEFT:
          ChangeDirection(player, Player::Direction::kLeft);
          break;

        case SDLK_RIGHT:
          ChangeDirection(player, Player::Direction::kRight);
          break;
      }
    }
  }
}