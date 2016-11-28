#include <string>

using namespace std;

static const string ZERO = "Love";
static const string FIFTEEN = "Fifteen";
static const string THIRTY = "Thirty";
static const string FORTY = "Forty";
static const string SEPARATOR = "-";
static const string ALL = "All";
static const string DEUCE = "Deuce";

static const string ADVANTAGE = "Advantage";

static const string WIN = "Win for";

static const string SEPARATOR_SPACE = " ";

bool hasAdvantage(int playerScore);

string formatAdvantageMessage(string playerName);

string formatWinMessage(string playerName);

string scoreToString(int score);

string formatScore(int p1Score, int p2Score);

const string tennis_score(int p1Score, int p2Score) {
	string score;
	if (p1Score == p2Score) {
		switch (p1Score) {
			case 0:
				score = ZERO + SEPARATOR + ALL;
				break;
			case 1:
				score = FIFTEEN + SEPARATOR + ALL;
				break;
			case 2:
				score = THIRTY + SEPARATOR + ALL;
				break;
			default:
				score = DEUCE;
				break;

		}
	} else if (hasAdvantage(p1Score) || hasAdvantage(p2Score)) {
		int minusResult = p1Score - p2Score;

		const char *firstPlayerName = "player1";
		const char *secondPlayerName = "player2";

		if (minusResult == 1) {
			score = formatAdvantageMessage(firstPlayerName);
		}
		if (minusResult == -1) {
			score = formatAdvantageMessage(secondPlayerName);
		}
		if (minusResult >= 2) {
			score = formatWinMessage(firstPlayerName);
		}
		if (minusResult <= -2) {
			score = formatWinMessage(secondPlayerName);
		}
	} else {
		score = formatScore(p1Score, p2Score);
	}
	return score;
}

string formatScore(int p1Score, int p2Score) { return scoreToString(p1Score) + SEPARATOR + scoreToString(p2Score); }

string scoreToString(int score) {
	switch (score) {
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

string formatAdvantageMessage(string playerName) { return ADVANTAGE + SEPARATOR_SPACE + playerName; }

bool hasAdvantage(int playerScore) { return playerScore >= 4; }

string formatWinMessage(string playerName) {
	return WIN + SEPARATOR_SPACE + playerName;
}