#ifndef NOT_EXIST_ERROR_H
#define NOT_EXIST_ERROR_H

#include <exception>

#define  NOT_EXIST_ERROR_MESSAGE "Channel does not exist\n"

class NotExistError : public std::exception
{
public:
	const char* what() const throw();
};

#endif