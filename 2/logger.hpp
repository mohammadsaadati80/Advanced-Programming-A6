#ifndef LOGGER_H
#define LOGGER_H

#include "bot.hpp"

class Logger : public Bot
{
public:
	Logger(std::string filename);
	std::string notify(std::string massage);

private:
	std::string filename;

};

#endif