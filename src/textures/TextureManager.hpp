#pragma once

#include <vector>
#include <SDL2/SDL.h>

#include "TextureId.hpp"


class TextureManager
{
public:
    TextureManager(SDL_Renderer* renderer);
    ~TextureManager();

    SDL_Texture* get(TextureId id) const;

private:
    SDL_Texture* load(TextureId id);
    void loadAll();
    void free();

    std::vector<SDL_Texture*> _textures;
    SDL_Renderer* _renderer;

    TextureManager(TextureManager&) = delete;
    TextureManager(TextureManager&&) = delete;
    TextureManager& operator=(TextureManager&) = delete;
    TextureManager& operator=(TextureManager&&) = delete;
};
