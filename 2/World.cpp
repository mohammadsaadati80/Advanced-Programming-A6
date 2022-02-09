#include "World.hpp"
using namespace std;

void World::check_command()
{
	string command;
	while (cin >> command)
	{
		if (command == ADD_CHANNEL_COMMAND)
		{
			string name;
			cin >> name;
			create_new_channel(name);
		}
		if (command == ADD_BOT_COMMAND)
		{
			string bot_type;
			cin >> bot_type;
			if (bot_type == ECHO_COMMAND)
			{
				string source;
				string destination;
				cin >> source;
				cin >> destination;
				add_new_echo(source, destination);
			}
			if (bot_type == LOGGER_COMMAND)
			{
				string filename;
				cin >> filename;
				add_new_logger(filename);
			}
			if (bot_type == FRED_COMMAND)
			{
				string channel;
				cin >> channel;
				add_new_fred(channel);
			}
			if (bot_type == LIBRARIAN_COMMAND)
			{
				string channel;
				cin >> channel;
				add_new_librarian(channel);
			}
		}
		if (command == TELL_COMMAND)
		{
			string channel_name;
			string massage;
			string input_massage;
			cin >> channel_name;
			getline(cin, input_massage);
			for (int current = 1; current < input_massage.size(); current++)
				massage.push_back(input_massage[current]);
			tell_to_bots_of_channel(channel_name, massage);
		}
	}
}

void World::create_new_channel(string channel_name)
{
	try
	{
		if (find_channel(channel_name) != ALREADY_EXIST_CHANNEL)
			throw AlreadyExistsError();
		Channel new_channel(channel_name);
		channels.push_back(channel_name);
	} 
	catch (AlreadyExistsError& error)
	{
		cerr << error.what();
	}
}

int World::find_channel(string channel_name)
{
	for (int current = 0; current < channels.size(); current++)
		if (channels[current].get_channel_name() == channel_name)
			return current;
	return NOT_FOUND_CHANNEL;
}

void World::add_new_echo(std::string source, std::string destination)
{
	try
	{
		if (source == destination)
			throw SameNameError();
		if (find_channel(source) == NOT_FOUND_CHANNEL)
			throw NotExistError();
		if (find_channel(destination) == NOT_FOUND_CHANNEL)
			throw NotExistError();
		
		Echo* new_echo = new Echo(destination);
		channels[find_channel(source)].add_new_bot(new_echo);
	}
	catch (SameNameError& error)
	{
		cerr << error.what();
	}
	catch (NotExistError& error)
	{
		cerr << error.what();
	}
}

void World::add_new_logger(std::string filename)
{
	Logger* new_logger = new Logger(filename);
	for (int current = 0; current < channels.size(); current++)
		channels[current].add_new_bot(new_logger);
}

void World::add_new_fred(std::string channel)
{
	try
	{
		if (find_channel(channel) == NOT_FOUND_CHANNEL)
			throw NotExistError();
		Fred* new_fred = new Fred;
		channels[find_channel(channel)].add_new_bot(new_fred);
	}
	catch (NotExistError& error)
	{
		cerr << error.what();
	}
}

void World::add_new_librarian(std::string channel)
{
	try
	{
		if (find_channel(channel) == NOT_FOUND_CHANNEL)
			throw NotExistError();
		Librarian* new_librarian = new Librarian;
		channels[find_channel(channel)].add_new_bot(new_librarian);
	}
	catch (NotExistError& error)
	{
		cerr << error.what();
	}
}

void World::tell_to_bots_of_channel(std::string channel_name, std::string massage)
{
	try
	{
		if (find_channel(channel_name) == NOT_FOUND_CHANNEL)
			throw NotExistError();
		vector<EchoAnswerResult> channel_answer_result = channels[find_channel(channel_name)].tell_to_bots(massage);
		if (channel_answer_result.size() != EMPTY) 
			for(int current = 0; current < channel_answer_result.size(); current++)
				tell_to_bots_of_channel(channel_answer_result[current].destination, channel_answer_result[current].massage);
	}
	catch (NotExistError& error)
	{
		cerr << error.what();
	}
}