#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "leaderboards.h"

using namespace std;

namespace Leaderboards
{
    void NewResult(Result result)
    {
		string filNavn = LeaderboardFileName(result.difficulty);
        ofstream ranglisteFil;
        ranglisteFil.open(filNavn, ios::app);

        if (ranglisteFil.is_open())
        {
            ranglisteFil << result.name << endl;
            ranglisteFil << result.guesses << endl << endl;
            ranglisteFil.close();
        }
    }

    list<Result> GetResults(Difficulty Difficulty)
    {
        list<Result> resultater;
        Result result;
        resultater.push_back(result);

        //cout << LeaderboardFileName(Difficulty) << endl;
		string filNavn = LeaderboardFileName(Difficulty);
        ifstream ranglisteFil;
        ranglisteFil.open(filNavn);

        string linje;
        int tal;

        //cout << "Checker om fil er sikker " << ranglisteFil.good() << endl;
        if (ranglisteFil.good())
        {
            //cout << "Fil er sikker" << endl;

            while ( getline(ranglisteFil, linje))
            {
                istringstream iss(linje);

                if (linje.empty())
                {
                    Result result;
                    resultater.push_back(result);
                }
                else if (iss >> tal)
                {
                    resultater.back().guesses = tal;
                }
                else
                {
                    resultater.back().name = linje;
                }
            }


        }
        else
        {
            resultater.pop_back();
        }

        //cout << "Lukker " << filNavn << "... " << endl;
        ranglisteFil.close();
        //cout << filNavn << " lukket" << endl;

        if (!resultater.empty())
        {
            if (resultater.front().name.empty())
            {
                resultater.pop_front();
            }

            if (resultater.back().name.empty())
            {
                resultater.pop_back();
            }
        }

        //cout << "Færdig med at hente " << resultater.size() << " resultater" << endl;

        return resultater;
    }

    string LeaderboardFileName(Difficulty Difficulty)
    {
        return "rangliste_" + Difficulty.name + ".txt";
    }

    Leaderboard SortResults(list<Result> resultater)
    {
        //cout << "Begynder sortering af " << resultater.size() << " resultater" << endl;

        list<Result> sorteredeResultater;

        vector<Result> v;

        if (!resultater.empty())
        {
            sorteredeResultater.push_back(resultater.front());
            resultater.pop_front();

            bool indsat;
            for (list<Result>::iterator it = resultater.begin(); it != resultater.end(); ++it)
            {
                indsat = false;

                for (list<Result>::iterator sit = sorteredeResultater.begin(); sit != sorteredeResultater.end(); ++sit)
                {
                    if (it->guesses < sit->guesses)
                    {
                        sorteredeResultater.insert(sit, (*it));
                        indsat = true;
                        break;
                    }
                }

                if (!indsat)
                {
                    sorteredeResultater.push_back((*it));
                }
            }

            v = Leaderboard{ std::make_move_iterator(std::begin(sorteredeResultater)),
                                std::make_move_iterator(std::end(sorteredeResultater)) };;
        }
        else
        {
            //cout << "Afbryder. Der er intet at sorterer." << endl;
        }


        return v;
    }

	void ShowLeaderboard(Leaderboard leaderboard)
	{
		if (leaderboard.size() > 0)
		{
			cout << setfill('_') << setw(26) << "_" << endl;
			cout << "|_" << "NR." << "_|_";
			cout << setfill('_') << setw(10) << "NAME" << "_|_";
			cout << "GUESS" << "_|" << endl;
			for (int i = 0; i < 10; ++i)
			{
				if (i >= leaderboard.size())
				{
					break;
				}
				cout << "|" << setfill('_') << setw(3) << i + 1 << "._|_";
				cout << setfill('_') << setw(10) << leaderboard[i].name << "_|_";
				cout << setfill('_') << setw(4) << leaderboard[i].guesses << "__|" << endl;
			}
		}
		else
		{
			cout << "No entries on leaderboard" << endl;
		}
	}

	vector<Leaderboard> GetLeaderboards(vector<Difficulty> difficulties)
	{
		Leaderboard leaderboard;
		vector<Leaderboard> leaderboards;
		for (vector<Difficulty>::iterator itr = difficulties.begin(); itr != difficulties.end(); ++itr)
		{
			leaderboard = SortResults(
				GetResults((*itr)));
			leaderboards.push_back(leaderboard);
		}

		return leaderboards;
	}
}
