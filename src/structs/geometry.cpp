#include "geometry.hpp"


Point::Point(double x, double y)
    : _x(x), _y(y)
{}

double Point::x() const
{
    return _x;
}

double Point::y() const
{
    return _y;
}

void Point::setX(double x)
{
    _x = x;
}

void Point::setY(double y)
{
    _y = y;
}


Size::Size(double width, double height)
    : _width(width), _height(height)
{}

double Size::width() const
{
    return _width;
}

double Size::height() const
{
    return _height;
}

void Size::setWidth(double width)
{
    _width = width;
}

void Size::setHeight(double height)
{
    _height = height;
}


Rect::Rect(const Point& position, const Size& size)
    : _position(position), _size(size)
{}

Rect::Rect(double pos_x, double pos_y, double size_x, double size_y)
    : Rect({pos_x, pos_y}, {size_x, size_y})
{}

Point Rect::position() const
{
    return _position;
}

Size Rect::size() const
{
    return _size;
}

void Rect::setPosition(const Point& position)
{
    _position = position;
}

void Rect::setSize(const Size& size)
{
    _size = size;
}


std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Point<" << point.x() << ", " << point.y() << ">";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Size& size)
{
    os << "Size<" << size.width() << ", " << size.height() << ">";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Rect& rect)
{
    os << "Rect<" << rect.position() << ", " << rect.size() << ">";
    return os;
}

