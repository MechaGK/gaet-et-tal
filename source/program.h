#ifndef PROGRAM_H
#define PROGRAM_H

#include "menu.h"
#include "game.h"

namespace Program
{
	extern bool open;

	extern Menu *main;
	extern Menu *difficulty;
	extern Menu *leaderboard;

	extern Game *game;

	void Initialize();
	void Run();

	void MainMenu(int choice);
	void DifficultyMenu(int choice);
	void LeaderboardMenu(int choice);
	void PrepareLeaderboardMenu();
}

#endif