// Exercise to determine which function is called

#include "students.cpp"

int main()
{
	Core* p1 = new Core;
	Core* p2 = new Grad;
	Core s1;
	Grad s2;

	std::cout << "p1" << std::endl;
	// Core functions
	p1->grade();
	p1->name();

	std::cout << "p2" << std::endl;
	// Grad Function
	p2->grade();
	// Core Function
	p2->name();


	std::cout << "s1" << std::endl;
	// Core Functions
	s1.grade();
	// Core Function
	s1.name();

	std::cout << "s2" << std::endl;
	// Core Function
	s2.name();
	// Grad Function
	s2.grade();

	return 0;
}
