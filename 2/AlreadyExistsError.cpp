#include "AlreadyExistsError.hpp"
using namespace std;

const char* AlreadyExistsError::what() const throw()
{
	return ALREADY_EXISTS_ERROR_MESSAGE;
}