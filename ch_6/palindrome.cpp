// checks if a string is a palindrome

#include <algorithm>
#include <string>

using std::string;

bool is_palindrome (const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}
