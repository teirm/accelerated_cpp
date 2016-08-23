// Class type version of student info

#include <algorithm>
#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <iomanip>

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
double median(std::vector<double> vec);


class Student_info {
public:
	Student_info();
	Student_info(std::istream&);
	bool valid() const { return !homework.empty(); }
	std::istream& read(std::istream&);
	double grade() const; 
	std::string name() const { return n; }

private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
};

Student_info::Student_info(): midterm(0), final(0) { }
Student_info::Student_info(std::istream& is) { read(is); }

std::istream& Student_info::read(std::istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
	if (in) {
		hw.clear();
		
		double x;
		while (in >> x) {
			hw.push_back(x);
		}
		
		in.clear();
	}
	return in;
}

double grade(double midterm_grade, double final_grade, double homework)
{
	return 0.2 * midterm_grade + 0.4 * final_grade + 0.4 * homework;
}

double grade(double midterm_grade, double final_grade, const std::vector<double>& hw)
{
	if (hw.size() == 0) {
		throw std::domain_error("student has done no homework");
	}
	return grade(midterm_grade, final_grade, median(hw));
}

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}


int main()
{
	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type maxlen = 0;

	// read and store the data
	while (record.read(std::cin)) {
		maxlen = std::max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the name and grades
	for (std::vector<Student_info>::size_type i = 0;
		 i != students.size(); ++i) {
		std::cout << students[i].name() // this and the next line changed
			 << std::string(maxlen + 1 - students[i].name().size(), ' ');
		if (students[i].valid()) {	
			double final_grade = students[i].grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade
				 << std::setprecision(prec) << std::endl;
		} else {
			std::cout << "INVALID ENTRY" << std::endl;
		}
	}
	return 0;
}

