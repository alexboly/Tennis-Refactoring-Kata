#include <string>
#include "EqualTennisScoreFormatting.h"
#include "PlayerHasAdvantageTennisScoreFormatting.h"
#include "WinnerTennisScoreFormatting.h"
#include "BeforeAdvantagesTennisScoreFormatting.h"

using namespace std;

const string tennis_score(int firstPlayerScore, int secondPlayerScore) {
	const string firstPlayerName("player1");
	const string secondPlayerName("player2");

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

	BeforeAdvantagesTennisScoreFormatting beforeAdvantagesTennisScoreFormatting(firstPlayerScore, secondPlayerScore);
	if (beforeAdvantagesTennisScoreFormatting.applies()) {
		return beforeAdvantagesTennisScoreFormatting.apply();
	}

	return string();
}
