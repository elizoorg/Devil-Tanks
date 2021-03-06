#pragma once
#include <SDL.h>
#include "Vector.h"
class Player
{
public:
	Player();
	~Player();
	Player(int x, int y, int a, int b);

	vec2i getPos();
	void setPos(int x,int y);
	SDL_Rect getRect() const;
	SDL_Rect& getRect() {
		return border;
	}
	void Move(int dd,int dy);
	void setHP(int x) {HP = x;}
	void Damage() { HP-=25; if (HP < 0) HP = 0; }
	bool isDead() { if (!HP) return true; else return false; }
	int getHP() { return HP; }
private:
	SDL_Rect border;
	int HP=1000;
};

