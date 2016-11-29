//
// Created by alexb on 11/29/16.
//

#include "PlayerOneHasAdvantageTennisScoreFormatting.h"

const string PlayerOneHasAdvantageTennisScoreFormatting::ADVANTAGE = "Advantage";
const string PlayerOneHasAdvantageTennisScoreFormatting::SEPARATOR_SPACE = " ";

PlayerOneHasAdvantageTennisScoreFormatting::PlayerOneHasAdvantageTennisScoreFormatting(const int firstPlayerScore,
                                                                                       const int secondPlayerScore,
                                                                                       const string firstPlayerName)
		: firstPlayerScore(firstPlayerScore), secondPlayerScore(secondPlayerScore), firstPlayerName(firstPlayerName) {}

bool PlayerOneHasAdvantageTennisScoreFormatting::applies() const {
	return (hasAdvantage(firstPlayerScore) || hasAdvantage(secondPlayerScore)) &&
	       firstPlayerScore - secondPlayerScore == 1;
}

string PlayerOneHasAdvantageTennisScoreFormatting::apply() const {
	return formatAdvantageMessage(firstPlayerName);
}
