#include "player.h"
#include "SDL.h"


Player::Player(const int x, const int y) : x(x), y(y) {}

void Player::SetX(int x) {
  this->x = x;
}

void Player::SetY(int y) {
  this->y = y;
}

void Player::SetDirection(const Direction direction){
  this->direction = direction;
}

void Player::SetGameField(int min_x, int max_x, int min_y, int max_y){
  gamefield_.min_x = min_x;
  gamefield_.max_x = max_x;
  gamefield_.min_y = min_y;
  gamefield_.max_y = max_y;

}


bool Player::isPLayerInGameField(){
  int x_virt = this->GetX();
  int y_virt = this->GetY();

  switch (direction) {
        case Direction::kUp:
          y_virt -= speed;
          break;

        case Direction::kDown:
          y_virt += speed;
          break;

        case Direction::kLeft:
          x_virt -= speed;
          break;

        case Direction::kRight:
          x_virt += speed;
          break;
        default:
          break;
      }


  if (x_virt > gamefield_.min_x && x_virt < gamefield_.max_x &&  y_virt > gamefield_.min_y && y_virt < gamefield_.max_y) {
    return true;}
    else{
      return false;
      }
  

}

void Player::Update() {
  
  if (this->isPLayerInGameField()){
    SDL_Point start_point_ = {x,y};
    switch (direction) {
      case Direction::kUp:
        y -= speed;
        break;

      case Direction::kDown:
        y += speed;
        break;

      case Direction::kLeft:
        x -= speed;
        break;

      case Direction::kRight:
        x += speed;
        break;
      default:
        break;
    }
    SDL_Point end_point_ = {x,y};
    _footPrintLineSegments.push_back(std::make_pair(start_point_, end_point_));
  }

}

int Player::GetX() const {
  return x;
}

int Player::GetY() const {
  return y;
}

int Player::GetRadius() const {
  return radius;
}

SDL_Color Player::GetColor() const {
  return color;
}

Player::Direction Player::GetDirection() const{
  return this->direction;
} 

 std::vector<std::pair<SDL_Point, SDL_Point>> Player::GetfootPrintLineSegments() const{
  return this->_footPrintLineSegments;
} 