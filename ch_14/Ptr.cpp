// A class to allow user to have some control of Ref_handle

#include <stdexcept>
#include <vector>

template <class T> T* clone(const T* tp)
{
	return tp->clone();
}

template<>
std::vector<char>* clone(const std::vector<char>* vp)
{
	return new std::vector<char>(*vp);
}

template <class T> class Ptr {
public:

	// new member to copy the object conditionally when needed
	void make_unique() {
		if (*refptr != 1) {
			--*refptr;
			refptr = new size_t(1);
			p = p? p->clone() : 0;
		}
	}

	// manage reference count as well as pointer
	Ptr(): p(0), refptr(new std::size_t(1)) { }
	Ptr(T* t): p(t), refptr(new std::size_t(1)) { }
	Ptr(const Ptr& h): p(h.p), refptr(h.refptr) {
		++*refptr;
	}
	Ptr& operator=(const Ptr&);
	~Ptr();

	operator bool() const { return p; }
	T& operator*() const {
		if (p)
			return *p;
		throw std::runtime_error("Unbounded Ptr");
	}

	T* operator->() const {
		if (p)
			return p;
		throw std::runtime_error("unbound Ptr");
	}

private:
	T* p;
	std::size_t* refptr;
};

template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
	++*rhs.refptr;
	// free the left hand size destroying pointers if appropriate
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}

	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template <class T> Ptr<T>::~Ptr()
{
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}
}
