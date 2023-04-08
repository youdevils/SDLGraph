/*
    Manages all the following resources:
    - Fonts
    - Sprite
    - Animated Sprite
    - Background
    - Player

    Is a singleton class.
*/

#pragma once

// Standard C++
#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>

// SDL
#include <SDL2/SDL.h>

// Custom
#include "../include/Font.hpp"
#include "../include/Point.hpp"
#include "../include/Menu.hpp"
#include "../include/SDLResourceManager.hpp"

class ResourceFactory
{

private:
    ResourceFactory();
    ~ResourceFactory();

    std::unordered_map<const char *, std::shared_ptr<Font>> m_fonts;
    std::vector<std::shared_ptr<Point>> m_points;
    std::shared_ptr<Menu> m_menu = nullptr;

public:
    static ResourceFactory &GetInstance();

    std::shared_ptr<Menu> CreateMenu(int xx, int yy, int ww, int hh, std::shared_ptr<Font> font);
    std::shared_ptr<Menu> GetMenu();

    std::shared_ptr<Font> CreateFont(const char *name, const char *path, int size);
    std::shared_ptr<Font> GetFont(const char *name);

    void AddPoint(const char *name, const float x, const float y);
    std::vector<std::shared_ptr<Point>> &GetPoints();
    void ClearPoints();
};