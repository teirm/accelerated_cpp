#include <fstream>
#include <string>
#include <iostream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;
using std::cout;

int main(int argc, char **argv)
{
	int fail_count = 0;
	// for each file in the input list
	for (int i = 1; i < argc; ++i) {
		ifstream in(argv[i]);

		if (in) {
			string s;
			while (getline(in, s))
				cout << s << endl;
		} else {
			cerr << "cannot open file " << argv[i] << endl;
			++fail_count;
		}
	}
	return fail_count;
}

