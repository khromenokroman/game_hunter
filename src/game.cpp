//
// Created by roma on 20.10.24.
//

#include "game.hpp"

hunter::game::Game::Game()
    : m_window{SDL_CreateWindow("test_window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, hunter::CONSTANTS::START_WINDOW_WIDTH,
                                hunter::CONSTANTS::START_WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE),
               SDL_DestroyWindow},
      m_renderer{SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer} {
    m_background.load_images(m_renderer.get(), "../images/zone1.jpg", nullptr);
}
void hunter::game::Game::run() {
    std::cout << "Start main loop game" << std::endl;
    SDL_RenderClear(m_renderer.get());

    SDL_RenderClear(m_renderer.get());
    SDL_RenderCopy(m_renderer.get(), m_background.textures.back().get(), nullptr, nullptr);
    SDL_RenderPresent(m_renderer.get());
    SDL_Event events;
    while (m_is_running) {
        get_os_event(events);
        SDL_RenderPresent(m_renderer.get());
        SDL_Delay(100);
    }
}
void hunter::game::Game::get_os_event(SDL_Event& event) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            m_is_running = false;
        }
    }
}
