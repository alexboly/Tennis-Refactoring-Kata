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

string &formatScoreWhenEqual(int score, string &scoreMessage);

const string tennis_score(int firstPlayerScore, int secondPlayerScore) {
	string score;
	if (firstPlayerScore == secondPlayerScore) {
		score = formatScoreWhenEqual(firstPlayerScore, score);
	} else if (hasAdvantage(firstPlayerScore) || hasAdvantage(secondPlayerScore)) {
		int minusResult = firstPlayerScore - secondPlayerScore;

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
		score = formatScore(firstPlayerScore, secondPlayerScore);
	}
	return score;
}

string &formatScoreWhenEqual(int score, string &scoreMessage) {
	switch (score) {
		case 0:
			scoreMessage = ZERO + SEPARATOR + ALL;
			break;
		case 1:
			scoreMessage = FIFTEEN + SEPARATOR + ALL;
			break;
		case 2:
			scoreMessage = THIRTY + SEPARATOR + ALL;
			break;
		default:
			scoreMessage = DEUCE;
			break;

	}
	return scoreMessage;
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