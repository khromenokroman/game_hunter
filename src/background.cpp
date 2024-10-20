//
// Created by roma on 20.10.24.
//

#include "background.hpp"

#include <iostream>
void hunter::background::Background::load_images(SDL_Renderer* renderer, std::filesystem::path const& path, SDL_Rect* rect) {
    std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface_image{IMG_Load(path.c_str()), SDL_FreeSurface};
    if (rect) {
        rect->w = surface_image->w;
        rect->h = surface_image->h;
    }
    std::unique_ptr<SDL_Texture, void (*)(SDL_Texture*)> texture_image{SDL_CreateTextureFromSurface(renderer, surface_image.get()),
                                                                       SDL_DestroyTexture};
    textures.emplace_back(std::move(texture_image));
    std::cout << "Add background file: " << path.filename() << std::endl;
}
