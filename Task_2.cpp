// Task_2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "AnyType.h"
#include "stdio.h"
#include "BadType.h"


int main()
{
	AnyType a = 1.5F;
	AnyType b = 2;

	std::cout<< a.get_TypeName() << std::endl;
	std::cout<< b.get_TypeName() << std::endl;

	try
	{
		b = a.ToInt();
		std::cout << b;
	}
	catch(BadType& bt)
	{
		std::cout << bt.what() << std::endl;
	}

	b.Swap(b, a);
	std::cout << b;

	system("pause");
    return 0;
}

