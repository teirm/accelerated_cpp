// Counting word count with associative arrays

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

int main()
{
	string s;
	map<string, int> counters;	// store each word and an associated counter

	// read the input, keeping track of each word and how often we see it
	while (cin >> s) {
		++counters[s];
	}

	for (map<string, int>::const_iterator it = counters.begin();
		 it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}
	
	return 0;
}
