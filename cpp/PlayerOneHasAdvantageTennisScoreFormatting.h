//
// Created by alexb on 11/29/16.
//

#ifndef CPP_PLAYERONEHASADVANTAGETENNISSCOREFORMATTING_H
#define CPP_PLAYERONEHASADVANTAGETENNISSCOREFORMATTING_H


#include "ITennisScoreFormattingStrategy.h"

class PlayerOneHasAdvantageTennisScoreFormatting : public ITennisScoreFormattingStrategy {
public:
	PlayerOneHasAdvantageTennisScoreFormatting(const int firstPlayerScore,
		                                           const int secondPlayerScore,
		                                           const string firstPlayerName);

	virtual bool applies() const;

	virtual string apply() const;

private:
	bool hasAdvantage(int playerScore)const { return playerScore >= 4; }

	const int firstPlayerScore;
	const int secondPlayerScore;
	const string firstPlayerName;
	static const string ADVANTAGE;
	static const string SEPARATOR_SPACE;

	string formatAdvantageMessage(string playerName)const { return ADVANTAGE + SEPARATOR_SPACE + playerName; }

};


#endif //CPP_PLAYERONEHASADVANTAGETENNISSCOREFORMATTING_H
