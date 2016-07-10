// Exercises from chapter 1
#include <iostream>
#include <string>

int main()
{
	// Ex1-1, 1-2	
	const std::string hello = "Hello";
	const std::string message = hello + ", world" + "!";

	// Ex1-3		
	{ 
		const std::string s = "a string";
		std::cout << s << std::endl;
	}

	{
		const std::string s = "another string";
		std::cout << s << std::endl;
	}

	// Ex1-4
	{ 
		const std::string s = "a string";
		std::cout << s << std::endl;
		{
			const std::string s = "another string";
			std::cout << s << std::endl;
		}
	}

	// Ex1-5
	//	{
	//		std::string s = "a string";
	//		{
	//			std::string x = s + ", really";
	//			std::cout << s << std::endl;
	//		}
	//		std::cout << x << std::endl; //scope error
	//	}

	//Ex 1-6
	{
		std::cout << "What is your name? ";
		std::string name;
		std::cin >> name;
		std::cout << "Hello, " << name
				  << std::endl << "And what is yours? ";
		std::cin >> name;
		std::cout << "Hello, " << name 
				  << "; nice to meet your too!" << std::endl;
	}

	return 0;
}
