#ifndef ALREADY_EXISTS_ERROR_H
#define ALREADY_EXISTS_ERROR_H

#include <exception>

#define  ALREADY_EXISTS_ERROR_MESSAGE "Channel already exists\n"

class AlreadyExistsError : public std::exception
{
public:
	const char* what() const throw();
};

#endif