#pragma once
#include "ball.h"
#include "paddle.h"

class Game
{
private:
    Ball ball;
    Paddle paddle1;
    Paddle paddle2;
    int playerOneScore;
    int playerTwoScore;

public:
    bool isRunning;
    bool isGameOver;
    Game() : ball(), paddle1(1), paddle2(2), playerOneScore(0), playerTwoScore(0), isGameOver(false) {}
    void Update();
    void Draw();
    void CheckCollisions();
    void Reset();
    void DisplayScore();
    void DisplayWinner();
};
