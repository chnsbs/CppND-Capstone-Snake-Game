#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(const std::size_t screen_width, const std::size_t screen_height, const std::size_t kPlayfieldWidth, const std::size_t kPlayfieldHeight)
    : player(0, 0),
      engine(dev()) {
        int padding = (int(screen_width) - int(kPlayfieldWidth))/2;
        SDL_Point startPoint1 = {0 + padding, 0 + padding};
        SDL_Point startPoint2 = {startPoint1.x + int(kPlayfieldWidth), startPoint1.y };
        SDL_Point startPoint3 = {startPoint1.x + int(kPlayfieldWidth), startPoint1.y + int(kPlayfieldHeight)};
        SDL_Point startPoint4 = {0 + padding, startPoint1.y + int(kPlayfieldHeight)};

        // Add game field edges
        lines_.push_back({startPoint1,startPoint2});
        lines_.push_back({startPoint2,startPoint3});
        lines_.push_back({startPoint3,startPoint4});
        lines_.push_back({startPoint4,startPoint1});

        // Setup the Player Correctly
        player.SetX((startPoint3.x - startPoint4.x)/2);
        player.SetY(startPoint3.y);
        player.SetGameField(padding, padding + int(kPlayfieldWidth),padding, padding + int(kPlayfieldHeight) );


}



void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, player);
    Update();
    renderer.Render(player, lines_);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}




void Game::Update() {
  if (!player.alive) return;
  
  player.Update();
  
  

}

int Game::GetScore() const { return score; }
