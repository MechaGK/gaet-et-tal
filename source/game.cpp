#include "game.h"
#include "functions.h"
#include "result.h"
#include "leaderboards.h"
#include <iostream>
#include <string>

using namespace std;

Game::Game()
{
    Difficulty *let = new Difficulty;
    let->name = "easy";
    let->numberGuesses = 4;
    let->maxNumber = 20;

    Difficulty *mellem = new Difficulty;
	mellem->name = "medium";
	mellem->numberGuesses = 4;
	mellem->maxNumber = 30;

    Difficulty *svaer = new Difficulty;
	svaer->name = "hard";
	svaer->numberGuesses = 4;
	svaer->maxNumber = 40;

    difficulties.push_back(*let);
	difficulties.push_back(*mellem);
	difficulties.push_back(*svaer);

    delete let;
    delete mellem;
    delete svaer;
}

Game::~Game()
{
    difficulties.clear();
    vector<Difficulty>().swap(difficulties);
}

void Game::Start()
{
    int secretNumber = rand() % difficulty.maxNumber + 1;
    cout << "You have choosen " << difficulty.name << "." << endl;
    cout << "Guess a number between 1 and " << difficulty.maxNumber << endl;

    int guessesUsed, guess;
    string guessText;
    bool won = false;

	for (int i = 0; i < difficulty.maxNumber; ++i)
    {
		guessText = to_string(i + 1) + ". guess: ";
		guess = GetNumber(1, difficulty.maxNumber, guessText);

		if (guess == secretNumber)
        {
            cout << guess << " is the secret, you have won!" << endl;
			guessesUsed = i + 1;
			won = true;
            break;
        }
        else
        {
			cout << guess << " is not the secret number. The secret number is ";
			cout << (guess < secretNumber ? "bigger" : "smaller") << "." << endl << endl;
        }
    }

	if (won)
    {
        string name;

        cout << "Your name: ";
		while (getline(cin, name))
        {
			if (name.size() > 30)
			{
				cout << "Your name is too long!" << endl;
				cout << "Your name: ";
			}
			else if (name != "")
            {
                break;
            }
			else
			{
				cout << "Your name: ";
			}
        }

        Result result;
		result.name = name;
        result.guesses = guessesUsed;
        result.difficulty = difficulty;

        cout << "Saving..." << endl;

        Leaderboards::NewResult(result);
    }
}

void Game::SetDifficulty(int newDifficulty)
{
	difficulty = difficulties[newDifficulty];
}
