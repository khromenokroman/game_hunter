//
// Created by roma on 20.10.24.
//
#pragma once
#include <iostream>

#include "background.hpp"
#include "constants.hpp"
#include "init.hpp"

namespace hunter::game {
struct Game {
    hunter::background::Background m_background;
    std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> m_window;       // окно
    std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)> m_renderer; // рисовальщик
    bool m_is_running{true};
    hunter::init::Init m_initialization;

    Game();
    void run();
    void get_os_event(SDL_Event &event);
};
} // namespace hunter::game
