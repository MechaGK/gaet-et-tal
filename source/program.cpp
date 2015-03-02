#include <iostream>
#include <vector>
#include <iomanip>
#include "program.h"
#include "leaderboards.h"

using namespace std;



vector<string> mainMenuEntries = { "play", "leaderboards", "quit" };
vector<string> difficulties;
vector<Leaderboard> leaderboards;

namespace Program
{
	int leaderboardMenuBackIndex;
	bool open = true;

	Menu *main;
	Menu *difficulty;
	Menu *leaderboard;

	Game *game;

	void Initialize()
	{
		srand((unsigned)time(0));
		game = new Game();

		for (vector<Difficulty>::iterator itr = game->difficulties.begin(); itr != game->difficulties.end(); ++itr)
		{
			difficulties.push_back(itr->name);
		}

		vector<string> menuEntries;
		for (vector<Difficulty>::iterator itr = game->difficulties.begin(); itr != game->difficulties.end(); ++itr)
		{
			menuEntries.push_back("Show leaderboard for " + itr->name);
		}
		menuEntries.push_back("Back");
		leaderboardMenuBackIndex = menuEntries.size() - 1;

		Program::main = new Menu("Welcome to guess a number", mainMenuEntries, MainMenu);
		Program::difficulty = new Menu("Choose difficulty", difficulties, DifficultyMenu);
		Program::leaderboard = new Menu("", menuEntries, LeaderboardMenu);
	}

	void Run()
	{
		cout << endl << endl;
		Program::main->Show();
	}

	void MainMenu(int choice)
	{
		cout << endl << endl;
		switch (choice)
		{
		case 0:
			difficulty->Show();
			break;
		case 1:
			PrepareLeaderboardMenu();
			leaderboard->Show();
			break;
		case 2:
			open = false;
			break;
		default:
			break;
		}
	}

	void DifficultyMenu(int choice)
	{
		game->SetDifficulty(choice);
		game->Start();
	}

	void PrepareLeaderboardMenu()
	{
		leaderboards = Leaderboards::GetLeaderboards(game->difficulties);
	}

	void LeaderboardMenu(int choice)
	{
		if (choice < leaderboardMenuBackIndex)
		{
			Leaderboards::ShowLeaderboard(leaderboards[choice]);
			leaderboard->Show();
		}
	}
}