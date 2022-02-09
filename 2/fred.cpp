#include "fred.hpp"
using namespace std;

string Fred::notify(string massage)
{
	if (massage == FRED_RECIEVE_MASSAGE)
		return FRED_SEND_MASSAGE;
	else
		return MY_NULL_CHARACTER;
}