// Algorithmic way to classify students

#include <algorithm>
#include <vector>
#include <string>

#include "../ch_4/Student_info.h"

using std::vector;

bool pgrade(const Student_info& s);
bool fgrade(const Student_info& s);

vector<Student_info> extract_fails(vector<Student_info>& students);

vector<Student_info>
mp_extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	remove_copy_if(students.begin(), students.end(),
				   back_inserter(fail), pgrade);
	students.erase(remove_if(students.begin(), students.end(), fgrade),
				   students.end());
	return fail;	
}

vector<Student_info>
sp_extract_fails(vector<Student_info>& students) {
	vector<Student_info>::iterator iter = 
		stable_partition(students.begin(), students.end(), pgrade);
	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());

	return fail;
}
