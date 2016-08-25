// A class that implements an array of strings

#include <string>
#include <iostream>

using std::cout;
using std::endl;

#define MAX_SZ 10

class Pig {
	private:
		int current_sz;
		std::string items[MAX_SZ];
	public:
		Pig();
		Pig(std::string *inventory, int n);
	
		void add_item(std::string s);
		int get_inv_sz() const { return current_sz; };
		const std::string* get_inv() const { return items; };
};


Pig::Pig(): current_sz(0) {}

Pig::Pig(std::string *inventory, int n)
{
	Pig::current_sz = 0;

	for (int i = 0; i < n && i < MAX_SZ; i++) {
		Pig::items[i] = inventory[i];
		Pig::current_sz++;		
	}
}

void Pig::add_item(std::string s)
{
	int size = Pig::get_inv_sz();	
	
	if (size < MAX_SZ) {
		Pig::items[size] = s;
		Pig::current_sz++;
	} else {
		cout << "INVENTORY FULL" << endl;
	}
}


void print_inventory(const Pig& p)
{
	int size = p.get_inv_sz();
	const std::string* inventory = p.get_inv();

	for (int i = 0; i < size; i++) {
		cout << inventory[i] << endl;
	}
}

int main(int argc, char** argv)
{
	Pig pig_a;

	cout << pig_a.get_inv_sz() << endl;
	
	pig_a.add_item("Knife");
	pig_a.add_item("Belt");
	
	cout << pig_a.get_inv_sz() << endl;

	print_inventory(pig_a);
	
	std::string init_inventory[] = {"Rod",
								    "Hat",
								    "Boots"};

	int init_size = sizeof(init_inventory)/sizeof(*init_inventory);
	
	Pig pig_b(init_inventory, init_size);

	print_inventory(pig_b);
	
	return 0;
}
