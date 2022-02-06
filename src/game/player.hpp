#pragma once

#include "abstract_object.hpp"


class Player final : public AbstractObject
{
public:
    Player() = default;
    Player(const Point& position);
    Player(const Point& position, const Size speed);

    Point position() const override;
    Size size() const override;

    Size speed() const override;
    void setSpeed(const Size& speed) override;

    void move(int mcs) override;

    TextureId texture() const override;

    void setRotation(double value) override;
    double rotation() const override;

    void setFlip(Flip flip) override;
    Flip flip() const override;

private:
    Point _position = {0.0, 0.0};
    /* temporary unused */ Size _size = {0.0, 0.0};
    Size _speed = {0.0, 0.0};

    double _rotation = 0.0;
    Flip _flip = Flip::None;
};

