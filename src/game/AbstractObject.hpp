#pragma once

#include "../textures/TextureId.hpp"
#include "../structs/Geometry.hpp"


class AbstractObject
{
public:
    virtual ~AbstractObject() = default;

    virtual Point position() const = 0;
    /* temporary unused */ virtual Size size() const = 0;

    virtual Size speed() const = 0;
    virtual void setSpeed(const Size& speed) = 0;

    virtual void move(int mcs) = 0;

    virtual TextureId texture() const = 0;

    virtual void setRotation(double value) = 0;
    virtual double rotation() const = 0;

    virtual void setFlip(Flip flip) = 0;
    virtual Flip flip() const = 0;
};

