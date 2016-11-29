//
// Created by alexb on 11/29/16.
//

#ifndef CPP_EQUALTENNISSCOREFORMATTING_H
#define CPP_EQUALTENNISSCOREFORMATTING_H


#include "ITennisScoreFormattingStrategy.h"

class EqualTennisScoreFormatting : public ITennisScoreFormattingStrategy{
public:
	EqualTennisScoreFormatting(int firstPlayerScore, int secondPlayerScore);

	virtual bool applies() const;

	virtual string apply() const;

private:
	int firstPlayerScore;
	int secondPlayerScore;

	static const string ZERO;
	static const string FIFTEEN;
	static const string THIRTY;
	static const string SEPARATOR;
	static const string ALL;
	static const string DEUCE;
};
#endif //CPP_EQUALTENNISSCOREFORMATTING_H
