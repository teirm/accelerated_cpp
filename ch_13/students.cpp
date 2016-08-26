// Classes for chapter 13

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../ch_4/Student_info.h"
#include "../ch_4/grade.h"

class Core {
public:
	virtual ~Core();
	Core(): midterm(0), final(0) { }
	Core(std::istream& is) { read(is); } 
	std::string name() const;
	virtual std::istream& read(std::istream&);
	virtual	double grade() const;
protected:
	std::istream& read_common(std::istream&);
	std::vector<double> homework;
	double midterm, final;
private:
	std::string n;
};

class Grad: public Core {
public:
	Grad(): thesis(0) { };
	Grad(std::istream& is) { read(is); };
	double grade() const;
	std::istream& read(std::istream&);
private:
	double thesis;
};

std::string Core::name() const { return n; }
double Core::grade() const
{
	return ::grade(midterm, final, homework);
}

std::istream& Core::read_common(std::istream& in)
{
	// read and store the students name and exam grades
	in >> n >> midterm >> final;
	return in;
}

std::istream& Core::read(std::istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}

std::istream& Grad::read(std::istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade() const
{
	return std::min(Core::grade(), thesis);
}

bool compare(const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}
