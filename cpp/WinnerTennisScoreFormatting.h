//
// Created by alexb on 11/29/16.
//

#ifndef CPP_WINNERTENNISSCOREFORMATTING_H
#define CPP_WINNERTENNISSCOREFORMATTING_H


#include "ITennisScoreFormattingStrategy.h"

class WinnerTennisScoreFormatting : public ITennisScoreFormattingStrategy {
public:
	WinnerTennisScoreFormatting(int firstPlayerScore, int secondPlayerScore, const string &firstPlayerName);

	virtual bool applies() const;

	virtual string apply() const;

private:
	int firstPlayerScore;
	int secondPlayerScore;
	string firstPlayerName;

	bool hasAdvantage(int playerScore) const { return playerScore >= 4; }


	static const string WIN;
	static const string SEPARATOR_SPACE;
};


#endif //CPP_WINNERTENNISSCOREFORMATTING_H
