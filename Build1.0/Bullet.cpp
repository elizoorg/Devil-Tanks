#include "Bullet.h"
#include <SDL_image.h>

Bullet::Bullet()
{

}



Bullet::~Bullet()
{
	SDL_DestroyTexture(text1);
}

void Bullet::setTexture(SDL_Renderer* render)
{
	SDL_Surface* test1 = IMG_Load("bull.png");
	if (!test1) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "bull.png", IMG_GetError());
	}
	text1 = SDL_CreateTextureFromSurface(render, test1);
	if (!text1) {
		printf("Unable to create texture from %s! SDL Error: %s\n", "bull.png", SDL_GetError());
	}
	SDL_FreeSurface(test1);
	pos.w = 30;
	pos.h = 30;
}

void Bullet::setPos(vec2i pos)
{
	posit = pos;
}

void Bullet::setVel(vec2f vel)
{
	velos = vel;
}

void Bullet::Coll(int x)
{
	posit.x = (float)posit.x - (float)velos.x * velocity;
	posit.y = (float)posit.y - (float)velos.y * velocity;
	if(x==1) velos.y *= -1;
	if(x==2) velos.x *= -1;
	coll++;
	

}

void Bullet::Move()
{
	posit.x = (float)posit.x+ (float)velos.x*velocity;
	posit.y = (float)posit.y + (float)velos.y * velocity;
}

void Bullet::Draw(SDL_Renderer* render)
{
	pos.x = posit.x;
	pos.y = posit.y;
	pos.w = 20;
	pos.h = 20;
	SDL_RenderCopy(render, text1,0,&pos);
}
