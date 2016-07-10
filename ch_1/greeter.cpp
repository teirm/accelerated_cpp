// Ask a person's name and greet the person
#include <iostream>
#include <string>

int main()
{
	// ask for person's name
	std::cout << "Please enter your first name: ";

	// read the name
	std::string name;		// define the name
	std::cin >> name;		// read into name

	// build the message that we intend to write
	const std::string greeting = "Hello, " + name + "!";

	// build the second and forth lines of the output
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";

	// build the first and the fifth lines of the output
	const std::string first(second.size(), '*');

	// write everything
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;

	return 0;
}



