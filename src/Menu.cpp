#include "../include/Menu.hpp"
Menu::Menu(int xx, int yy, int ww, int hh, std::shared_ptr<Font> font)
{
    m_menu_background.w = ww;
    m_menu_background.h = hh;
    m_menu_background.x = xx;
    m_menu_background.y = yy;

    m_scale_plus.m_background.w = 100;
    m_scale_plus.m_background.h = hh;
    m_scale_plus.m_background.x = 0;
    m_scale_plus.m_background.y = yy;

    m_scale_minus.m_background.w = 100;
    m_scale_minus.m_background.h = hh;
    m_scale_minus.m_background.x = 100;
    m_scale_minus.m_background.y = yy;

    m_size_plus.m_background.w = 100;
    m_size_plus.m_background.h = hh;
    m_size_plus.m_background.x = 200;
    m_size_plus.m_background.y = yy;

    m_size_minus.m_background.w = 100;
    m_size_minus.m_background.h = hh;
    m_size_minus.m_background.x = 300;
    m_size_minus.m_background.y = yy;

    m_refresh.m_background.w = 100;
    m_refresh.m_background.h = hh;
    m_refresh.m_background.x = 400;
    m_refresh.m_background.y = yy;

    m_show_points.m_background.w = 100;
    m_show_points.m_background.h = hh;
    m_show_points.m_background.x = 500;
    m_show_points.m_background.y = yy;

    m_menu_font = font;
}

Menu::~Menu()
{
    m_menu_font = nullptr;
}

void Menu::Render(SDL_Renderer *renderer)
{
    // ----- Scale +
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &m_menu_background);

    if (m_scale_plus.is_hovered == true)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Scale +", {0, 0, 0});
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Scale +", {230, 230, 230});
    }
    SDL_RenderFillRect(renderer, &m_scale_plus.m_background);
    m_menu_font->SetPosition(m_scale_plus.m_background.x + (m_scale_plus.m_background.w / 2) - (m_menu_font->GetWidth() / 2),
                             m_scale_plus.m_background.y + (m_scale_plus.m_background.h / 2) - (m_menu_font->GetHeight() / 2));
    m_menu_font->Render();

    // ----- Scale -
    if (m_scale_minus.is_hovered == true)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Scale -", {0, 0, 0});
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Scale -", {230, 230, 230});
    }
    SDL_RenderFillRect(renderer, &m_scale_minus.m_background);
    m_menu_font->SetPosition(m_scale_minus.m_background.x + (m_scale_minus.m_background.w / 2) - (m_menu_font->GetWidth() / 2),
                             m_scale_minus.m_background.y + (m_scale_minus.m_background.h / 2) - (m_menu_font->GetHeight() / 2));
    m_menu_font->Render();

    // ----- Size +
    if (m_size_minus.is_hovered == true)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Size  -", {0, 0, 0});
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Size  -", {230, 230, 230});
    }
    SDL_RenderFillRect(renderer, &m_size_minus.m_background);
    m_menu_font->SetPosition(m_size_minus.m_background.x + (m_size_minus.m_background.w / 2) - (m_menu_font->GetWidth() / 2),
                             m_size_minus.m_background.y + (m_size_minus.m_background.h / 2) - (m_menu_font->GetHeight() / 2));
    m_menu_font->Render();

    // ----- Size -
    if (m_size_plus.is_hovered == true)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Size  +", {0, 0, 0});
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Size  +", {230, 230, 230});
    }
    SDL_RenderFillRect(renderer, &m_size_plus.m_background);
    m_menu_font->SetPosition(m_size_plus.m_background.x + (m_size_plus.m_background.w / 2) - (m_menu_font->GetWidth() / 2),
                             m_size_plus.m_background.y + (m_size_plus.m_background.h / 2) - (m_menu_font->GetHeight() / 2));
    m_menu_font->Render();

    // ----- Refresh
    if (m_refresh.is_hovered == true)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Refresh", {0, 0, 0});
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Refresh", {230, 230, 230});
    }
    SDL_RenderFillRect(renderer, &m_refresh.m_background);
    m_menu_font->SetPosition(m_refresh.m_background.x + (m_refresh.m_background.w / 2) - (m_menu_font->GetWidth() / 2),
                             m_refresh.m_background.y + (m_refresh.m_background.h / 2) - (m_menu_font->GetHeight() / 2));
    m_menu_font->Render();

    // ----- Show Point
    if (m_show_points.is_hovered == true)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Points", {0, 0, 0});
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        m_menu_font->SetText(renderer, "Points", {230, 230, 230});
    }
    SDL_RenderFillRect(renderer, &m_show_points.m_background);
    m_menu_font->SetPosition(m_show_points.m_background.x + (m_show_points.m_background.w / 2) - (m_menu_font->GetWidth() / 2),
                             m_show_points.m_background.y + (m_show_points.m_background.h / 2) - (m_menu_font->GetHeight() / 2));
    m_menu_font->Render();
}

void Menu::Hovering(int x, int y)
{
    SDL_Point point;
    point.x = x;
    point.y = y;

    if (SDL_PointInRect(&point, &m_scale_plus.m_background))
    {
        m_scale_plus.is_hovered = true;
    }
    else
    {
        m_scale_plus.is_hovered = false;
    }

    if (SDL_PointInRect(&point, &m_scale_minus.m_background))
    {
        m_scale_minus.is_hovered = true;
    }
    else
    {
        m_scale_minus.is_hovered = false;
    }

    if (SDL_PointInRect(&point, &m_size_plus.m_background))
    {
        m_size_plus.is_hovered = true;
    }
    else
    {
        m_size_plus.is_hovered = false;
    }

    if (SDL_PointInRect(&point, &m_size_minus.m_background))
    {
        m_size_minus.is_hovered = true;
    }
    else
    {
        m_size_minus.is_hovered = false;
    }

    if (SDL_PointInRect(&point, &m_refresh.m_background))
    {
        m_refresh.is_hovered = true;
    }
    else
    {
        m_refresh.is_hovered = false;
    }

    if (SDL_PointInRect(&point, &m_show_points.m_background))
    {
        m_show_points.is_hovered = true;
    }
    else
    {
        m_show_points.is_hovered = false;
    }
}

int Menu::Clicked(int x, int y)
{
    SDL_Point point;
    point.x = x;
    point.y = y;

    if (SDL_PointInRect(&point, &m_scale_plus.m_background))
    {
        return 1;
    }

    if (SDL_PointInRect(&point, &m_scale_minus.m_background))
    {
        return 2;
    }

    if (SDL_PointInRect(&point, &m_size_plus.m_background))
    {
        return 3;
    }

    if (SDL_PointInRect(&point, &m_size_minus.m_background))
    {
        return 4;
    }

    if (SDL_PointInRect(&point, &m_refresh.m_background))
    {
        return 5;
    }

    if (SDL_PointInRect(&point, &m_show_points.m_background))
    {
        return 6;
    }
    return -1;
}

void Menu::SetWindowSize(int w, int h)
{
    m_menu_background.w = w;
    m_menu_background.h = 40;
    m_menu_background.x = 0;
    m_menu_background.y = h;

    m_scale_plus.m_background.w = 100;
    m_scale_plus.m_background.h = 40;
    m_scale_plus.m_background.x = 0;
    m_scale_plus.m_background.y = h;

    m_scale_minus.m_background.w = 100;
    m_scale_minus.m_background.h = 40;
    m_scale_minus.m_background.x = 100;
    m_scale_minus.m_background.y = h;

    m_size_plus.m_background.w = 100;
    m_size_plus.m_background.h = 40;
    m_size_plus.m_background.x = 200;
    m_size_plus.m_background.y = h;

    m_size_minus.m_background.w = 100;
    m_size_minus.m_background.h = 40;
    m_size_minus.m_background.x = 300;
    m_size_minus.m_background.y = h;

    m_refresh.m_background.w = 100;
    m_refresh.m_background.h = 40;
    m_refresh.m_background.x = 400;
    m_refresh.m_background.y = h;

    m_show_points.m_background.w = 100;
    m_show_points.m_background.h = 40;
    m_show_points.m_background.x = 500;
    m_show_points.m_background.y = h;
}