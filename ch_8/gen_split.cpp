// Generic Split

#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;

using std::string;
using std::vector;

template <class Out>
void split (const string& str, Out os) {

	typedef string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end()) {

		i = find_if(i, str.end(), not_space);

		iter j = find_if(i, str.end(), space);

		if (i != str.end())
			*os++ = string(i, j); // changed

		i = j;
	}
}

int main()
{
	string s;

	while (getline(cin, s))
		split(s, ostream_iterator<string>(cout, "\n"));
	return 0;
}
