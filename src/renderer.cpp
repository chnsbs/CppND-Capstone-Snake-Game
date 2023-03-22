#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t kPlayfieldWidth, 
                   const std::size_t kPlayfieldHeight)
    : screen_width(screen_width),
      screen_height(screen_height),
      kPlayfieldWidth(kPlayfieldWidth),
      kPlayfieldHeight(kPlayfieldHeight){
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Qix CHN", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }


}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(const Player& player, const std::vector<std::pair<SDL_Point, SDL_Point>>& lines) {

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render Lines
  SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
  for(const auto& line : lines){
    SDL_RenderDrawLine(sdl_renderer, line.first.x, line.first.y, line.second.x, line.second.y);
  }

  // Render player body
  DrawCircle(player.GetX(), player.GetY(), player.GetRadius(), {255, 0, 0, 255});

  // Render player footprint
    SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 0, 255);
    for (const auto& segment : player.GetfootPrintLineSegments()) {
        SDL_RenderDrawLine(sdl_renderer, segment.first.x, segment.first.y, segment.second.x, segment.second.y);
    }
  
  // Render drawed 



  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::DrawCircle(int x, int y, int radius, SDL_Color color) {
  SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
  for (int w = 0; w < radius * 2; w++) {
    for (int h = 0; h < radius * 2; h++) {
      int dx = radius - w;
      int dy = radius - h;
      if ((dx * dx + dy * dy) <= (radius * radius)) {
        SDL_RenderDrawPoint(sdl_renderer, x + dx, y + dy);
      }
    }
  }
}


void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
