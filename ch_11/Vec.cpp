// Self implementation of vector class as
// Vec

#include <cstddef>
#include <memory>

template <class T> class Vec {
public:
	Vec& operator=(const Vec&);	
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	~Vec() { uncreate(); }

	typedef T* iterator;
	typedef const T* const_iterator;	
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;
	
	Vec() { create(); }
	explicit Vec(size_type n, const_reference val = T()) { create(n, val); }

	size_type size() const { return avail - data; }
	T& operator[] (size_type i) { return data[i]; }
	const T& operator[] (size_type i) const { return data[i]; }	

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	void push_back (const T& val) {
		if (avail == limit)		// get space if needed
			grow();
		unchecked_append(val);	// append the new element
	}

private:
	// implementation
	iterator data;
	iterator limit;
	iterator avail;

	std::allocator<T> alloc; // object to handle memory allocation
	
	void create();
	void create(size_type, const T&);
	void create(const_iterator,const_iterator);

	void uncreate();

	void grow();
	void unchecked_append(const T&);
};


template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	// check for self-assignment
	if (&rhs != this) {

		// free the array in the lhs
		uncreate();

		// copy elements from the rhs to lhs
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T> void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val);
}

template<class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate()
{
	if (data) {
		// destroy (in reverse order) the elements that were constructed
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		// return all the space that was allocated
		alloc.deallocate(data, limit - data);
	}

	data = limit = avail = 0;
}


template <class T> void Vec<T>::grow()
{
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = unitialized_copy(data, avail, new_data);
	
	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}


template <class T> void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}
