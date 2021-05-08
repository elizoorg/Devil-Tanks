#include "Contoller.h"

Controller::Controller() {

}

Controller::~Controller()
{
}

void Controller::Init(SDL_GameController* controller)
{
	Button[SDL_CONTROLLER_BUTTON_A]= SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_A).value.button;
	Button[SDL_CONTROLLER_BUTTON_B] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_B).value.button;
	Button[SDL_CONTROLLER_BUTTON_X] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_X).value.button;
	Button[SDL_CONTROLLER_BUTTON_Y] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_X).value.button; 
	Button[SDL_CONTROLLER_BUTTON_BACK] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_BACK).value.button;
	Button[SDL_CONTROLLER_BUTTON_GUIDE] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_GUIDE).value.button;
	Button[SDL_CONTROLLER_BUTTON_START] =SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_START).value.button;
	Button[SDL_CONTROLLER_BUTTON_LEFTSTICK] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_LEFTSTICK).value.button;
	Button[SDL_CONTROLLER_BUTTON_RIGHTSTICK] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_RIGHTSTICK).value.button;
	Button[SDL_CONTROLLER_BUTTON_LEFTSHOULDER] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER).value.button;
	Button[SDL_CONTROLLER_BUTTON_RIGHTSHOULDER] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER).value.button;
	Button[SDL_CONTROLLER_BUTTON_DPAD_UP] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP).value.button;
	Button[SDL_CONTROLLER_BUTTON_DPAD_DOWN] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN).value.button;
	Button[SDL_CONTROLLER_BUTTON_DPAD_LEFT] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT).value.button;
	Button[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] = SDL_GameControllerGetBindForButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT).value.button;
	Axis[SDL_CONTROLLER_AXIS_LEFTX] = SDL_GameControllerGetBindForAxis(controller, SDL_CONTROLLER_AXIS_LEFTX).value.axis;
	Axis[SDL_CONTROLLER_AXIS_LEFTY] = SDL_GameControllerGetBindForAxis(controller, SDL_CONTROLLER_AXIS_LEFTY).value.axis;
	Axis[SDL_CONTROLLER_AXIS_RIGHTX] = SDL_GameControllerGetBindForAxis(controller, SDL_CONTROLLER_AXIS_RIGHTX).value.axis;
	Axis[SDL_CONTROLLER_AXIS_RIGHTY] = SDL_GameControllerGetBindForAxis(controller, SDL_CONTROLLER_AXIS_RIGHTY).value.axis;
}


Controller cplayer1;
Controller cplayer2;
