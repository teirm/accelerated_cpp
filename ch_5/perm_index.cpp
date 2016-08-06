// A program to generate permuted indexes of input
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "string_split.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

/* NOTE (6-AUG-16): A really interesting way to
 * keep the index of the shift would be to use
 * a hash map: h(perm) -> index.  Therefore 
 * even on sorting the position of the start
 * would be maintained.  Come back once you
 * cover hashing.
 */


bool compare(const string& x , const string& y)
{
	return x < y;
}

vector<string> rotate_string(const vector<string>& s_vec, int shift)
{
	vector<string> ret = s_vec;
	vector<string>::size_type org_size = s_vec.size();
	
	ret.insert(ret.begin(), s_vec.begin() + shift, s_vec.end());
	ret.erase(ret.begin() + org_size, ret.end());

	return ret;
}	

string vector_to_string(const vector<string>& s_vec)
{
	string ret;	
	vector<string>::size_type i;

	for (i = 0; i < s_vec.size(); i++) {
		ret += s_vec[i];
	
		i < s_vec.size() - 1 ? ret += " ":ret += "";
	}

	return ret;
}

void print_str_vec(const vector<string>& s_vec) {

	vector<string>::size_type i;
	
	for (i = 0; i < s_vec.size(); i++) {
		cout << s_vec[i] << " ";
	}
	
	cout << endl;
}

int main()
{
	string input;
		
	vector<string> input_strings;
	vector<string> rotation;
	vector<string> permutations;

	while (cin) {
		getline(cin, input);
		input_strings.push_back(input);	
	}

	cout << endl;

	vector<string>::size_type shift;
	
	vector<string> str_fragments = split(input_strings[0]);

	for (shift = 0; shift < str_fragments.size(); shift++) {
		rotation = rotate_string(str_fragments, shift);
		cout << vector_to_string(rotation) << endl;	
	} 

	return 0;
}
