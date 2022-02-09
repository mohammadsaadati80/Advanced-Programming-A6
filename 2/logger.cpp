#include "logger.hpp"
using namespace std;

Logger::Logger(string _filename)
{
	filename = _filename;
}

string Logger::notify(string massage)
{
	ofstream output(filename.c_str(), ios::app);
	output << massage << endl;
	return MY_NULL_CHARACTER;
}