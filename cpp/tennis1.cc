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

std::string &appendScoreToString(int score, std::string &scoreMessage);
std::string scoreToString(int score);

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

	    score+=scoreToString(p1Score);

	    score+= SEPARATOR;

	    score += scoreToString(p2Score);
    }
    return score;
}

std::string &appendScoreToString(int score, std::string &scoreMessage) {
	switch(score)
	    {
		    case 0:
			    scoreMessage+= ZERO;
			    break;
		    case 1:
			    scoreMessage+= FIFTEEN;
			    break;
		    case 2:
			    scoreMessage+= THIRTY;
			    break;
		    case 3:
			    scoreMessage+= FORTY;
			    break;
	    }
	return scoreMessage;
}

std::string scoreToString(int score) {
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
	return std::string();

}
std::string formatAdvantageMessage(std::string playerName) { return std::string("Advantage ") + playerName; }

bool hasAdvantage(int playerScore) { return playerScore >= 4; }

std::string formatWinMessage(std::string playerName)
{
	return std::string("Win for ") + playerName;
}