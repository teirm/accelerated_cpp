// Pirvate classes for use in implementation only

#include "Ptr.cpp"
#include <string>
#include <cstddef>

class Picture;

class Pic_base {
	// no public interface (except for destructor)
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;

	virtual wd_sz width() const = 0;
	virtual ht_sz height() const = 0;
	virtual void display(std::ostream&, ht_sz, bool) const = 0;

public:
	virtual ~Pic_base() { }
};

class String_Pic: public Pic_base {

	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;
	
	std::vector<std::string> data;
	String_Pic(const std::vector<std::string>& v): data(v) { }

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};

class Frame_Pic: public Pic_base {

	friend Picture frame(const Picture& pic);
	
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;
	
	Ptr<Pic_base> p;
	Frame_Pic(const Ptr<Pic_base>& pic): p(pic) { }
	
	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;	
};

class VCat_Pic: public Pic_base {

	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;

	Ptr<Pic_base> top, bottom;
	VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b):
		top(t), bottom(b) { }
	
	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};
	
class HCat_Pic: public Pic_base {
	
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;
	
	Ptr<Pic_base> left, right;
	HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r):
		left(l), right(r) { }
	
	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};

// Public interface class and operations
class Picture {
friend Picture frame(const Picture& pic);

public:
	Picture(const std::vector<std::string>& = 
		std::vector<std::string>());
private:
	Ptr<Pic_base> p;
	Picture(Pic_base* ptr): p(ptr) { }
};

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

Picture frame(const Picture& pic)
{
	return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r)
{
	return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
	return new VCat_pic(t.p, b.p);
}

Picture::Picture(const vector<string>& v): p(new String_Pic(v)) { }


