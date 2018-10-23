template <typename V> class vector_iterator : public random_access_iterator_tag
{
	T *ptr;
	vector_iterator(T *ptr) : ptr(ptr) {};
	T &operator * ()
	{
		return *this->ptr;
	}
	T *operator -> ()
	{
		return this->ptr;
	}
	vector_iterator<T> &operator ++ ()
	{
		this->ptr++;
	}
	vector_iterator<T> &operator -- ()
	{
		this->ptr--;
	}
	vector_iterator<T> operator ++ (int n)
	{
		(void)n;
		return vector_iterator<T>(this->ptr + 1);
	}
	vector_iterator<T> operator -- (int n)
	{
		(void)n;
		return vector_iterator<T>(this->ptr - 1);
	}
	vector_iterator<T> operator + (int n)
	{
		return vector_iterator<T>(this->ptr + n);
	}
	vector_iterator<T> operator - (int n)
	{
		return vector_iterator<T>(this->ptr - n);
	}
	vector_iterator<T> &operator += (int n)
	{
		this->ptr += n;
		return *this;
	}
	vector_iterator<T> &operator -= (int n)
	{
		this->ptr -= n;
		return *this;
	}
	bool operator == (vector_iterator<T> iter)
	{
		return this->ptr == iter->ptr;
	}
	bool operator != (vector_iterator<T> iter)
	{
		return this->ptr != iter->ptr;
	}
	bool operator < (vector_iterator<T> iter)
	{
		return this->ptr < iter->ptr;
	}
	bool operator > (vector_iterator<T> iter)
	{
		return this->ptr > iter->ptr;
	}
	bool operator <= (vector_iterator<T> iter)
	{
		return this->ptr <= iter->ptr;
	}
	bool operator >= (vector_iterator<T> iter)
	{
		return this->ptr >= iter->ptr;
	}
};
