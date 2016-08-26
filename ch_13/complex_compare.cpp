#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "students.cpp"


using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::domain_error;
using std::string;
using std::streamsize;
using std::setprecision;

bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
	return compare(*cp1, *cp2);
}

int main()
{
	std::vector<Core*> students;
	Core* record;
	char ch;
	std::string::size_type maxlen = 0;

	// read and store the data
	while (cin >> ch) {
		if (ch == 'U')
			record = new Core;
		else
			record = new Grad;
		record->read(cin);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare_Core_ptrs);

	for (vector<Core*>::size_type i = 0;
		 i != students.size(); ++i) {
		cout << students[i]->name()
			 << string(maxlen + 1 - students[i]->name().size(), ' ');
		try {
			double final_grade = students[i]->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec) << endl;

		} catch (domain_error e) {
			cout << e.what() << endl;
		}
		delete students[i];
	}
	return 0;

}
