#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

Player::Player(int x, int y, int a, int b)
{
	border.x = x;
	border.y = y;
	border.w = a;
	border.h = b;
}

vec2i Player::getPos()
{
	return vec2i(border.x,border.y);
}

void Player::setPos(int x,int y)
{
	border.x = x;
	border.y = y;
}

SDL_Rect Player::getRect() const
{
	return border;
}

void Player::Move(int dd, int dy)
{
	border.x += dd;
	border.y += dy;
}
