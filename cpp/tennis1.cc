#include <string>
#include <map>

std::string formatScoreWhenEqual(int aPlayerScore);

std::string &formatScoreWhenAPlayerHasAdvantageOrWon(int p1Score, int p2Score, std::string &score);

std::string formatScoreWhenGameIsInProgressAndBeforeAdvantage(int p1Score, int p2Score);

std::string formatScore(int score);

const std::string tennis_score(int p1Score, int p2Score) {
    std::string score = "";
    bool scoreIsEqual = (p1Score == p2Score);
    bool aPlayerHasAdvantageOrWon = (p1Score >= 4 || p2Score >= 4);

    if (scoreIsEqual) {
        score = formatScoreWhenEqual(p1Score);
    }

    if (!scoreIsEqual && aPlayerHasAdvantageOrWon) {
        score = formatScoreWhenAPlayerHasAdvantageOrWon(p1Score, p2Score, score);
    }

    if (!scoreIsEqual && !aPlayerHasAdvantageOrWon) {
        score = formatScoreWhenGameIsInProgressAndBeforeAdvantage(p1Score, p2Score);
    }

    return score;

}

std::string formatScoreWhenGameIsInProgressAndBeforeAdvantage(int p1Score, int p2Score) {
    return formatScore(p1Score) + "-" + formatScore(p2Score);
}

std::string &formatScoreWhenAPlayerHasAdvantageOrWon(int p1Score, int p2Score, std::string &score) {
    int minusResult = p1Score - p2Score;
    if (minusResult == 1) score = "Advantage player1";
    if (minusResult == -1) score = "Advantage player2";
    if (minusResult >= 2) score = "Win for player1";
    if (minusResult <= -2) score = "Win for player2";
    return score;
}

std::string formatScoreWhenEqual(int aPlayerScore) {
    switch (aPlayerScore) {
        case 0:
            return "Love-All";
        case 1:
            return "Fifteen-All";
        case 2:
            return "Thirty-All";
        default:
            return "Deuce";
    }
}

std::string formatScore(int score) {
    std::map<int, std::string> scoreToScoreLabel = {
            {0, "Love"},
            {1, "Fifteen"},
            {2, "Thirty"},
            {3, "Forty"}
    };
    return scoreToScoreLabel[score];
}
