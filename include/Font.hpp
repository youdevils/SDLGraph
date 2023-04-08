#pragma once

// Standard C++
#include <iostream>
#include <string>

// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Font
{
    private:
        SDL_Surface* m_surface = nullptr;
        TTF_Font* m_font = nullptr;
        SDL_Texture* m_texture = nullptr;
        SDL_Renderer* m_renderer = nullptr;
        std::string m_filename;
        SDL_Rect m_rectangle;

    public:
        Font(TTF_Font* font);
        ~Font();
        void SetText(SDL_Renderer* renderer, std::string text, SDL_Color color);
        void SetPosition(int x, int y);
        int GetX();
        int GetY();
        void SetWidthHeight(int w, int h);
        int GetWidth();
        int GetHeight();
        void Render();
};

