#ifndef WORLD_H
#define WORLD_H

#include "bot.hpp"
#include "channel.hpp"
#include "logger.hpp"
#include "echo.hpp"
#include "fred.hpp"
#include "librarian.hpp"
#include "AlreadyExistsError.hpp"
#include "NotExistError.hpp"
#include "SameNameError.hpp"

#define ADD_CHANNEL_COMMAND "add_channel"
#define ADD_BOT_COMMAND "add_bot"
#define FRED_COMMAND "fred"
#define ECHO_COMMAND "echo"
#define LIBRARIAN_COMMAND "librarian"
#define LOGGER_COMMAND "logger"
#define TELL_COMMAND "tell"
#define NOT_FOUND_CHANNEL -1
#define ALREADY_EXIST_CHANNEL -1
#define EMPTY 0

class World
{
public:
	void check_command();
	void create_new_channel(std::string channel_name);
	int find_channel(std::string channel_name);
	void add_new_echo(std::string src, std::string dest);
	void add_new_logger(std::string filename);
	void add_new_fred(std::string channel);
	void add_new_librarian(std::string channel);
	void tell_to_bots_of_channel(std::string channel_name, std::string massage);

private:
	std::vector<Channel> channels;

};

#endif 