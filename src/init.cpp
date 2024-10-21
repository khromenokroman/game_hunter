//
// Created by roma on 20.10.24.
//

#include "init.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>
#include <stdexcept>

//@todo: добавить деструктор для очистки
hunter::init::Init::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("SDL initialization failed: " + std::string(SDL_GetError()));
    }
    std::cout << "SDL initialization is done" << std::endl;
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        throw std::runtime_error("SDL_image initialization failed: " + std::string(IMG_GetError()));
    }
    std::cout << "SDL_image initialization is done" << std::endl;
    if (Mix_Init(MIX_INIT_MP3) == 0) {
        throw std::runtime_error("SDL_mixer initialization failed: " + std::string(IMG_GetError()));
    }
    std::cout << "SDL_mixer initialization is done" << std::endl;
}
