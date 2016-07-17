// A small program that computes the square of the inpu
#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() 
{
	vector<int> n_array;
	int input;
	while (cin >> input) {
		n_array.push_back(input);
	}
	
	cout << endl;

	vector<int>::size_type  i;
	for (i = 0; i < n_array.size(); i++) {
		cout << n_array[i] << "\t" <<  n_array[i] * n_array[i] << endl;
	}
	
	return 0;
}
