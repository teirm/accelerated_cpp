// Separate passing and failing student records
#include <vector>
#include "../ch_4/grade.cpp"

using std::vector;


bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();	

	// invariant: elements [0, i) of students represent passing grades
	while (iter != students.end()) {	
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);	
		} else {
			++iter;	
		}
	}
	return fail;
}
