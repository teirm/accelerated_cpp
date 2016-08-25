// Converts numeric grades to letters

#include <string>
#include <cstddef>

using std::string;

string letter_grade(double grade)
{
	// range posts for numeric grades
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	// names for the letter grades
	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-",
		 "C+", "C", "C-", "D", "F"
	};
	
	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

	// given a numeric, find and return the associated letter grade
	for (size_t i = 0; i < ngrades; ++i) {
		if (grade >= numbers[i])
			return letters[i];
	}
	
	return "?\?\?";	
				
	
}

