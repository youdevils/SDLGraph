#include "../include/FramerateManager.hpp"

FramerateManager::FramerateManager()
{
}

FramerateManager::~FramerateManager()
{
}

FramerateManager &FramerateManager::GetInstance()
{
    static FramerateManager *s_instance = new FramerateManager;
    return *s_instance;
}

void FramerateManager::SetStartTick()
{
    m_startTick = SDL_GetTicks();
}

void FramerateManager::LimitFramerate()
{
    // Cap to 60 FPS
    if (m_rateIsLimited)
    {
        if (GetDelta() < m_FrameRate)
        {
            SDL_Delay(m_FrameRate - GetDelta());
        }
    }
}

float FramerateManager::GetDelta()
{
    return (float(SDL_GetTicks()) - m_startTick);
}

float FramerateManager::GetStart()
{
    return float(SDL_GetTicks());
}

void FramerateManager::SetRateLimit(bool isLimited)
{
    if (m_rateIsLimited == true)
    {
        m_rateIsLimited = false;
    }
    else
    {
        m_rateIsLimited = true;
    }
}

void FramerateManager::SetFPS(float fps)
{
    // 1000 milliseconds = 1 second
    m_FrameRate = 1000.0f / fps;
}

float FramerateManager::GetFPS()
{
    return m_FPS;
}