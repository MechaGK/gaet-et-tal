#ifndef GAME_H
#define GAME_H
#include "difficulty.h"
#include <vector>

class Game
{
public:
    std::vector<Difficulty> difficulties;
    Difficulty difficulty;
    Game();
    ~Game();
    void Start();
    void SetDifficulty(int newDifficulty);
};

#endif // GAME_H
