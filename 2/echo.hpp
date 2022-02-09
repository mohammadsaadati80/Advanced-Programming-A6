#ifndef ECHO_H
#define ECHO_H
 
#include "bot.hpp"

#define ECHO_SPECIAL_CHARACTER "@&$%*#$%@*&"
#define ECHO_SPECIAL_CHARACTER_SIZE 11

class Echo : public Bot
{
public:
	Echo(std::string dest);
	std::string notify(std::string massage);
	std::string get_dest_channel();

private:
	std::string destination_channel_name;
	 
};

#endif 