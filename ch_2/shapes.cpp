#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	cout << "Enter the size of the squares: ";
	int size;	 
	cin >> size;

	// Make Square
	string stars_1(size, '*');	
	for (int i = 0; i < size; i++) {
		cout << stars_1;
		cout << endl;
	}

	cout << endl;

	cout << "Enter width: ";
	int width;
	cin >> width;
	
	cout << "Enter length: ";
	int length;
	cin >> length;

	string stars_2(length, '*');
	for (int i = 0; i < width; i++) {
		cout << stars_2;
		cout << endl;
	}

	cout << endl;

	cout << "Enter height: ";
	int height;
	cin >> height;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << "*";	
		}
		cout << endl;
	}

	return 0;

}
