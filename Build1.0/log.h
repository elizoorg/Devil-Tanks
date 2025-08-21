#pragma once
#include <iostream>
#include <SDL3/SDL.h>
using namespace std;

ostream& operator<<(ostream& os, const SDL_Rect& rect) {
    os << rect.x << " " << rect.y << " " << rect.w << " " << rect.h << endl;
    return os;
}

ostream& operator<<(ostream& os, const SDL_FRect& rect) {
	os << rect.x << " " << rect.y << " " << rect.w << " " << rect.h << endl;
	return os;
}

bool check_collision(SDL_FRect A, SDL_FRect B)
{
    
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;
   
        if (bottomA <= topB)
        {
            return false;
        }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    return true;
}


int check_bcollision(SDL_FRect A, SDL_FRect B)
{

    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }   
    if (leftB < leftA || rightB > rightA) return 2;
    if (topB > topA || bottomB < bottomA) return 1;
}









