//
// Created by roma on 20.10.24.
//

#include "game.hpp"

hunter::game::Game::Game()
    : m_window{SDL_CreateWindow("hunter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, hunter::CONSTANTS::START_WINDOW_WIDTH,
                                hunter::CONSTANTS::START_WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE),
               SDL_DestroyWindow},
      m_renderer{SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer} {
    m_background.load_images(m_renderer.get(), "../images/zone1.jpg", nullptr);
    m_background.load_images(m_renderer.get(), "../images/aim.png", &m_surface_aim);
    m_background.load_images(m_renderer.get(), "../images/target.png", &m_surface_target);
    m_background.load_music("../sounds/shut.mp3");
}
void hunter::game::Game::run() {
    std::cout << "Start main loop game" << std::endl;

    m_surface_aim_dst = {100, 200, m_surface_aim.w, m_surface_aim.h};
    m_surface_target = {300, 20, 550, 370};
    m_surface_target_dst = {100, 100, 150, 100};

    srand(time(0));

    for (auto i = 0; i < 10; i++) {
        npcs.emplace_back(
            SDL_Rect{rand() % hunter::CONSTANTS::START_WINDOW_WIDTH - 100, rand() % hunter::CONSTANTS::START_WINDOW_HEIGHT - 100, 80, 50});
    }

    int frame = 1;
    int frame_count = 4;
    int cur_frame_time = 0;
    int max_frame_time = 220;
    int last_time = static_cast<int>(SDL_GetTicks());
    int new_time = 0;
    int dt = 0;

    SDL_Event events;
    while (m_is_running) {
        get_os_event(events);

        new_time = static_cast<int>(SDL_GetTicks());
        dt = new_time - last_time;
        last_time = new_time;
        cur_frame_time += dt;
        if (cur_frame_time > max_frame_time) {
            cur_frame_time -= max_frame_time;
            frame += 1;
            if (frame > frame_count) {
                frame = 1;
                m_surface_target.x = 300;
            } else {
                m_surface_target.x += m_surface_target.w;
                for (auto& npc : npcs) {
                    if (npc.x >= hunter::CONSTANTS::START_WINDOW_WIDTH) {
                        npc.x = -100;
                        npc.y = rand() % 700;
                    }
                    npc.x += 60;
                }
            }
        }
        SDL_RenderClear(m_renderer.get());
        SDL_RenderCopy(m_renderer.get(), m_background.textures[0].get(), nullptr, nullptr);
        for (auto const& npc : npcs) {
            SDL_RenderCopy(m_renderer.get(), m_background.textures[2].get(), &m_surface_target, &npc);
        }
        SDL_RenderCopy(m_renderer.get(), m_background.textures[1].get(), &m_surface_aim, &m_surface_aim_dst);
        SDL_RenderPresent(m_renderer.get());
    }
}
void hunter::game::Game::get_os_event(SDL_Event& event) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            m_is_running = false;
        }
        if (event.type == SDL_MOUSEMOTION) {
            m_surface_aim_dst.x = event.motion.x - 100;
            m_surface_aim_dst.y = event.motion.y - 100;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            int mouse_x{}, mouse_y{};
            SDL_GetMouseState(&mouse_x, &mouse_y);
            SDL_Point mouse_pos{mouse_x, mouse_y};
            Mix_PlayChannel(-1, m_background.musics[0].get(), 0);
            for (auto itr = npcs.begin(); itr != npcs.end();) {
                if (SDL_PointInRect(&mouse_pos, &(*itr))) {
                    itr = npcs.erase(itr);
                } else {
                    itr++;
                }
            }
        }
    }
}
