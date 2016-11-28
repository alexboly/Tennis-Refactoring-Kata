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

string formatScoreNotEqualBeforeAdvantages(int p1Score, int p2Score);

const string formatScoreWhenEqual(const int score);

string formatScoreWhenNotEqualDuringAdvantages(int firstPlayerScore, int secondPlayerScore);

const string tennis_score(int firstPlayerScore, int secondPlayerScore) {
	string score;
	const bool scoreIsEqual = (firstPlayerScore == secondPlayerScore);
	const bool scoreNotEqualDuringAdvantages = (firstPlayerScore != secondPlayerScore) &&
	                                           (hasAdvantage(firstPlayerScore) || hasAdvantage(secondPlayerScore));
	const bool scoreNotEqualBeforeAdvantages = (firstPlayerScore != secondPlayerScore) &&
	                                           !(hasAdvantage(firstPlayerScore) || hasAdvantage(secondPlayerScore));

	if (scoreIsEqual) {
		score = formatScoreWhenEqual(firstPlayerScore);
	}

	if (scoreNotEqualDuringAdvantages) {
		score = formatScoreWhenNotEqualDuringAdvantages(firstPlayerScore, secondPlayerScore);
	}

	if (scoreNotEqualBeforeAdvantages) {
		score = formatScoreNotEqualBeforeAdvantages(firstPlayerScore, secondPlayerScore);
	}

	return score;
}

string formatScoreWhenNotEqualDuringAdvantages(int firstPlayerScore, int secondPlayerScore) {
	int minusResult = firstPlayerScore - secondPlayerScore;

	const char *firstPlayerName = "player1";
	const char *secondPlayerName = "player2";

	if (minusResult == 1) {
		return formatAdvantageMessage(firstPlayerName);
	}
	if (minusResult == -1) {
		return formatAdvantageMessage(secondPlayerName);
	}
	if (minusResult >= 2) {
		return formatWinMessage(firstPlayerName);
	}
	if (minusResult <= -2) {
		return formatWinMessage(secondPlayerName);
	}
	return string();
}

const string formatScoreWhenEqual(const int score) {
	switch (score) {
		case 0:
			return ZERO + SEPARATOR + ALL;
		case 1:
			return FIFTEEN + SEPARATOR + ALL;
		case 2:
			return THIRTY + SEPARATOR + ALL;
		default:
			return DEUCE;

	}
}

string formatScoreNotEqualBeforeAdvantages(int p1Score, int p2Score) { return scoreToString(p1Score) + SEPARATOR + scoreToString(p2Score); }

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