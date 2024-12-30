#include "position.h"

Position::Position()
{
    x = 0;
    y = 0;
}

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Position::set(int x, int y)
{
    this->x = x;
    this->y = y;
}

bool Position::operator==(const Position &other) const
{
    return x == other.x && y == other.y;
}

Position Position::operator+(const Position &other) const
{
    return Position(x + other.x, y + other.y);
}

Position Position::operator+=(const Position &other)
{
    return *this = *this + other;
}

Position Position::operator-(const Position &other) const
{
    return Position(x - other.x, y - other.y);
}

Position Position::operator-=(const Position &other)
{
    return *this = *this - other;
}

Position Position::operator*(const Position &other) const
{
    return Position(x * other.x, y * other.y);
}
