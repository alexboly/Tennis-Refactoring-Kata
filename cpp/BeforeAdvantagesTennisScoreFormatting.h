//
// Created by alexb on 11/29/16.
//

#ifndef CPP_BEFOREADVANTAGESTENNISSCOREFORMATTING_H
#define CPP_BEFOREADVANTAGESTENNISSCOREFORMATTING_H


#include "ITennisScoreFormattingStrategy.h"

class BeforeAdvantagesTennisScoreFormatting : public ITennisScoreFormattingStrategy {
public:
	BeforeAdvantagesTennisScoreFormatting(const int firstPlayerScore, const int secondPlayerScore);

	virtual bool applies() const;

	virtual string apply() const;

private:
	const int firstPlayerScore;
	const int secondPlayerScore;

	bool hasAdvantage(int playerScore)const { return playerScore >= 4; }

	string scoreToString(int score) const;

	static const string ZERO;
	static const string FIFTEEN;
	static const string THIRTY;
	static const string FORTY;
	static const string SEPARATOR;
};


#endif //CPP_BEFOREADVANTAGESTENNISSCOREFORMATTING_H
