#pragma once

#include <vector>

#include "TextureId.hpp"


class SizeManager
{
public:
    SizeManager(int window_width, int window_height);

    int size(TextureId id);

    void resize(int window_width, int window_height);

private:
    std::vector<int> _sizes;
};

