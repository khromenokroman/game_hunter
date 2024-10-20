//
// Created by roma on 20.10.24.
//

#include "init.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <stdexcept>

hunter::init::Init::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("SDL initialization failed: " + std::string(SDL_GetError()));
    }
    std::cout << "SDL initialization is done" << std::endl;
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        throw std::runtime_error("SDL_image initialization failed: " + std::string(IMG_GetError()));
    }
    std::cout << "SDL_image initialization is done" << std::endl;
}
