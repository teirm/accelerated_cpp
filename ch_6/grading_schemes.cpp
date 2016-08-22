// Comparison of student grades

#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <numeric>

#include "../ch_4/Student_info.h"
#include "../ch_4/grade.h"
#include "../ch_4/median.h"

using std::vector;
using std::string;
using std::domain_error;
using std::endl;
using std::cin;
using std::cout;
using std::ostream;

bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0))
		   == s.homework.end());
}

double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm_grade, s.final_grade, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(),
			  back_inserter(grades), average_grade);
	return median(grades);
}

double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm_grade, s.final_grade, 0);
	}
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(),
			  back_inserter(grades), grade_aux);
	return median(grades);
}

// median of the nonzero elemens of s.homework or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(),
				back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm_grade, s.final_grade, 0);
	else
		return grade(s.midterm_grade, s.final_grade, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(),
			  back_inserter(grades), optimistic_median);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
				   ", median(didnt) = " << analysis(didnt) << endl;
}

int main()
{
	// students who did and didn't do all their homework
	vector<Student_info> did;
	vector<Student_info> didnt;

	Student_info student;
	while (read(cin, student)) {
		if (did_all_hw(student)) {
			did.push_back(student);
		} else {
			didnt.push_back(student);
		}
	}

	// verify that the analyses will show us something
	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}

	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;	
	}

	// do the analyses
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "median", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in",
			       optimistic_median_analysis, did, didnt);
	
	return 0;
}

