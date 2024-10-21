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
    hunter::background::Background m_background;                        // сервис загрузка картинок
    SDL_Rect m_surface_aim{0, 0, 0, 0};                                 // полигон для прицела
    SDL_Rect m_surface_aim_dst{0, 0, 0, 0};                             // полигон где будет размещаться прицел
    SDL_Rect m_surface_target{0, 0, 0, 0};                              // полигон для мишени
    SDL_Rect m_surface_target_dst{0, 0, 0, 0};                          // полигон где будет размещаться мишень
    std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> m_window;       // окно
    std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)> m_renderer; // рисовальщик
    bool m_is_running{true};                                            // флаг работы главного цикла игры
    hunter::init::Init m_initialization;                                // сервис инициализация системы

    Game();
    void run();
    void get_os_event(SDL_Event &event);
};
} // namespace hunter::game
