#include "AnyType.h"
#include "WrongType.h"


int main()
{
	AnyType at1(true);

	at1 = 3.1415;
	std::cout << "Holder 1: " << at1 << std::endl;

	try
	{
		int i = at1.get_Int();
	}
	catch (WrongType& wt)
	{
		std::cout << wt.what() << std::endl;
	}


	at1 = (unsigned char)'a';
	AnyType at2(90.1f);

	std::cout << "Before swapping:\n" << "Holder 1: " << at1 << std::endl;
	std::cout << "Holder 2: " << at2 << std::endl;

	AnyType::Swap(at1, at2);

	std::cout << "After swapping:\n" << "Holder 1: " << at1 << std::endl;
	std::cout << "Holder 2: " << at2 << std::endl;

	AnyType at3(std::move(at2));
	at3 = std::move(at1);

	std::cout << "After moving \n Holder 3: " << at3 << std::endl;
	std::cout << "Holder 2: " << at2 << std::endl;

	system("pause");
	return 0;
}