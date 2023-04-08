#include "../include/Font.hpp"

Font::Font(TTF_Font *font)
{
    m_font = font;
}

Font::~Font()
{
    // Kill Existing Texture
    if (m_texture != nullptr)
    {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }

    // Kill Existing Surface
    if (m_surface != nullptr)
    {
        SDL_FreeSurface(m_surface);
        m_texture = nullptr;
    }
    m_renderer = nullptr;
    m_font = nullptr;
}

void Font::SetText(SDL_Renderer *renderer, std::string text, SDL_Color color)
{
    // Kill Existing Texture
    if (m_texture != nullptr)
    {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }

    // Kill Existing Surface
    if (m_surface != nullptr)
    {
        SDL_FreeSurface(m_surface);
        m_surface = nullptr;
    }

    // Set Renderer
    m_renderer = renderer;

    // Create Sprite Surface with new text and color
    m_surface = TTF_RenderText_Solid(m_font, text.c_str(), color);

    // Set Rectangle
    m_rectangle.x = 0;
    m_rectangle.y = 0;
    m_rectangle.w = m_surface->w;
    m_rectangle.h = m_surface->h;

    // Create and Set Texture
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

    // Kill Existing Surface
    if (m_surface != nullptr)
    {
        SDL_FreeSurface(m_surface);
        m_surface = nullptr;
    }
}

void Font::Render()
{
    if (m_renderer != nullptr)
    {
        SDL_RenderCopy(m_renderer, m_texture, NULL, &m_rectangle);
    }
}

void Font::SetPosition(int x, int y)
{
    m_rectangle.x = x;
    m_rectangle.y = y;
}

int Font::GetX()
{
    return m_rectangle.x;
}

int Font::GetY()
{
    return m_rectangle.y;
}
void Font::SetWidthHeight(int w, int h)
{
    m_rectangle.w = w;
    m_rectangle.h = h;
}

int Font::GetWidth()
{
    return m_rectangle.w;
}

int Font::GetHeight()
{
    return m_rectangle.h;
}
