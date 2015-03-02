#include "input_handlers.h"
#include "program.h"
#include <iostream>

using namespace std;

namespace InputHandler
{
	void MainMenu(int choice)
	{
		cout << endl << endl;
		switch (choice)
		{
		case 0:
			Program::difficulty->Show();
			break;
		case 1:
			Program::leaderboard->();
			break;
		case 2:
			Program::open = false;
			break;
		default:
			break;
		}
	}

	void DifficultyMenu(int choice)
	{
		Program::game->SetDifficulty(choice);
		Program::game->Start();
	}

}