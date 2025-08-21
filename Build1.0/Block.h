#pragma once
#include <SDL3/SDL.h>
class Block
{
public:
	Block();
	~Block();
	Block(int x, int y, int a, int b);

	SDL_FRect getRect();
private:
	SDL_FRect border;

};

