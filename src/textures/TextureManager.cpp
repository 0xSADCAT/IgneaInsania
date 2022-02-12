#include "TextureManager.hpp"

#include <iostream>
#include <cassert>
#include <SDL2/SDL_image.h>

#include "TexturePath.hpp"


TextureManager::TextureManager(SDL_Renderer* renderer)
    : _renderer(renderer)
{
    assert(renderer != nullptr);

    loadAll();
}

TextureManager::~TextureManager()
{
    this->free();
}

SDL_Texture* TextureManager::get(TextureId id) const
{
    if (static_cast<unsigned int>(id) >= static_cast<unsigned int>(TextureId::Undefined))
    {
        return nullptr;
    }

    return _textures[static_cast<unsigned int>(id)];
}

SDL_Texture* TextureManager::load(TextureId id)
{
    SDL_Texture* result = nullptr;

    switch (id) {
    case TextureId::Player:
        result = IMG_LoadTexture(_renderer, texture_path::player.c_str());
        break;

    case TextureId::Undefined:
        std::cerr << "[WARN] TextureManager::load(TextureId id): id = Undefined" << std::endl
                  << "Loading UNDEFINED texture???" << std::endl;
        break;
    }

    if (result == nullptr)
    {
        std::cerr << "[WARN] Failed to load texture:" << std::endl
                  << IMG_GetError() << std::endl;
    }
    return result;
}

void TextureManager::loadAll()
{
    _textures.reserve(static_cast<unsigned int>(TextureId::Undefined));

    _textures.push_back(load(TextureId::Player));

    if (_textures.size() != static_cast<unsigned int>(TextureId::Undefined))
    {
        std::cerr << "[WARN] Loaded not all textures!" << std::endl;
    }
}

void TextureManager::free()
{
    for (auto& texture : _textures)
    {
        if (texture != nullptr)
        {
            SDL_DestroyTexture(texture);
        }
    }
}
