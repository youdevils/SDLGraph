#include "../include/SDLResourceManager.hpp"

SDLResourceManager::SDLResourceManager(/* args */)
{
}

SDLResourceManager::~SDLResourceManager()
{
    for (auto element : m_surfaces)
    {
        SDL_FreeSurface(element.second);
    }

    for (auto element : m_ttfs)
    {
        TTF_CloseFont(element.second);
    }
}

SDLResourceManager &SDLResourceManager::GetInstance()
{
    static SDLResourceManager *s_instance = new SDLResourceManager;
    return *s_instance;
}

SDL_Surface *SDLResourceManager::GetSurface(std::string location)
{
    auto search = m_surfaces.find(location);
    if (search != m_surfaces.end())
    {
        return m_surfaces[location];
    }
    else
    {
        m_surfaces.insert({location, IMG_Load(location.c_str())});
        return m_surfaces[location];
    }

    std::cout << "\nError Finding or Loading Resource";

    return nullptr;
}
TTF_Font *SDLResourceManager::GetTTF(std::string location, int size)
{
    std::string key = location + std::to_string(size);
    auto search = m_ttfs.find(key);
    if (search != m_ttfs.end())
    {
        return m_ttfs[key];
    }
    else
    {
        m_ttfs.insert({key, TTF_OpenFont(location.c_str(), size)});
        return m_ttfs[key];
    }

    std::cout << "\nError Finding or Loading Resource";

    return nullptr;
}