#pragma once

#include <exception>

class WrongType : public std::exception
{
public:
	const char* what() const throw() { return "Bad types!"; }
};
