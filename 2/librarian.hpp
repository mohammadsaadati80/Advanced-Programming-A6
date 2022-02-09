#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "bot.hpp"

#define LIBRARIAN_SEND_MASSAGE "Quiet!"
#define NUMBER_OF_SEND_MASSAGE 5

class Librarian : public Bot
{
public:
	Librarian();
	std::string notify(std::string massage);

private:
	int number_of_massage_recive;

};



#endif 
