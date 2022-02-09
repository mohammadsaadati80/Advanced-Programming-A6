#ifndef CHANNEL_H
#define CHANNEL_h

#include "bot.hpp"
#include "echo.hpp"

struct EchoAnswerResult
{
	std::string destination;
	std::string massage;
};


class Channel
{
public:
	Channel(std::string channel_name);
	std::string get_channel_name();
	void add_new_bot(Bot* new_bot);
	std::vector<EchoAnswerResult> tell_to_bots(std::string massage);
	
private:
	std::vector<Bot*> bots;
	std::string channel_name;

};

#endif 