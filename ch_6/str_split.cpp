// Chapter 6 Program to split strings

#include <cctype>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::isspace;
using std::string;

bool space (char c)
{
	return isspace(c);
}

bool not_space (char c)
{
	return !isspace(c);
}

vector<string> split (const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end()) {

		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find end of next word 
		iter j = find_if(i, str.end(), space);

		// copy the characters in [i, j)
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;

	}
	return ret;
}
