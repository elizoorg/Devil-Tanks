#pragma once
#include <SDL.h>
#include <map>
using namespace std;



class Controller
{
public:
	Controller();
	~Controller();
	void Init(SDL_GameController* controller);
	short getButton(short key) {  return Button[key];  }
	short getAxis(short axis) {  return Axis[axis];}
private:
	map<short, short> Button;
	map<short, short> Axis;
};
