#include "EqualTennisScoreFormatting.h"

const string EqualTennisScoreFormatting::ZERO = "Love";
const string EqualTennisScoreFormatting::FIFTEEN = "Fifteen";
const string EqualTennisScoreFormatting::THIRTY = "Thirty";
const string EqualTennisScoreFormatting::SEPARATOR = "-";
const string EqualTennisScoreFormatting::ALL = "All";
const string EqualTennisScoreFormatting::DEUCE = "Deuce";

EqualTennisScoreFormatting::EqualTennisScoreFormatting(int firstPlayerScore, int secondPlayerScore) : firstPlayerScore(
		firstPlayerScore), secondPlayerScore(secondPlayerScore) {}

bool EqualTennisScoreFormatting::applies() const {
	return firstPlayerScore == secondPlayerScore;
}

string EqualTennisScoreFormatting::apply() const {
	switch (firstPlayerScore) {
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
