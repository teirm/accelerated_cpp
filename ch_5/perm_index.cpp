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

vector<string> rotate_string(const vector<string>& s_vec, int shift)
{
	vector<string> ret = s_vec;
	vector<string>::size_type org_size = s_vec.size();
	
	ret.insert(ret.begin(), s_vec.begin() + shift, s_vec.end());
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

	vector<string>::size_type shift;
	
	vector<string> str_fragments = split(input_strings[0]);
	vector<string> perms = str_fragments;	
	vector<string>::size_type original_size = perms.size();

	for (shift = 0; shift < str_fragments.size(); shift++) {
		rotations = rotate_string(str_fragments, shift);
		print_string_vec(rotations);	
	} 

	return 0;
}
