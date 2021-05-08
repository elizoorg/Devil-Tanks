#include "Block.h"

Block::Block()
{
}

Block::~Block()
{
}

Block::Block(int x, int y, int a, int b)
{
	border.x = x;
	border.y = y;
	border.w = a;
	border.h = b;
}

SDL_Rect Block::getRect()
{
	return border;
}
