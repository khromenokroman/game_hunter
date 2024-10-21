//
// Created by roma on 20.10.24.
//

#include "background.hpp"

void hunter::background::Background::load_images(SDL_Renderer* renderer, std::filesystem::path const& path, SDL_Rect* rect) {
    std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface_image{IMG_Load(path.c_str()), SDL_FreeSurface};
    if (!surface_image) {
        throw std::runtime_error("Error while load image " + path.string() + " -> " + std::string(SDL_GetError()));
    }
    if (rect) {
        rect->w = surface_image->w;
        rect->h = surface_image->h;
    }
    std::unique_ptr<SDL_Texture, void (*)(SDL_Texture*)> texture_image{SDL_CreateTextureFromSurface(renderer, surface_image.get()),
                                                                       SDL_DestroyTexture};
    textures.emplace_back(std::move(texture_image));
    std::cout << "Add background file: " << path.filename() << std::endl;
}
void hunter::background::Background::load_music(std::filesystem::path const& path) {
    std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk*)> gun_shot{Mix_LoadWAV("../sounds/gun_shot.mp3"), Mix_FreeChunk};
    if (!gun_shot) {
        throw std::runtime_error("Error while loading music " + path.string() + " -> " + Mix_GetError());
    }
    musics.emplace_back(std::move(gun_shot));
}
hunter::background::Background::Background() { Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048); }
