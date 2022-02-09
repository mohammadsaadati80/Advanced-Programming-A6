#ifndef BOT_H
#define BOT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

#define MY_NULL_CHARACTER ""

class Bot
{
public:
	virtual std::string notify(std::string massage = 0) = 0;

private:

};

#endif 