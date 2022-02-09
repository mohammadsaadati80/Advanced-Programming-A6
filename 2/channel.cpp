#include "channel.hpp"
using namespace std;

Channel::Channel(string _channel_name)
{
	channel_name = _channel_name;
}

string Channel::get_channel_name() { return channel_name; }

void Channel::add_new_bot(Bot* new_bot)
{
	bots.push_back(new_bot);
}

vector<EchoAnswerResult> Channel::tell_to_bots(string massage)
{
	vector<EchoAnswerResult> channel_answer_result;
	for (int current = 0; current < bots.size(); current++)
	{
		string bot_answer = bots[current]->notify(massage);
		if (bot_answer != MY_NULL_CHARACTER)
		{
			if (bot_answer.substr(0,ECHO_SPECIAL_CHARACTER_SIZE) == ECHO_SPECIAL_CHARACTER)
			{
				string echo_bot_answer_result;
				for (int current = ECHO_SPECIAL_CHARACTER_SIZE; current < bot_answer.size();current++)
					echo_bot_answer_result.push_back(bot_answer[current]);
				EchoAnswerResult new_echo_result;
				new_echo_result.destination = echo_bot_answer_result;
				new_echo_result.massage = massage;
				channel_answer_result.push_back(new_echo_result);
			}
			else
			{
				vector<EchoAnswerResult> result = tell_to_bots(bot_answer);
				for (int current = 0; current < result.size(); current++)
					channel_answer_result.push_back(result[current]);
			}
		}
	}
	return channel_answer_result;
}