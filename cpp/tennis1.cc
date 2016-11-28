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

const std::string tennis_score(int p1Score, int p2Score) {
    std::string score = "";
    int tempScore=0;
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

	    if (minusResult==1) {
	        score = formatAdvantageMessage("player1");
        }
        if (minusResult == -1) {
	        score = formatAdvantageMessage("player2");
        }
        if (minusResult>=2) {
	        score = formatWinMessage("player1");
        }
        if (minusResult <= -2) {
	        score =formatWinMessage("player2");
        }
    }
    else
    {
        for (int i=1; i<3; i++)
        {
            if (i==1) tempScore = p1Score;
            else { score+= SEPARATOR; tempScore = p2Score;}
            switch(tempScore)
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
        }
    }
    return score;
}

std::string formatAdvantageMessage(std::string playerName) { return std::string("Advantage ") + playerName; }

bool hasAdvantage(int playerScore) { return playerScore >= 4; }

std::string formatWinMessage(std::string playerName)
{
	return std::string("Win for ") + playerName;
}