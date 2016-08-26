// Exercise to determine which function is called

#include "students.cpp"

int main()
{
	Core* p1 = new Core;
	Core* p2 = new Grad;
	Core s1;
	Grad s2;

	p1->grade();
	p1->name();

	p2->grade();
	p2->name();

	s1.grade();
	s1.name();

	s2.name();
	s2.grade();

	return 0;
}
