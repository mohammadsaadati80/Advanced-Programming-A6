#ifndef SAME_NAME_ERROR_H
#define SAME_NAME_ERROR_H

#include <exception>

#define SAME_NAME_ERROR_MESSAGE "Source and destination cannot be the same channel\n"

class SameNameError : public std::exception
{
public:
	const char* what() const throw();
};

#endif 