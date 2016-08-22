// counting line positions 

#include <vector>
#include <iostream>
#include <string>
#include <map>

#include "../ch_6/str_split.cpp"

using std::map;
using std::string;
using std::vector;

using std::cin;
using std::cout;
using std::endl;
using std::istream;

// find all the liens that refer to each word in the input
map<string, vector<int> >
xref(istream& in,
	 vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	// read the next line
	while (getline(in, line)) {
		++line_number;
		
		// break the input line into words
		vector<string> words = find_words(line);

		// remember that each word occurs on the current line
		for (vector<string>::const_iterator it = words.begin();
			 it != words.end(); ++it) {
			ret[*it].push_back(line_number);
		}
	}
	return ret;
}

int main()
{
	// call xref using split by default
	map<string, vector<int> > ret = xref(cin);

	// write the results
	for (map<string, vector<int> >::const_iterator it = ret.begin();
		 it != ret.end(); ++it) {

		cout << it-> first << " occurs on line(s): ";

		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it;

		++line_it;

		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}

		cout <<endl;
	}
	return 0;
}
