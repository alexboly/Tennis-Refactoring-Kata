#include <string>

static const char *const ZERO = "Love";
static const char *const FIFTEEN = "Fifteen";

static const char *const THIRTY = "Thirty";

static const char *const FORTY = "Forty";

static const char *const SEPARATOR = "-";

static const char *const ALL = "All";

static const char *const DEUCE = "Deuce";

bool hasAdvantage(int playerScore);

std::string formatAdvantageMessage(std::string playerName);
std::string formatWinMessage(std::string playerName);

std::string &foo(int p2Score, std::string &score);

const std::string tennis_score(int p1Score, int p2Score) {
    std::string score = "";
    if (p1Score==p2Score)
    {
        switch (p1Score)
        {
            case 0:
                    score = std::string(ZERO) + std::string(SEPARATOR) + std::string(ALL);
                break;
            case 1:
                    score = std::string(FIFTEEN)  +  std::string(SEPARATOR) + std::string(ALL);
                break;
            case 2:
                    score = std::string(THIRTY) +  std::string(SEPARATOR) + std::string(ALL);
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
	        score =formatWinMessage(secondPlayerName);
        }
    }
    else
    {

	    score=foo(p1Score, score);

	    score+= SEPARATOR;

	    score = foo(p2Score, score);
    }
    return score;
}

std::string &foo(int p2Score, std::string &score) {
	switch(p2Score)
	    {
		    case 0:
			    score+= ZERO;
			    break;
		    case 1:
			    score+= FIFTEEN;
			    break;
		    case 2:
			    score+= THIRTY;
			    break;
		    case 3:
			    score+= FORTY;
			    break;
	    }
	return score;
}

std::string formatAdvantageMessage(std::string playerName) { return std::string("Advantage ") + playerName; }

bool hasAdvantage(int playerScore) { return playerScore >= 4; }

std::string formatWinMessage(std::string playerName)
{
	return std::string("Win for ") + playerName;
}