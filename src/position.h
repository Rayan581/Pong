#pragma once

struct Position
{
    int x, y;
    Position();
    Position(int x, int y);
    void set(int x, int y);
    bool operator==(const Position &other) const;
    Position operator+(const Position &other) const;
    Position operator+=(const Position &other);
    Position operator-(const Position &other) const;
    Position operator-=(const Position &other);
};
