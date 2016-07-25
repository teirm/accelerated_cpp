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

string rotate_string(const string& s)
{
	vector<string> fragments;
	string head_fragment;
	string ret;
		
	fragments = split(s);
	head_fragment = fragments[0];
	
	fragments.erase(fragments.begin(), fragments.begin()+1);
	fragments.push_back(head_fragment);	

	vector<string>::size_type i;
	for (i = 0; i < fragments.size(); i++) {
		ret += fragments[i];
		ret += " ";
	}
	
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

int main()
{
	string input;
	string perm;
	string head;	
		
	vector<string> fragments;	
	vector<string> input_strings;
	vector<string> rotations;
	
	while (cin) {
		getline(cin, input);
		input_strings.push_back(input);	
	}

	cout << endl;
	
	vector<string>::size_type i, j;
	perm = input_strings[0];
	for (i = 0; i < input_strings.size(); i++) {
		fragments = split(input_strings[i]);
		for (j = 0; j < fragments.size(); j++) {
			perm = rotate_string(perm);
			rotations.push_back(perm);
		}
	}
	
	// Can look at original to see how it was supposed to be :D
	sort(rotations.begin(), rotations.end(), compare);

	cout << "Key\tValue" << endl << endl;
	for (i = 0; i < rotations.size(); i++) {
		cout << rotations[i] << endl;	
	}
	return 0;
}
