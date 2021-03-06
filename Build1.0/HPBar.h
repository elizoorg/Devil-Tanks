#pragma once
#include <SDL.h>
struct mColor {
	short r;
	short g;
	short b;
};


class HPBar
{
public:
	HPBar();
	HPBar(int x, int y, int a, int b) { border = SDL_Rect{ x,y,a,b }; }
	~HPBar();
	void Draw(SDL_Renderer* render);
	void setColor(int r, int g, int b, int r1, int g1, int b1) {
		cBar.r=r; cBar.g = g; cBar.b = b; cBorder.r = r1; cBorder.g = g1; cBorder.b = b1;
	}

	void setHP(int z) { mHP = z; }
private:
	mColor cBorder;
	mColor cBar;
	SDL_Rect border;
	int mHP;
};

