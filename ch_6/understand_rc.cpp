// Understanding remove_copy function

#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

void print_int_vec(const vector<int>& v) {

	typedef vector<int>::size_type vec_sz; 
	
	for (vec_sz i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	
	cout << endl;	

}

int main()
{
	int x;
	vector<int> input;
	vector<int> remove_bin;
	

	while (cin >> x) {
		input.push_back(x);
	}

	cout << "Before remove_copy" << endl;
	print_int_vec(input);
	
	remove_copy(input.begin(), input.end(),
				back_inserter(remove_bin), 0);

	cout << "After remove_copy" << endl;
	print_int_vec(input);

	cout << "Remove_bin" << endl;
	print_int_vec(remove_bin); 


	return 0;	

}
