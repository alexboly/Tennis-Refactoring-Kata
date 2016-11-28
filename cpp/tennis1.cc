#include <string>

static const char *const ZERO = "Love";
static const char *const FIFTEEN = "Fifteen";

static const char *const THIRTY = "Thirty";

static const char *const FORTY = "Forty";

bool hasAdvantage(int playerScore);

const std::string tennis_score(int p1Score, int p2Score) {
    std::string score = "";
    int tempScore=0;
    if (p1Score==p2Score)
    {
        switch (p1Score)
        {
            case 0:
                    score = "Love-All";
                break;
            case 1:
                    score = std::string(FIFTEEN)  + std::string("-All");
                break;
            case 2:
                    score = "Thirty-All";
                break;
            default:
                    score = "Deuce";
                break;
            
        }
    }
    else if (hasAdvantage(p1Score) || hasAdvantage(p2Score))
    {
        int minusResult = p1Score-p2Score;
        if (minusResult==1) score ="Advantage player1";
        else if (minusResult ==-1) score ="Advantage player2";
        else if (minusResult>=2) score = "Win for player1";
        else score ="Win for player2";
    }
    else
    {
        for (int i=1; i<3; i++)
        {
            if (i==1) tempScore = p1Score;
            else { score+="-"; tempScore = p2Score;}
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

bool hasAdvantage(int playerScore) { return playerScore >= 4; }
