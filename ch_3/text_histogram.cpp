// A program that tracks how many times
// it has seen a word of input

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	typedef vector<string>::size_type vec_string_sz;
	string x;
	vector<string> word_holder;
	vector<int> word_counter;
	int found_flag = 0;	
	while (cin >> x) {
		if (word_holder.size() == 0) {
			word_holder.push_back(x);
			word_counter.push_back(1);
		} else {
			for (vec_string_sz i = 0; i < word_holder.size(); i++) {
				if (word_holder[i].compare(x) == 0) {
					word_counter[i]++;
					found_flag = 1;
				} 
			}
			if (found_flag == 0) {
				word_holder.push_back(x);
				word_counter.push_back(1);
			}
			found_flag = 0;	
		}
	}

	cout << endl;
	
	// Display results
	for (vec_string_sz i = 0; i < word_holder.size(); i ++) {
		cout << word_holder[i] << "\t" << word_counter[i] << endl;
	}
			
	return 0;

}
