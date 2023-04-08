// Standard C++
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>

// Custom
#include "../include/SDLApp.hpp"
#include "../include/ResourceFactory.hpp"
#include "../include/DataFile.hpp"
#include "../include/Graph.hpp"

SDLApp *app;

Graph graph;

DataFile file;

ResourceFactory &RM()
{
    return ResourceFactory::GetInstance();
}

void HandleEvents()
{
    SDL_Event window_event;
    SDL_GetMouseState(app->GetMouseX(), app->GetMouseY());
    graph.SetWindowSize(app->GetWindowWidth(), app->GetWindowHeight());
    RM().GetMenu()->SetWindowSize(app->GetWindowWidth(), app->GetWindowHeight());
    while (SDL_PollEvent(&window_event))
    {
        if (window_event.type == SDL_QUIT)
        {
            app->SetRunning(false);
            break;
        }
        if (window_event.type == SDL_KEYUP && window_event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        {
            app->SetRunning(false);
            break;
        }
        if (window_event.type == SDL_KEYUP && window_event.key.keysym.scancode == SDL_SCANCODE_KP_PLUS)
        {
            graph.ChangeScale(1);
            break;
        }
        if (window_event.type == SDL_KEYUP && window_event.key.keysym.scancode == SDL_SCANCODE_KP_MINUS)
        {
            graph.ChangeScale(-1);
            break;
        }
        if (window_event.type == SDL_KEYUP && window_event.key.keysym.scancode == SDL_SCANCODE_KP_8)
        {
            graph.ChangeSize(1);
            break;
        }
        if (window_event.type == SDL_KEYUP && window_event.key.keysym.scancode == SDL_SCANCODE_KP_2)
        {
            graph.ChangeSize(-1);
            break;
        }
        if (window_event.type == SDL_KEYUP && window_event.key.keysym.scancode == SDL_SCANCODE_KP_7)
        {
            graph.Change_Show_Points();
            break;
        }
        if (window_event.type == SDL_KEYUP && window_event.key.keysym.scancode == SDL_SCANCODE_KP_0)
        {
            RM().ClearPoints();
            file.Read_Data_From_File(RM().GetPoints());
            break;
        }
        if (window_event.type == SDL_MOUSEBUTTONUP && window_event.button.button == SDL_BUTTON_LEFT)
        {
            int button = RM().GetMenu()->Clicked(*app->GetMouseX(), *app->GetMouseY());
            switch (button)
            {
            case 1:
                graph.ChangeScale(1);
                break;
            case 2:
                graph.ChangeScale(-1);
                break;
            case 3:
                graph.ChangeSize(1);
                break;
            case 4:
                graph.ChangeSize(-1);
                break;
            case 5:
                RM().ClearPoints();
                file.Read_Data_From_File(RM().GetPoints());
                break;
            case 6:
                graph.Change_Show_Points();
                break;
            default:
                break;
            }
        }
    }
}

void HandleUpdates()
{
    if (RM().GetMenu() != nullptr)
    {
        RM().GetMenu()->Hovering(*app->GetMouseX(), *app->GetMouseY());
    }
}

void HandleRendering()
{
    // Clear Window
    SDL_SetRenderDrawColor(app->GetRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(app->GetRenderer());

    // ----- DrawGraph
    graph.DrawGraph(app->GetRenderer(), RM().GetPoints(), RM().GetFont("Roboto"));

    // ----- Draw Menubar
    RM().GetMenu()->Render(app->GetRenderer());

    // Present New Screen
    SDL_RenderPresent(app->GetRenderer());
}

int main(int argc, char *argv[])
{
    // ----- SDL Application
    app = new SDLApp("Graph1.0", 1500, 1500);

    // ----- App Loop Callback Functions
    app->SetEventCallback(HandleEvents);
    app->SetUpdateCallback(HandleUpdates);
    app->SetRenderCallback(HandleRendering);

    // ----- Resource Creation
    RM().CreateFont("Roboto", "../assets/Roboto-Regular.ttf", 18);
    RM().CreateFont("RobotoMenu", "../assets/Roboto-Regular.ttf", 24);

    // file.Write_Data_To_File(RM().GetPoints());
    // file.Read_Data_From_File(RM().GetPoints());

    graph = Graph(app->GetWindowWidth(), app->GetWindowHeight());

    RM().CreateMenu(0, app->GetWindowHeight(), app->GetWindowWidth(), 40, RM().GetFont("RobotoMenu"));

    // ----- Start Gameloop
    app->RunApp();

    // ----- Cleaup
    delete app;

    return 0;
}