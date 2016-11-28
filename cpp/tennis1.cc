#include <string>

using namespace std;

static const char *const ZERO = "Love";
static const char *const FIFTEEN = "Fifteen";

static const char *const THIRTY = "Thirty";

static const char *const FORTY = "Forty";

static const char *const SEPARATOR = "-";

static const char *const ALL = "All";

static const char *const DEUCE = "Deuce";

bool hasAdvantage(int playerScore);

string formatAdvantageMessage(string playerName);
string formatWinMessage(string playerName);

string scoreToString(int score);

string formatScore(int p1Score, int p2Score);

const string tennis_score(int p1Score, int p2Score) {
    string score;
    if (p1Score==p2Score)
    {
        switch (p1Score)
        {
            case 0:
                    score = string(ZERO) + string(SEPARATOR) + string(ALL);
                break;
            case 1:
                    score = string(FIFTEEN)  +  string(SEPARATOR) + string(ALL);
                break;
            case 2:
                    score = string(THIRTY) +  string(SEPARATOR) + string(ALL);
                break;
            default:
                    score = DEUCE;
                break;
            
        }
    }
    else if (hasAdvantage(p1Score) || hasAdvantage(p2Score))
    {
        int minusResult = p1Score-p2Score;

	    const char *firstPlayerName = "player1";
	    const char *secondPlayerName = "player2";

	    if (minusResult == 1) {
	        score = formatAdvantageMessage(firstPlayerName);
        }
	    if (minusResult == -1) {
	        score = formatAdvantageMessage(secondPlayerName);
        }
        if (minusResult>=2) {
	        score = formatWinMessage(firstPlayerName);
        }
        if (minusResult <= -2) {
	        score = formatWinMessage(secondPlayerName);
        }
    }
    else
    {
	    score = formatScore(p1Score, p2Score);
    }
    return score;
}

string formatScore(int p1Score, int p2Score) { return scoreToString(p1Score) + SEPARATOR + scoreToString(p2Score); }

string scoreToString(int score) {
	switch(score)
	{
		case 0:
			return ZERO;
		case 1:
			return FIFTEEN;
		case 2:
			return THIRTY;
		case 3:
			return FORTY;
	}
	return string();

}
string formatAdvantageMessage(string playerName) { return string("Advantage ") + playerName; }

bool hasAdvantage(int playerScore) { return playerScore >= 4; }

string formatWinMessage(string playerName)
{
	return string("Win for ") + playerName;
}