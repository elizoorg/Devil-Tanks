#include "HPBar.h"
#include <iostream>

using namespace std;
HPBar::HPBar()
{
}

HPBar::~HPBar()
{
}

void HPBar::Draw(SDL_Renderer* render)
{
	SDL_SetRenderDrawColor(render, cBar.r, cBar.g, cBar.b, 0);
	SDL_Rect b1;
	b1.x = border.x;
	b1.y = border.y;
	b1.w = border.w * ((float)mHP / 1000);
	b1.h = border.h;
	SDL_RenderFillRect(render, &b1);
	SDL_SetRenderDrawColor(render, cBorder.r, cBorder.g, cBorder.b, 0);
	SDL_RenderDrawRect(render, &border);
}
