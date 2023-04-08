/*
    Manages all the following resources:
    - SDL Surfaces
    - TTF Fonts

    Is a singleton class.
*/

#pragma once

// Standard C++
#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class SDLResourceManager
{
private:
    SDLResourceManager(/* args */);
    ~SDLResourceManager();

    std::unordered_map<std::string, SDL_Surface *> m_surfaces;
    std::unordered_map<std::string, TTF_Font *> m_ttfs;

public:
    static SDLResourceManager &GetInstance();
    SDL_Surface *GetSurface(std::string location);
    TTF_Font *GetTTF(std::string location, int size);
};
