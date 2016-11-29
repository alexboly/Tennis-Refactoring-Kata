//
// Created by alexb on 11/29/16.
//

#ifndef CPP_ITENNISSCOREFORMATTINGSTRATEGY_H
#define CPP_ITENNISSCOREFORMATTINGSTRATEGY_H

#include <string>
using namespace std;

class ITennisScoreFormattingStrategy {

public:
	virtual bool applies() const = 0;

	virtual string apply() const = 0;
};


#endif //CPP_ITENNISSCOREFORMATTINGSTRATEGY_H
