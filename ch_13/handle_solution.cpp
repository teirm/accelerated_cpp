// Handle Class for grad and undergrad records

#include "students.cpp"

class Student_info_handle {
public:
	Student_info_handle(): cp(0) { }
	Student_info_handle(std::istream& is): cp(0) { read(is); }
	Student_info_handle(const Student_info_handle&);
	Student_info_handle& operator=(const Student_info_handle&);
	~Student_info_handle() { delete cp; }

	std::istream& read(std::istream&);

	std::string name() const {
		if (cp) return cp->name();
		else throw std::runtime_error("unitialized Student");
	}
	
	double grade() const {
		if (cp) return cp->grade();
		else throw std::runtime_error("unitialized Student");
	}

	static bool compare(const Student_info_handle& s1,
						const Student_info_handle& s2) {
		return s1.name() < s2.name();
	}

	private:
		Core* cp;
};

std::istream& Student_info_handle::read(std::istream& is)
{
	delete cp;

	char ch;
	is >> ch;

	if (ch == 'U') {
		cp = new Core(is);
	} else {
		cp = new Grad(is);
	}

	return is;
}

Student_info_handle::Student_info_handle(const Student_info_handle& s): cp(0)
{
	if (s.cp) cp = s.cp->clone();
}

Student_info_handle& Student_info_handle::operator=(const Student_info_handle& s)
{
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
	return *this;
}

int main()
{
	std::vector<Student_info_handle> students;
	Student_info_handle record;
	std::string::size_type maxlen = 0;

	while (record.read(std::cin)) {
		maxlen = std::max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), Student_info_handle::compare);

	return 0;
}

