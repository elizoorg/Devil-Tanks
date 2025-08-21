#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Control.h"
#include "Timer.h"
#include "Player.h"
#include "Block.h"
#include <iostream>
#include "Bullet.h"
#include <HPBar.h>
#include <Contoller.h>
#include <sstream>
using namespace std;
constexpr int width =1920, height =1080;
constexpr int FRAME_RATE = 60;
class MyGame
{
public: 
	MyGame();
	~MyGame();

	void Init();
	void Run();
	void Loop();
	void Update();
	void Render();
	void CheckControllers();
	bool MainMenu();
	void EndGame(int a);
	
private:

	
	vec2f aim;
	vec2f aimnorm;

	vec2f aim2;
	vec2f aimnorm2;

	vec2f dur;
	vec2f durnorm;

	vec2f dur2;
	vec2f durnorm2;

	SDL_FRect aimrect2;

	int d1;
	int d2;

	double ang1;
	double ang2;
	double ang3;
	double ang4;
	vector <Bullet*> bullets;
	vector <Bullet*> bullets2;
	HPBar bar{ 25, 25, 300, 50 };
	HPBar bar2{ 1595,25,300,50 };
	SDL_FRect plat;
	SDL_FRect aimrect;

	SDL_Window* window;
	SDL_Renderer* mRender;
	Bullet bull;
	SDL_Event event;
	EventHandler* handler;
	Timer* timer_;
	bool _end=true;
	Player* player;
	Player* player2;
	SDL_Texture* crosshair;
	vector <Block*> block;

	SDL_Texture* tank1;
	SDL_Texture* menu;
	SDL_Texture* tank2;
	SDL_Texture* dylo1;
	SDL_Texture* dylo2;
	SDL_Texture* pole;
	SDL_Texture* endGame;

	std::vector<SDL_Gamepad*> gamepads;

	SDL_Joystick* gGameController = NULL;
	SDL_Joystick* gGameController1 = NULL;
	SDL_Gamepad* controller = NULL;
	SDL_Gamepad* controller1 = NULL;


	bool isEndless = false;

};
