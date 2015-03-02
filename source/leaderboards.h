#ifndef LEADERBOARDS
#define LEADERBOARDS

#include "result.h"
#include "difficulty.h"
#include <list>
#include <vector>

typedef std::vector<Result> Leaderboard;

namespace Leaderboards
{
    void NewResult(Result result);
    std::list<Result> GetResults(Difficulty difficulty);
    std::string LeaderboardFileName(Difficulty difficulty);
	Leaderboard SortResults(std::list<Result> results);
	void ShowLeaderboard(Leaderboard leaderboard);
	std::vector<Leaderboard> GetLeaderboards(std::vector<Difficulty> difficulties);

}

#endif // LEADERBOARDS

