#ifndef FRED_H
#define FRED_H

#include "bot.hpp"

#define FRED_RECIEVE_MASSAGE "Hi"
#define FRED_SEND_MASSAGE "Hello"

class Fred : public Bot
{
public:
	std::string notify(std::string massage);

private:
	 
};

#endif 