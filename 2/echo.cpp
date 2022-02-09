#include "echo.hpp"
using namespace std;

Echo::Echo( string _dest)
{
	destination_channel_name = _dest;
}

string Echo::notify(string massage)
{
	return ECHO_SPECIAL_CHARACTER + destination_channel_name;
}

string Echo::get_dest_channel() { return destination_channel_name; }