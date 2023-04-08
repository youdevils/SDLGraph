#pragma once

// Standard C++
#include <iostream>
#include <memory>

// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Custom
#include "../include/Font.hpp"

struct MenuButton
{
    bool is_hovered = false;
    SDL_Rect m_background;
};

class Menu
{
private:
    SDL_Rect m_menu_background;
    std::shared_ptr<Font> m_menu_font = nullptr;

    MenuButton m_scale_plus;
    MenuButton m_scale_minus;
    MenuButton m_size_plus;
    MenuButton m_size_minus;
    MenuButton m_refresh;
    MenuButton m_show_points;

    const SDL_Color m_BACKGROUND_COLOR = {0, 0, 255};
    const SDL_Color m_HOVER_COLOR = {100, 200, 255};

public:
    Menu(int xx, int yy, int ww, int hh, std::shared_ptr<Font> font);
    ~Menu();
    void Render(SDL_Renderer *renderer);
    void Hovering(int x, int y);
    int Clicked(int x, int y);
    void SetWindowSize(int w, int h);
};
