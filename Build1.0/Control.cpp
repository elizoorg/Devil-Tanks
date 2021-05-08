#include "Control.h"
#include <iostream>
using namespace std;
EventHandler* EventHandler::sInstance = NULL;
const int JOYSTICK_DEAD_ZONE = 8000;
EventHandler* EventHandler::Instance()
{
	if (!sInstance)
		sInstance = new EventHandler();
	return sInstance;
}

EventHandler::EventHandler()
{
	delete sInstance;
	sInstance = NULL;
}
void EventHandler::Handle(SDL_Event* Event) {
	switch (Event->type) {
	case SDL_KEYDOWN: {
		OnKeyDown(Event->key.keysym.sym, Event->key.keysym.mod);
		break;
	}
	case SDL_KEYUP: {
		OnKeyUp(Event->key.keysym.sym, Event->key.keysym.mod);
		break;
	}

	case SDL_MOUSEMOTION: {
		OnMouseMove(Event->motion.x, Event->motion.y,
			Event->motion.xrel, Event->motion.yrel,
			(Event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
			(Event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
			(Event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
		break;
	}

	case SDL_MOUSEBUTTONDOWN: {
		switch (Event->button.button) {
		case SDL_BUTTON_LEFT: {
			OnLButtonDown(Event->button.x, Event->button.y);
			break;
		}
		case SDL_BUTTON_RIGHT: {
			OnRButtonDown(Event->button.x, Event->button.y);
			break;
		}
		case SDL_BUTTON_MIDDLE: {
			OnMButtonDown(Event->button.x, Event->button.y);
			break;
		}
		}
		break;
	}

	case SDL_MOUSEBUTTONUP: {
		switch (Event->button.button) {
		case SDL_BUTTON_LEFT: {
			OnLButtonUp(Event->button.x, Event->button.y);
			break;
		}
		case SDL_BUTTON_RIGHT: {
			OnRButtonUp(Event->button.x, Event->button.y);
			break;
		}
		case SDL_BUTTON_MIDDLE: {
			OnMButtonUp(Event->button.x, Event->button.y);
			break;
		}
		}
		break;
	}
	case SDL_MOUSEWHEEL: {
		OnMouseWheel(Event->wheel.y);
		break;
	}
	case SDL_JOYAXISMOTION: {
		OnJoyAxis(Event->jaxis.which, Event->jaxis.axis, Event->jaxis.value);
		break;
	}
	case SDL_JOYHATMOTION: {
		OnJoyHat(Event->jhat.which, Event->jhat.hat, Event->jhat.value);
		break;
	}
	case SDL_JOYBUTTONDOWN: {
		OnJoyButtonDown(Event->jbutton.which, Event->jbutton.button);
		break;
	}
	case SDL_JOYBUTTONUP: {
		OnJoyButtonUp(Event->jbutton.which, Event->jbutton.button);
		break;
	}
	case SDL_QUIT: {
		break;
	}
	}
}

void EventHandler::OnKeyDown(SDL_Keycode sym, Uint16 mod){keys_down[sym] = true;}
void EventHandler::OnKeyUp(SDL_Keycode sym, Uint16 mod){keys_down[sym] = false;}
void EventHandler::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle){MousePos.x = mX; MousePos.y = mY;}
void EventHandler::OnMouseWheel(int shift) { shift = shift; }
void EventHandler::OnLButtonDown(int mX, int mY) { mouse_down[SDL_BUTTON_LEFT] = true; setMousePos(mX, mY); }
void EventHandler::OnLButtonUp(int mX, int mY) { mouse_down[SDL_BUTTON_LEFT] = false; setMousePos(mX, mY); }
void EventHandler::OnRButtonDown(int mX, int mY) { mouse_down[SDL_BUTTON_RIGHT] = true; setMousePos(mX, mY); }
void EventHandler::OnRButtonUp(int mX, int mY) { mouse_down[SDL_BUTTON_RIGHT] = false; setMousePos(mX, mY); }
void EventHandler::OnMButtonDown(int mX, int mY) { mouse_down[SDL_BUTTON_MIDDLE] = true; setMousePos(mX, mY); }
void EventHandler::OnMButtonUp(int mX, int mY) { mouse_down[SDL_BUTTON_MIDDLE] = false; setMousePos(mX, mY); }
void EventHandler::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{
	switch (which) {
	case 0:
			if(axis==LX11)Stick1Pos.x = value; 
			if(axis==LY11)Stick1Pos.y = value; 
			if (axis == LX12)Stick2Pos.x = value;
			if (axis == LY12)Stick2Pos.y = value; 
			break;
	case 1:
				if (axis == LX21)Stick21Pos.x = value; 
				if (axis == LY21)Stick21Pos.y = value; 
				if (axis == LX22)Stick22Pos.x = value; 
				if (axis == LY22)Stick22Pos.y = value; 
		break;
	}
}

void EventHandler::OnJoyButtonDown(Uint8 which, Uint8 button) {
	if (!which) button_down[button] = true; else  button2_down[button] = true;
}
void EventHandler::OnJoyButtonUp(Uint8 which, Uint8 button) { if (!which) button_down[button] = false; else button2_down[button] = false; }
void EventHandler::OnJoyHat(Uint8 which, Uint8 hat, Uint8 value) { cout << (int)  value << endl; }
bool EventHandler::KeyDown(SDL_Keycode keycode) { return keys_down[keycode]; }
vec2i EventHandler::GetMousePos(){return MousePos;}
bool EventHandler::MouseDown(Uint8 mouse){return mouse_down[mouse];}
bool EventHandler::ButtonDown(Uint8 button) { return button_down[button]; }
bool EventHandler::Button2ndDown(Uint8 button){return button2_down[button];}
vec2i EventHandler::GetStick1Pos(){return Stick1Pos;}
vec2i EventHandler::GetStick2Pos() { return Stick2Pos; }
vec2i EventHandler::GetStick21Pos() { return Stick21Pos; }
vec2i EventHandler::GetStick22Pos() { return Stick22Pos; }
vec2i EventHandler::Get1stTriggerPos() { return Trigger1; }
vec2i EventHandler::Get2ndTriggerPos() { return Trigger2; }
short EventHandler::getMouseShift(){return shift;}
void EventHandler::setMapping()
{
	LX11 = cplayer1.getAxis(SDL_CONTROLLER_AXIS_LEFTX);
	LY11 = cplayer1.getAxis(SDL_CONTROLLER_AXIS_LEFTY);
	LX12 = cplayer1.getAxis(SDL_CONTROLLER_AXIS_RIGHTX);
	LY12 = cplayer1.getAxis(SDL_CONTROLLER_AXIS_RIGHTY);
	LX21 = cplayer2.getAxis(SDL_CONTROLLER_AXIS_LEFTX);
	LY21 = cplayer2.getAxis(SDL_CONTROLLER_AXIS_LEFTY);
	LX22 = cplayer2.getAxis(SDL_CONTROLLER_AXIS_RIGHTX);
	LY22 = cplayer2.getAxis(SDL_CONTROLLER_AXIS_RIGHTY);
}
inline void EventHandler::setMousePos(Uint8 x, Uint8 y){MousePos.x = x; MousePos.y = y;}
