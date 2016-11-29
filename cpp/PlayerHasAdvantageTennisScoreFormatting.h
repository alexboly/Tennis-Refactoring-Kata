//
// Created by alexb on 11/29/16.
//

#ifndef CPP_PLAYERONEHASADVANTAGETENNISSCOREFORMATTING_H
#define CPP_PLAYERONEHASADVANTAGETENNISSCOREFORMATTING_H


#include "ITennisScoreFormattingStrategy.h"

class PlayerHasAdvantageTennisScoreFormatting : public ITennisScoreFormattingStrategy {
public:
	PlayerHasAdvantageTennisScoreFormatting(const int highScorePlayerScore,
		                                           const int lowScorePlayerScore,
		                                           const string playerNameWhoHasAdvantage);

	virtual bool applies() const;

	virtual string apply() const;

private:
	bool hasAdvantage(int playerScore)const { return playerScore >= 4; }

	const int highScorePlayerScore;
	const int lowPlayerScore;
	const string playerNameWhoHasAdvantage;
	static const string ADVANTAGE;
	static const string SEPARATOR_SPACE;

	string formatAdvantageMessage(string playerName)const { return ADVANTAGE + SEPARATOR_SPACE + playerName; }

};


#endif //CPP_PLAYERONEHASADVANTAGETENNISSCOREFORMATTING_H
