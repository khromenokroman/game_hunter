//
// Created by roma on 20.10.24.
//
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <filesystem>
#include <map>
#include <memory>
#include <vector>

namespace hunter::background {
struct Background {
    std::vector<std::unique_ptr<SDL_Texture, void (*)(SDL_Texture*)>> textures;
    void load_images(SDL_Renderer* renderer, std::filesystem::path const& path, SDL_Rect* rect);
};
} // namespace hunter::background