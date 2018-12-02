#ifndef JKS_ARRAY_ITERATOR_H
# define JKS_ARRAY_ITERATOR_H

# include "iterator.h"

namespace jks
{

	template <class T> class array_iterator : public iterator<random_access_iterator_tag, T>
	{

	public:
		using iterator_category = random_access_iterator_tag;
		using value_type = T;
		using difference_type = ptrdiff_t;
		using pointer = T*;
		using reference = T&;

	private:
		pointer m_ptr;

	public:
		array_iterator(pointer ptr)
		: m_ptr(ptr)
		{
		}

		array_iterator(const array_iterator &it)
		: m_ptr(it.m_ptr)
		{
		}

		reference operator * ()
		{
			return *m_ptr;
		}

		pointer operator -> ()
		{
			return m_ptr;
		}

		array_iterator<T> &operator ++ ()
		{
			m_ptr++;
			return *this;
		}

		array_iterator<T> &operator -- ()
		{
			m_ptr--;
			return *this;
		}

		array_iterator<T> operator ++ (int)
		{
			array_iterator<T> tmp = *this;
			++(*this);
			return tmp;
		}

		array_iterator<T> operator -- (int)
		{
			array_iterator<T> tmp = *this;
			--(*this);
			return tmp;
		}

		array_iterator<T> operator + (difference_type n)
		{
			return array_iterator<T>(m_ptr + n);
		}

		array_iterator<T> operator - (difference_type n)
		{
			return array_iterator<T>(m_ptr - n);
		}

		array_iterator<T> &operator += (difference_type n)
		{
			m_ptr += n;
			return *this;
		}

		array_iterator<T> &operator -= (difference_type n)
		{
			m_ptr -= n;
			return *this;
		}

		bool operator == (array_iterator<T> it)
		{
			return m_ptr == it.m_ptr;
		}

		bool operator != (array_iterator<T> it)
		{
			return m_ptr != it.m_ptr;
		}

		bool operator < (array_iterator<T> it)
		{
			return m_ptr < it.m_ptr;
		}

		bool operator > (array_iterator<T> it)
		{
			return m_ptr > it.m_ptr;
		}

		bool operator <= (array_iterator<T> it)
		{
			return m_ptr <= it.m_ptr;
		}

		bool operator >= (array_iterator<T> it)
		{
			return m_ptr >= it.m_ptr;
		}

	};

}

#endif
