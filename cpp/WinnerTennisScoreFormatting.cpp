//
// Created by alexb on 11/29/16.
//

#include "WinnerTennisScoreFormatting.h"

const string WinnerTennisScoreFormatting::WIN = "Win for";
const string WinnerTennisScoreFormatting::SEPARATOR_SPACE = " ";


WinnerTennisScoreFormatting::WinnerTennisScoreFormatting(int firstPlayerScore, int secondPlayerScore,
                                                         const string &firstPlayerName) : firstPlayerScore(
		firstPlayerScore), secondPlayerScore(secondPlayerScore), firstPlayerName(firstPlayerName) {}

bool WinnerTennisScoreFormatting::applies() const {
	return (hasAdvantage(firstPlayerScore) || hasAdvantage(secondPlayerScore)) &&
	       firstPlayerScore - secondPlayerScore >= 2;
}

string WinnerTennisScoreFormatting::apply() const {
	return WIN + SEPARATOR_SPACE + firstPlayerName;
}
