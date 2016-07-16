// A program to compute grades
// From Accelerated CPP 3.1
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

int main()
{
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades ";
	double midterm;
	double final;
	cin >> midterm >> final;

	// ask for the homework grades
	cout << "Enter all your homework grades, "
			"followed by end-of-file: ";

	vector<double> homework;	
	double x;
	while (cin >> x) {
		homework.push_back(x);
	}
	
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	
	if (size == 0) {
		cout << endl;
		return 1;
	}

	sort(homework.begin(), homework.end());
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1])/2
						   : homework[mid];

	// write the result
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * median
		 << setprecision(prec) << endl;

	return 0;
}
