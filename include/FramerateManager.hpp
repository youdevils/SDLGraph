#pragma once

// Standard C++
#include <iostream>

// SDL
#include <SDL2/SDL.h>

class FramerateManager
{
private:
    FramerateManager(/* args */);
    ~FramerateManager();
    Uint32 m_startTick = -1;
    Uint32 m_endTick = -1;
    bool m_rateIsLimited = true;
    float m_FPS = 60.0f;
    float m_FrameRate = 1000.0f / m_FPS;

public:
    static FramerateManager &GetInstance();
    void SetStartTick();
    void LimitFramerate();
    void SetRateLimit(bool isLimited);
    void SetFPS(float fps);
    float GetFPS();
    float GetDelta();
    float GetStart();
};
