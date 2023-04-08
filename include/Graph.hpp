#pragma once
// Standard C++
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>

// Custom
#include "../include/ResourceFactory.hpp"
#include "../include/DataFile.hpp"

class Graph
{
private:
    int m_size = 2;
    int m_multiplier = 10;
    int m_scale = 1;
    int m_horizontal_space;
    int m_vertical_space;
    int m_window_width;
    int m_window_height;
    bool m_show_points = true;

public:
    void DrawGraph(SDL_Renderer *rend, std::vector<std::shared_ptr<Point>> &points, std::shared_ptr<Font> font);
    void ChangeSize(int n);
    void ChangeScale(int n);
    void Change_Show_Points();
    void SetWindowSize(int w, int h);
    Graph();
    Graph(int w, int h);
    ~Graph();
};
void Graph::ChangeSize(int n)
{
    if (n > 0)
    {
        if (m_size < 10)
        {
            m_size += n;
            m_horizontal_space = m_window_width / (m_size * m_multiplier);
            m_vertical_space = m_window_height / (m_size * m_multiplier);
        }
    }
    else
    {
        if (m_size > 1)
        {
            m_size += n;
            m_horizontal_space = m_window_width / (m_size * m_multiplier);
            m_vertical_space = m_window_height / (m_size * m_multiplier);
        }
    }
}

void Graph::ChangeScale(int n)
{
    if (n > 0)
    {
        if (m_scale < 100)
        {
            m_scale += n;
        }
    }
    else
    {
        if (m_scale > 1)
        {
            m_scale += n;
        }
    }
}
void Graph::Change_Show_Points()
{
    if (m_show_points)
    {
        m_show_points = false;
    }
    else
    {
        m_show_points = true;
    }
}
void Graph::SetWindowSize(int w, int h)
{
    m_window_width = w;
    m_window_height = h;
}
void Graph::DrawGraph(SDL_Renderer *rend, std::vector<std::shared_ptr<Point>> &points, std::shared_ptr<Font> font)
{
    m_horizontal_space = m_window_width / (m_size * m_multiplier);
    m_vertical_space = m_window_height / (m_size * m_multiplier);

    SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);

    // ----- Draw Solid Graph Lines
    SDL_RenderDrawLine(rend, m_window_width / 2, 0, m_window_width / 2, m_window_height);
    SDL_RenderDrawLine(rend, 0, m_window_height / 2, m_window_width, m_window_height / 2);

    // ----- Draw Axis Graph Lines
    for (int i = 1; i < m_size * m_multiplier; i++)
    {
        // X Axis
        SDL_RenderDrawLine(rend, i * m_horizontal_space, m_window_height / 2 - 10, i * m_horizontal_space, m_window_height / 2 + 10);
        // Y Axis
        SDL_RenderDrawLine(rend, m_window_width / 2 - 10, i * m_vertical_space, m_window_width / 2 + 10, i * m_vertical_space);
    }

    // ----- Draw Axis Numbers
    for (int i = (m_size * m_multiplier / 2) + 1; i < m_size * m_multiplier; i++)
    {
        // Postive X Axis
        font->SetText(rend, std::to_string((i - (m_size * m_multiplier / 2)) * m_scale), {0, 255, 255});
        font->SetPosition((i * m_horizontal_space) - font->GetWidth() / 2, m_window_height / 2 + 15);
        font->Render();

        // Negative Y Axis
        font->SetText(rend, "-" + std::to_string((i - (m_size * m_multiplier / 2)) * m_scale), {0, 255, 255});
        font->SetPosition(m_window_width / 2 - 15 - font->GetWidth(), (i * m_vertical_space) - font->GetHeight() / 2);
        font->Render();
    }

    // ----- Draw Axis Numbers
    for (int i = (m_size * m_multiplier / 2) - 1; i > 0; i--)
    {
        // Negative X Axis
        font->SetText(rend, "-" + std::to_string((i - (m_size * m_multiplier / 2)) * m_scale), {0, 255, 255});
        font->SetPosition((i * m_horizontal_space) - font->GetWidth() / 2, m_window_height / 2 + 15);
        font->Render();

        // Postive Y Axis
        font->SetText(rend, std::to_string(std::abs((i - (m_size * m_multiplier / 2))) * m_scale), {0, 255, 255});
        font->SetPosition(m_window_width / 2 - 15 - font->GetWidth(), (i * m_vertical_space) - font->GetHeight() / 2);
        font->Render();
    }

    // ----- Draw Points
    const int point_count = points.size();
    for (int i = 0; i < point_count; i++)
    {
        float x = (m_window_width / 2) + (points[i]->GetX() / m_scale) * m_horizontal_space;
        float y = (m_window_height / 2) + (points[i]->GetY() / m_scale) * m_vertical_space * -1;
        SDL_SetRenderDrawColor(rend, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPointF(rend, x, y);
        SDL_RenderDrawPointF(rend, x - 1, y);
        SDL_RenderDrawPointF(rend, x + 1, y);
        SDL_RenderDrawPointF(rend, x, y - 1);
        SDL_RenderDrawPointF(rend, x, y + 1);
        SDL_RenderDrawPointF(rend, x + 1, y - 1);
        SDL_RenderDrawPointF(rend, x - 1, y - 1);
        SDL_RenderDrawPointF(rend, x + 1, y + 1);
        SDL_RenderDrawPointF(rend, x - 1, y + 1);

        SDL_RenderDrawPointF(rend, x - 2, y);
        SDL_RenderDrawPointF(rend, x + 2, y);
        SDL_RenderDrawPointF(rend, x, y - 2);
        SDL_RenderDrawPointF(rend, x, y + 2);
        SDL_RenderDrawPointF(rend, x + 2, y - 2);
        SDL_RenderDrawPointF(rend, x - 2, y - 2);
        SDL_RenderDrawPointF(rend, x + 2, y + 2);
        SDL_RenderDrawPointF(rend, x - 2, y + 2);
        if (m_show_points == true)
        {
            // Point Coordinate Text
            std::stringstream bufferx;
            std::stringstream buffery;
            bufferx.precision(2);
            bufferx << std::fixed << points[i]->GetX();
            buffery.precision(2);
            buffery << std::fixed << points[i]->GetY();

            font->SetText(rend, bufferx.str() + ", " + buffery.str(), {255, 255, 0});
            font->SetPosition(x + 5, y - 15);

            font->Render();
        }
    }
}

Graph::Graph(/* args */)
{
}

Graph::Graph(int w, int h)
{
    m_window_width = w;
    m_window_height = h;
}

Graph::~Graph()
{
}
