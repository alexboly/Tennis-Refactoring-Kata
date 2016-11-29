#include <string>
#include <vector>
#include <algorithm>
#include "EqualTennisScoreFormatting.h"
#include "PlayerHasAdvantageTennisScoreFormatting.h"
#include "WinnerTennisScoreFormatting.h"
#include "BeforeAdvantagesTennisScoreFormatting.h"

using namespace std;

bool applies(ITennisScoreFormattingStrategy *value) {
	return value->applies();
}

const string tennis_score(int firstPlayerScore, int secondPlayerScore) {
	const string firstPlayerName("player1");
	const string secondPlayerName("player2");

	EqualTennisScoreFormatting equalTennisScoreFormatting(firstPlayerScore, secondPlayerScore);
	PlayerHasAdvantageTennisScoreFormatting firstPlayerHasAdvantageTennisScoreFormatting(
			firstPlayerScore, secondPlayerScore, firstPlayerName);
	WinnerTennisScoreFormatting firstPlayerWinnerScoreFormatting(firstPlayerScore, secondPlayerScore, firstPlayerName);
	PlayerHasAdvantageTennisScoreFormatting secondPlayerHasAdvantageTennisScoreFormatting(
			secondPlayerScore, firstPlayerScore, secondPlayerName);
	WinnerTennisScoreFormatting secondPlayerWinnerScoreFormatting(secondPlayerScore, firstPlayerScore,
	                                                              secondPlayerName);
	BeforeAdvantagesTennisScoreFormatting beforeAdvantagesTennisScoreFormatting(firstPlayerScore, secondPlayerScore);


	vector<ITennisScoreFormattingStrategy *> formattingRules;
	formattingRules.push_back(&equalTennisScoreFormatting);
	formattingRules.push_back(&firstPlayerHasAdvantageTennisScoreFormatting);
	formattingRules.push_back(&firstPlayerWinnerScoreFormatting);
	formattingRules.push_back(&secondPlayerHasAdvantageTennisScoreFormatting);
	formattingRules.push_back(&secondPlayerWinnerScoreFormatting);
	formattingRules.push_back(&beforeAdvantagesTennisScoreFormatting);

	ITennisScoreFormattingStrategy *firstThatApplies = find_if(formattingRules.begin(), formattingRules.end(),
	                                                           applies)[0];
	return firstThatApplies->apply();
}