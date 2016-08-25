// Using basic pointers

#include <iostream>

using std::endl;
using std::cout;

int main()
{
	typedef double (*analysis_fp)(const int&);

	int x = 5;

	// p points to x
	int* p = &x;
	cout << "x = " << x << endl;

	// change the value of x through p
	*p = 6;
	cout << "x = " << x << endl;
	return 0;
}
