#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kPlayfieldWidth{600};
  constexpr std::size_t kPlayfieldHeight{600};

  Renderer renderer(kScreenWidth, kScreenHeight, kPlayfieldWidth, kPlayfieldHeight);
  Controller controller;
  Game game(kScreenWidth, kScreenHeight, kPlayfieldWidth, kPlayfieldHeight );
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  return 0;
}