#include "Contoller.h"
#include <iostream>

Controller::Controller() {

}

Controller::~Controller()
{
}

void Controller::Init(SDL_Gamepad* controller)
{
    int num_bindings;
    SDL_GamepadBinding** bindings = SDL_GetGamepadBindings(controller, &num_bindings);
    if (bindings && num_bindings > 0) {
        // Для кнопок
        for (int i = 0; i < num_bindings; i++) {
            if (bindings[i] && bindings[i]->input_type == SDL_GAMEPAD_BINDTYPE_BUTTON) {
                switch (bindings[i]->output.button) {
                case SDL_GAMEPAD_BUTTON_SOUTH:
                    Button[SDL_GAMEPAD_BUTTON_SOUTH] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_EAST:
                    Button[SDL_GAMEPAD_BUTTON_EAST] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_WEST:
                    Button[SDL_GAMEPAD_BUTTON_WEST] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_NORTH:
                    Button[SDL_GAMEPAD_BUTTON_NORTH] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_BACK:
                    Button[SDL_GAMEPAD_BUTTON_BACK] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_GUIDE:
                    Button[SDL_GAMEPAD_BUTTON_GUIDE] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_START:
                    Button[SDL_GAMEPAD_BUTTON_START] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_LEFT_STICK:
                    Button[SDL_GAMEPAD_BUTTON_LEFT_STICK] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_RIGHT_STICK:
                    Button[SDL_GAMEPAD_BUTTON_RIGHT_STICK] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_LEFT_SHOULDER:
                    Button[SDL_GAMEPAD_BUTTON_LEFT_SHOULDER] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER:
                    Button[SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_DPAD_UP:
                    Button[SDL_GAMEPAD_BUTTON_DPAD_UP] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_DPAD_DOWN:
                    Button[SDL_GAMEPAD_BUTTON_DPAD_DOWN] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_DPAD_LEFT:
                    Button[SDL_GAMEPAD_BUTTON_DPAD_LEFT] = bindings[i]->input.button;
                    break;
                case SDL_GAMEPAD_BUTTON_DPAD_RIGHT:
                    Button[SDL_GAMEPAD_BUTTON_DPAD_RIGHT] = bindings[i]->input.button;
                    break;
                }
            }
            // Для осей
            else if (bindings[i] && bindings[i]->input_type == SDL_GAMEPAD_BINDTYPE_AXIS) {
                switch (bindings[i]->input.axis.axis) {
                case SDL_GAMEPAD_AXIS_LEFTX:
                    Axis[SDL_GAMEPAD_AXIS_LEFTX] = bindings[i]->input.axis.axis;
                    break;
                case SDL_GAMEPAD_AXIS_LEFTY:
                    Axis[SDL_GAMEPAD_AXIS_LEFTY] = bindings[i]->input.axis.axis;
                    break;
                case SDL_GAMEPAD_AXIS_RIGHTX:
                    Axis[SDL_GAMEPAD_AXIS_RIGHTX] = bindings[i]->input.axis.axis;
                    break;
                case SDL_GAMEPAD_AXIS_RIGHTY:
                    Axis[SDL_GAMEPAD_AXIS_RIGHTY] = bindings[i]->input.axis.axis;
                    break;
                }
            }
        }

        // Освобождаем память
        
        SDL_free(bindings);
    }
}


Controller cplayer1;
Controller cplayer2;
