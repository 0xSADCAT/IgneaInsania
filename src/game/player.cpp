#include "player.hpp"


Player::Player(const Point& position)
    : _position(position)
{}

Player::Player(const Point& position, const Size speed)
    : _position(position), _speed(speed)
{}

Point Player::position() const
{
    return _position;
}

Size Player::size() const
{
    return _size;
}

Size Player::speed() const
{
    return _speed;
}

void Player::setSpeed(const Size& speed)
{
    _speed = speed;
}

void Player::move(int mcs)
{
    double time = static_cast<double>(mcs) / 1'000'000.0;
    _position.setX(_position.x() + _speed.width() * time);
    _position.setY(_position.y() + _speed.height() * time);
}

TextureId Player::texture() const
{
    return TextureId::Player;
}

void Player::setRotation(double value)
{
    _rotation = value;
}

double Player::rotation() const
{
    return _rotation;
}

void Player::setFlip(Flip flip)
{
    _flip = flip;
}

Flip Player::flip() const
{
    return _flip;
}
