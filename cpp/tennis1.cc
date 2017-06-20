#include <string>
#include <map>

std::string &formatScoreWhenEqual(int p1Score, std::string &score);

std::string &formatScoreWhenAPlayerHasAdvantageOrWon(int p1Score, int p2Score, std::string &score);

std::string &formatScoreWhenGameIsInProgressAndBeforeAdvantage(int p1Score, int p2Score, std::string &score);

std::string &formatScore(std::string &score, int tempScore);

const std::string tennis_score(int p1Score, int p2Score) {
    std::string score = "";
    bool scoreIsEqual = (p1Score == p2Score);
    bool aPlayerHasAdvantageOrWon = (p1Score >= 4 || p2Score >= 4);

    if (scoreIsEqual) {
        score = formatScoreWhenEqual(p1Score, score);
    }

    if (!scoreIsEqual && aPlayerHasAdvantageOrWon) {
        score = formatScoreWhenAPlayerHasAdvantageOrWon(p1Score, p2Score, score);
    }

    if (!scoreIsEqual && !aPlayerHasAdvantageOrWon) {
        score = formatScoreWhenGameIsInProgressAndBeforeAdvantage(p1Score, p2Score, score);
    }

    return score;

}

std::string &formatScoreWhenGameIsInProgressAndBeforeAdvantage(int p1Score, int p2Score, std::string &score) {
    score = formatScore(score, p1Score);
    score += "-";
    score = formatScore(score, p2Score);

    return score;
}

std::string &formatScore(std::string &score, int tempScore) {
    std::map<int, std::string> scoreToScoreLabel = {
            {0, "Love"},
            {1, "Fifteen"},
            {2, "Thirty"},
            {3, "Forty"}
    };

    score += scoreToScoreLabel[tempScore];

    return score;
}

std::string &formatScoreWhenAPlayerHasAdvantageOrWon(int p1Score, int p2Score, std::string &score) {
    int minusResult = p1Score - p2Score;
    if (minusResult == 1) score = "Advantage player1";
    if (minusResult == -1) score = "Advantage player2";
    if (minusResult >= 2) score = "Win for player1";
    if (minusResult <= -2) score = "Win for player2";
    return score;
}

std::string &formatScoreWhenEqual(int p1Score, std::string &score) {
    switch (p1Score) {
        case 0:
            score = "Love-All";
            break;
        case 1:
            score = "Fifteen-All";
            break;
        case 2:
            score = "Thirty-All";
            break;
        default:
            score = "Deuce";
            break;

    }
    return score;
}
