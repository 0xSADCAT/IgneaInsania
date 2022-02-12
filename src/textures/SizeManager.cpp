#include "SizeManager.hpp"

#include <cassert>

SizeManager::SizeManager(int window_width, int window_height)
{
    _sizes.resize(static_cast<unsigned int>(TextureId::Undefined));
    resize(window_width, window_height);
}

int SizeManager::size(TextureId id)
{
    assert(static_cast<unsigned int>(id) < static_cast<unsigned int>(TextureId::Undefined));

    return _sizes[static_cast<unsigned int>(id)];
}

void SizeManager::resize(int window_width, int window_height)
{
    assert(window_width > 0 and window_width < 10000);
    assert(window_height > 0 and window_height < 10000);

    int size = std::max(window_width, window_height);

    _sizes[static_cast<unsigned int>(TextureId::Player)] = size / 20;
}
