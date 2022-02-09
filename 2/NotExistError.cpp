#include "NotExistError.hpp"
using namespace std;

const char* NotExistError::what() const throw()
{
	return NOT_EXIST_ERROR_MESSAGE;
}