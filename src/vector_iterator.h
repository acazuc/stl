#ifndef JKS_VECTOR_ITERATOR_H
# define JKS_VECTOR_ITERATOR_H

# include "iterator.h"

namespace jks
{

	template <class T> class vector_iterator : public iterator<random_access_iterator_tag, T>
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
		vector_iterator(pointer ptr)
		: m_ptr(ptr)
		{
		}

		/*vector_iterator(vector_iterator &it)
		: m_ptr(it.m_ptr)
		{
		}*/

		reference operator * ()
		{
			return *m_ptr;
		}

		pointer operator -> ()
		{
			return m_ptr;
		}

		vector_iterator<T> &operator ++ ()
		{
			m_ptr++;
			return *this;
		}

		vector_iterator<T> &operator -- ()
		{
			m_ptr--;
			return *this;
		}

		vector_iterator<T> operator ++ (int)
		{
			vector_iterator<T> tmp = *this;
			++(*this);
			return tmp;
		}

		vector_iterator<T> operator -- (int)
		{
			vector_iterator<T> tmp = *this;
			--(*this);
			return tmp;
		}

		vector_iterator<T> operator + (difference_type n)
		{
			return vector_iterator<T>(m_ptr + n);
		}

		vector_iterator<T> operator - (difference_type n)
		{
			return vector_iterator<T>(m_ptr - n);
		}

		vector_iterator<T> &operator += (difference_type n)
		{
			m_ptr += n;
			return *this;
		}

		vector_iterator<T> &operator -= (difference_type n)
		{
			m_ptr -= n;
			return *this;
		}

		bool operator == (vector_iterator<T> it)
		{
			return m_ptr == it.m_ptr;
		}

		bool operator != (vector_iterator<T> it)
		{
			return m_ptr != it.m_ptr;
		}

		bool operator < (vector_iterator<T> it)
		{
			return m_ptr < it.m_ptr;
		}

		bool operator > (vector_iterator<T> it)
		{
			return m_ptr > it.m_ptr;
		}

		bool operator <= (vector_iterator<T> it)
		{
			return m_ptr <= it.m_ptr;
		}

		bool operator >= (vector_iterator<T> it)
		{
			return m_ptr >= it.m_ptr;
		}

	};

}

#endif
