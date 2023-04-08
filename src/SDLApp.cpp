#include "../include/SDLApp.hpp"

SDLApp::SDLApp(const char *title, int windowwidth, int windowheight)
{
    // ----- Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "SDL Initialisation Failure.\n");
    }

    if (TTF_Init() == -1)
    {
        fprintf(stderr, "Font Initialisation Failure.\n");
    }

    // ----- Create window
    m_window = SDL_CreateWindow(title,
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                windowwidth, windowheight,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    m_windowWidth = windowwidth;
    m_windowHeight = windowheight;

    if (!m_window)
    {
        fprintf(stderr, "Error creating window.\n");
    }

    // ----- Renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    FramerateManager::GetInstance().SetStartTick();
}

void SDLApp::SetRunning(bool isRunning)
{
    m_isRunning = isRunning;
}

void SDLApp::SetEventCallback(std::function<void(void)> func)
{
    m_EventCallback = func;
}

void SDLApp::SetUpdateCallback(std::function<void(void)> func)
{
    m_UpdateCallback = func;
}

void SDLApp::SetRenderCallback(std::function<void(void)> func)
{
    m_RenderCallback = func;
}

SDLApp::~SDLApp()
{
    SDL_DestroyWindow(m_window);
    TTF_Quit();
    SDL_Quit();
    m_renderer = nullptr;
    m_window = nullptr;
}

SDL_Renderer *SDLApp::GetRenderer() const
{
    return m_renderer;
}

void SDLApp::RunApp()
{
    m_isRunning = true;
    while (m_isRunning)
    {
        FramerateManager::GetInstance().LimitFramerate();
        SDL_GetWindowSize(m_window, &m_windowWidth, &m_windowHeight);
        m_EventCallback();
        m_UpdateCallback();
        m_RenderCallback();

        FramerateManager::GetInstance().SetStartTick();
    }
}

int *SDLApp::GetMouseX()
{
    return &m_mousePositionX;
}

int *SDLApp::GetMouseY()
{
    return &m_mousePositionY;
}

int SDLApp::GetWindowWidth()
{
    return m_windowWidth;
}
int SDLApp::GetWindowHeight()
{
    return m_windowHeight - 40;
}

FramerateManager &SDLApp::GetFrameManager()
{
    return FramerateManager::GetInstance();
}