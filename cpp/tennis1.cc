#include <string>
#include "EqualTennisScoreFormatting.h"
#include "PlayerHasAdvantageTennisScoreFormatting.h"
#include "WinnerTennisScoreFormatting.h"

using namespace std;

static const string ZERO = "Love";
static const string FIFTEEN = "Fifteen";
static const string THIRTY = "Thirty";
static const string FORTY = "Forty";
static const string SEPARATOR = "-";

static const string WIN = "Win for";

static const string SEPARATOR_SPACE = " ";

bool hasAdvantage(int playerScore);

string formatWinMessage(string playerName);

string scoreToString(int score);

string formatScoreNotEqualBeforeAdvantages(int p1Score, int p2Score);

const string tennis_score(int firstPlayerScore, int secondPlayerScore) {
	const string firstPlayerName("player1");
	const string secondPlayerName("player2");
	const bool scoreNotEqualBeforeAdvantages = (firstPlayerScore != secondPlayerScore) &&
	                                           !(hasAdvantage(firstPlayerScore) || hasAdvantage(secondPlayerScore));

	EqualTennisScoreFormatting equalTennisScoreFormatting(firstPlayerScore, secondPlayerScore);
	if (equalTennisScoreFormatting.applies()) {
		return equalTennisScoreFormatting.apply();
	}

	PlayerHasAdvantageTennisScoreFormatting firstPlayerHasAdvantageTennisScoreFormatting(
			firstPlayerScore, secondPlayerScore, firstPlayerName);
	if (firstPlayerHasAdvantageTennisScoreFormatting.applies()) {
		return firstPlayerHasAdvantageTennisScoreFormatting.apply();
	}


	WinnerTennisScoreFormatting firstPlayerWinnerScoreFormatting(firstPlayerScore, secondPlayerScore, firstPlayerName);
	if (firstPlayerWinnerScoreFormatting.applies()) {
		return firstPlayerWinnerScoreFormatting.apply();
	}

	PlayerHasAdvantageTennisScoreFormatting secondPlayerHasAdvantageTennisScoreFormatting(
			secondPlayerScore, firstPlayerScore, secondPlayerName);
	if (secondPlayerHasAdvantageTennisScoreFormatting.applies()) {
		return secondPlayerHasAdvantageTennisScoreFormatting.apply();
	}

	WinnerTennisScoreFormatting secondPlayerWinnerScoreFormatting(secondPlayerScore, firstPlayerScore,
	                                                              secondPlayerName);

	if (secondPlayerWinnerScoreFormatting.applies()) {
		return secondPlayerWinnerScoreFormatting.apply();
	}

	if (scoreNotEqualBeforeAdvantages) {
		return formatScoreNotEqualBeforeAdvantages(firstPlayerScore, secondPlayerScore);
	}

	return string();
}

string formatScoreNotEqualBeforeAdvantages(int p1Score, int p2Score) {
	return scoreToString(p1Score) + SEPARATOR + scoreToString(p2Score);
}

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

bool hasAdvantage(int playerScore) { return playerScore >= 4; }

string formatWinMessage(string playerName) {
	return WIN + SEPARATOR_SPACE + playerName;
}