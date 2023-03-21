#include "player.h"

Player::Player(int x, int y) : x(x), y(y) {}

void Player::SetX(int x) {
  this->x = x;
}

void Player::SetY(int y) {
  this->y = y;
}

void Player::Update() {
  x += dx;
  y += dy;
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