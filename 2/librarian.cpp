#include "librarian.hpp"
using namespace std;

Librarian::Librarian()
{
	number_of_massage_recive = 0;
}

string Librarian::notify(string massage)
{
	number_of_massage_recive += 1;
	if (number_of_massage_recive == NUMBER_OF_SEND_MASSAGE)
		number_of_massage_recive = 0;
	if (number_of_massage_recive % NUMBER_OF_SEND_MASSAGE == 0)
		return LIBRARIAN_SEND_MASSAGE;
	else
		return MY_NULL_CHARACTER;
}