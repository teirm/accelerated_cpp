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

bool compare(const string& x , const string& y)
{
	return x < y;
}

vector<string> rotate_string(const vector<string>& s_vec, int shifts)
{
	vector<string> ret = s_vec;
	vector<string>::size_type org_size = s_vec.size();
	
	ret.insert(ret.begin(), s_vec.begin() + shifts, s_vec.end());
	ret.erase(ret.begin() + org_size, ret.end());

	return ret;
}	

string unrotate_and_print(const string& s, int separator)
{

	vector<string> fragments;
	vector<string>::size_type i;
	
	fragments = split(s);
	
	string key = "";
	string value;
		
	for (i = 0; i < fragments.size(); i++) {
		if (i < fragments.size() - separator) {
			value += fragments[i];
			value += " ";
		} else {
			key += fragments[i];
			key += " ";
		}			
	}
	return key + "\t" + value;	
}

void print_string_vec(const vector<string>& s_vec) {

	vector<string>::size_type i;
	
	for (i = 0; i < s_vec.size(); i++) {
		cout << s_vec[i] << " ";
	}
	
	cout << endl;
}

int main()
{
	string input;
	string head;	
		
	vector<string> fragments;	
	vector<string> input_strings;
	vector<string> rotations;

	while (cin) {
		getline(cin, input);
		input_strings.push_back(input);	
	}

	cout << endl;

	print_string_vec(input_strings);

	vector<string>::size_type shift_counter;
	
	vector<string> string_fragments = split(input_strings[0]);
	vector<string> perms = string_fragments;	
	vector<string>::size_type original_size = perms.size();

/*	perms.insert(perms.begin(), string_fragments.begin() + 1, string_fragments.end());	

	perms.erase(perms.begin() + original_size, perms.end());
	
	print_string_vec(perms);
*/	
	for (shift_counter = 0; shift_counter < string_fragments.size(); shift_counter++) {
		rotations = rotate_string(string_fragments, shift_counter);
		print_string_vec(rotations);	
	} 

	return 0;
}
