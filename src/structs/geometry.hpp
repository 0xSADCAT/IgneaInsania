#pragma once


#include <ostream>


class Point
{
public:
    Point(double x, double y);

    double x() const;
    double y() const;

    void setX(double x);
    void setY(double y);

private:
    double _x;
    double _y;
};


class Size
{
public:
    Size(double width, double height);

    double width() const;
    double height() const;

    void setWidth(double width);
    void setHeight(double height);

private:
    double _width;
    double _height;
};


class Rect
{
public:
    Rect(const Point& position, const Size& size);
    Rect(double pos_x, double pos_y, double size_x, double size_y);

    Point position() const;
    Size size() const;

    void setPosition(const Point& position);
    void setSize(const Size& size);

private:
    Point _position;
    Size _size;
};


std::ostream& operator<<(std::ostream& os, const Point& point);
std::ostream& operator<<(std::ostream& os, const Size& size);
std::ostream& operator<<(std::ostream& os, const Rect& rect);

