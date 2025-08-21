#pragma once
#include <SDL3/SDL.h>
#include <unordered_map>
#include "Vector.h"
#include "Contoller.h"
extern Controller cplayer1, cplayer2;
class EventHandler
{
public:
	static EventHandler* Instance();
	EventHandler();
	void Handle(SDL_Event* Event);
	void OnKeyDown(SDL_Keycode sym, Uint16 mod);
	void OnKeyUp(SDL_Keycode sym, Uint16 mod);
	void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
	void OnMouseWheel(int shift);
	void OnLButtonDown(int mX, int mY);
	void OnLButtonUp(int mX, int mY);
	void OnRButtonDown(int mX, int mY);
	void OnRButtonUp(int mX, int mY);
	void OnMButtonDown(int mX, int mY);
	void OnMButtonUp(int mX, int mY);
	void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
	void OnJoyButtonDown(Uint8 which, Uint8 button);
	void OnJoyButtonUp(Uint8 which, Uint8 button);
	void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);
	bool KeyDown(SDL_Keycode keycode);
	vec2i GetMousePos();
	void setMousePos(Uint8 x,Uint8 y);
	bool MouseDown(Uint8 mouse);
	bool ButtonDown(Uint8 button);
	bool Button2ndDown(Uint8 button);
	bool HatDown(Uint8 button);
	vec2i GetStick1Pos();
	vec2i GetStick2Pos();
	vec2i GetStick21Pos();
	vec2i GetStick22Pos();
	vec2i Get1stTriggerPos();
	vec2i Get2ndTriggerPos();
	short getMouseShift();
	void setMapping();
private:
	static EventHandler* sInstance;
	std::unordered_map<uint16_t, bool> keys_down;
	short shift;
	short LX11=0, LY11=0, LX12=0, LY12=0;
	short LX21=0, LY21=0, LX22=0, LY22=0;
	vec2i MousePos;
	vec2i Stick1Pos;
	vec2i Stick2Pos;
	vec2i Stick21Pos;
	vec2i Stick22Pos;
	vec2i Trigger1, Trigger2;
	std::unordered_map<uint8_t, bool> mouse_down;
	std::unordered_map<uint8_t, bool> button_down;
	std::unordered_map<uint8_t, bool> button2_down;
	std::unordered_map<uint8_t, bool> hat_down;
};
