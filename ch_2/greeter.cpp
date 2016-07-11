#include <iostream>
#include <string>

//What standard library names we use
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	// Ask for the person's name
	cout << "Please enter your first name: ";

	// Read in the name
	string name;
	cin >> name;

	// build the message that we intend to write
	const string greeting = "Hello, " + name + "!";
	cout << endl;	
	
	// the number of blanks surround the greeting
	// Exercise 2-1 pad = 0
	// Exercise 2-3 
	cout << "Please enter amout of padding: ";
	string::size_type pad;
	cin >> pad;
	cout << endl;

	// the number of rows and columns to write
	const unsigned int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	//Write a blank line to separate the output from the input
	cout << endl;
	
	// write rows rows of output
	// invariant: we have written r rows so far
	for (unsigned int r = 0; r != rows; ++r) {
		
		string::size_type c = 0;
		
		while (c != cols) {
			
			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			} else {

				if (r == 0 || r == rows - 1 ||
					c == 0 || c == cols - 1) {
					cout << "*";
					++c;			
				} else if (r != pad + 1 && c != pad + 1) {
					string spaces(greeting.size() + pad * 2, ' ');
					cout << spaces;
					c += greeting.size() + pad * 2;
				} else {
					cout << " ";
					c++;
				}	
			}

		}
		cout << endl;
	}

	return 0;
}
