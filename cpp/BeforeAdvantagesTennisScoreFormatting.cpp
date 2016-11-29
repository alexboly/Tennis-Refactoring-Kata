//
// Created by alexb on 11/29/16.
//

#include "BeforeAdvantagesTennisScoreFormatting.h"

const string BeforeAdvantagesTennisScoreFormatting::ZERO = "Love";
const string BeforeAdvantagesTennisScoreFormatting::FIFTEEN = "Fifteen";
const string BeforeAdvantagesTennisScoreFormatting::THIRTY = "Thirty";
const string BeforeAdvantagesTennisScoreFormatting::FORTY = "Forty";
const string BeforeAdvantagesTennisScoreFormatting::SEPARATOR = "-";

BeforeAdvantagesTennisScoreFormatting::BeforeAdvantagesTennisScoreFormatting(const int firstPlayerScore,
                                                                             const int secondPlayerScore)
		: firstPlayerScore(firstPlayerScore), secondPlayerScore(secondPlayerScore) {}

bool BeforeAdvantagesTennisScoreFormatting::applies() const {
	return (firstPlayerScore != secondPlayerScore) &&
	       !(hasAdvantage(firstPlayerScore) || hasAdvantage(secondPlayerScore));
}

string BeforeAdvantagesTennisScoreFormatting::apply() const {
	return scoreToString(firstPlayerScore) + SEPARATOR + scoreToString(secondPlayerScore);
}

string BeforeAdvantagesTennisScoreFormatting::scoreToString(int score) const {
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