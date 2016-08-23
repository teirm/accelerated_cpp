// Types of iterators

// SEQUENTIAL READ ONLY
template <class In, class X> In find(In begin, In end, const X& x)
{
	while (begin != end && *begin != x)
		++begin;
	return begin;
}

// SEQUENTIAL WRITE ONLY 
template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;
	return dest;
}

// SEQUENTIAL READ-WRITE
template <class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
	while (beg != end) {
		if (*beg == x)
			*beg = y;
		++beg;
	}
}

// REVERSIBLE ACCESS
template <class Bi> void reverse(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

// RANDOM ACCESS
template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
	while (begin < end) {
		Ran mid = begin + (end - begin) / 2;

		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		else return true;
	}
	return false;
}
