//
// Created by roma on 20.10.24.
//
#pragma once
#include <SDL2/SDL_mixer.h>

#include <iostream>
#include <list>

#include "background.hpp"
#include "constants.hpp"
#include "init.hpp"

namespace hunter::game {
struct Game {
    std::list<SDL_Rect> m_npcs;                                         // боты
    hunter::background::Background m_background;                        // сервис загрузка картинок
    SDL_Rect m_surface_aim{0, 0, 0, 0};                                 // полигон для прицела
    SDL_Rect m_surface_aim_dst{0, 0, 0, 0};                             // полигон где будет размещаться прицел
    SDL_Rect m_surface_target{0, 0, 0, 0};                              // полигон для мишени
    SDL_Rect m_surface_target_dst{0, 0, 0, 0};                          // полигон где будет размещаться мишень
    std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> m_window;       // окно
    std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)> m_renderer; // рисовальщик
    bool m_is_running{true};                                            // флаг работы главного цикла игры
    bool m_state_mouse{static_cast<bool>(hunter::CONSTANTS::STATE_MOUSE::UP)};
    hunter::init::Init m_initialization; // сервис инициализация системы

    Game();
    void run();
    void get_os_event(SDL_Event &event);
    void create_npc();
    void move_npc();
    void render_npc();
    void render_window_game();
    void check_good_shot();
};
} // namespace hunter::game
