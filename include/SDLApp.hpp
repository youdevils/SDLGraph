#pragma once

// Standard C++
#include <functional>

// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Custom
#include "../include/FramerateManager.hpp"

class SDLApp
{
private:
    int m_mousePositionX;
    int m_mousePositionY;
    bool m_isRunning;
    SDL_Renderer *m_renderer = nullptr;
    SDL_Window *m_window = nullptr;
    std::function<void(void)> m_EventCallback;
    std::function<void(void)> m_UpdateCallback;
    std::function<void(void)> m_RenderCallback;
    int m_windowWidth;
    int m_windowHeight;

public:
    SDLApp(const char *title, int windowwidth, int windowheight);
    ~SDLApp();
    SDL_Renderer *GetRenderer() const;
    int GetWindowWidth();
    int GetWindowHeight();
    int *GetMouseX();
    int *GetMouseY();
    void RunApp();
    void SetRunning(bool isRunning);
    void SetEventCallback(std::function<void(void)> func);
    void SetUpdateCallback(std::function<void(void)> func);
    void SetRenderCallback(std::function<void(void)> func);
    FramerateManager &GetFrameManager();
};
