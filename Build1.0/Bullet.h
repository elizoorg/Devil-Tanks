#pragma once
#include "vector.h"
#include <SDL3/SDL.h>

#define velocity 20 ;
class Bullet
{
public:
	Bullet();
	~Bullet();
	void setTexture(SDL_Renderer* render);
	void setPos(vec2i pos);
	void setVel(vec2f vel);
	void Coll(int x);
	bool isDead() { if (coll > 2) return true; else return false; }
	int getColl() { return coll; };
	void setAngle(int ang) { angle = ang; }
	vec2i getPos() { return posit; }
	SDL_FRect getRect(){ return pos; };
	void Move();
	void Draw(SDL_Renderer* render);
private:	
	vec2i posit;
	int coll;
	int angle;
	vec2f velos;
	SDL_FRect pos;
	SDL_Texture* text1;
};

