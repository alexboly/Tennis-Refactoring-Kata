//
// Created by alexb on 11/29/16.
//

#include "PlayerHasAdvantageTennisScoreFormatting.h"

const string PlayerHasAdvantageTennisScoreFormatting::ADVANTAGE = "Advantage";
const string PlayerHasAdvantageTennisScoreFormatting::SEPARATOR_SPACE = " ";

PlayerHasAdvantageTennisScoreFormatting::PlayerHasAdvantageTennisScoreFormatting(const int highScorePlayerScore,
                                                                                 const int lowScorePlayerScore,
                                                                                 const string playerNameWhoHasAdvantage)
		: highScorePlayerScore(highScorePlayerScore), lowPlayerScore(lowScorePlayerScore), playerNameWhoHasAdvantage(playerNameWhoHasAdvantage) {}

bool PlayerHasAdvantageTennisScoreFormatting::applies() const {
	return (hasAdvantage(highScorePlayerScore) || hasAdvantage(lowPlayerScore)) &&
	       highScorePlayerScore - lowPlayerScore == 1;
}

string PlayerHasAdvantageTennisScoreFormatting::apply() const {
	return formatAdvantageMessage(playerNameWhoHasAdvantage);
}
