#pragma once
#include <SDL_rect.h>
class Block
{
public:
	Block();
	~Block();
	Block(int x, int y, int a, int b);

	SDL_Rect getRect();
private:
	SDL_Rect border;

};

