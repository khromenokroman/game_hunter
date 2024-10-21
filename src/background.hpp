//
// Created by roma on 20.10.24.
//
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <filesystem>
#include <map>
#include <memory>
#include <vector>
#include <iostream>

namespace hunter::background {
struct Background {
    Background();
    std::vector<std::unique_ptr<SDL_Texture, void (*)(SDL_Texture*)>> textures;
    std::vector<std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk*)>> musics;
    void load_images(SDL_Renderer* renderer, std::filesystem::path const& path, SDL_Rect* rect);
    void load_music(std::filesystem::path const& path);
};
} // namespace hunter::background