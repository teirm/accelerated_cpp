// A program that will print the quartiles
// of a set of numbers given as input
#include <string>
#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main()
{
	typedef vector<double>::size_type vec_sz;
	vector<double> numb_array;
	double x;
	
	while (cin >> x) {
		numb_array.push_back(x);
	}
	
	vec_sz size = numb_array.size();	
	
	if (size == 0) {
		cout << endl;
		return 1;
	}

	//sort array
	sort(numb_array.begin(), numb_array.end());

	vec_sz mid = size/2;
	double q2 = size % 2 == 0 ? (numb_array[mid] + numb_array[mid-1])/2
							  : numb_array[mid];

	vec_sz one_quarter = mid/2;
	double q1 = size % 4 == 0 ? (numb_array[one_quarter] + numb_array[one_quarter - 1])/2
							  : numb_array[one_quarter];

	vec_sz three_quarter = one_quarter + mid;
	double q3 = size % 4 == 0 ? (numb_array[three_quarter] + numb_array[three_quarter - 1])/2
							  : numb_array[three_quarter];

	cout << endl;
	cout << "Q1: " << q1 << endl;
	cout << "Q2: " << q2 << endl;
	cout << "Q3: " << q3 << endl;
	
	return 0;
}

