#include "SameNameError.hpp"
using namespace std;

const char* SameNameError::what() const throw()
{
	return SAME_NAME_ERROR_MESSAGE;
}