// Exercise 8.3

#include <vector>
#include <iostream>

#include "iterator_types.cpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

template <class In>
void print_vec(In beg, In end)
{
	while (beg != end) {
		cout << *beg++ << endl;
	}
}	 


int main()
{
	int x;
	vector<int> input;
	
	while (cin >> x)
		input.push_back(x);

	cout << "Before Reverse" << endl;
	print_vec(input.begin(), input.end());

	reverse(input.begin(), input.end());

	cout << "After Reverse" << endl;
	print_vec(input.begin(), input.end());

	return 0;	
}			

