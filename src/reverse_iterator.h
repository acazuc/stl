#ifndef JKS_REVERSE_ITERATOR_H
# define JKS_REVERSE_ITERATOR_H

# include "iterator.h"

namespace jks
{

	template <class Iterator> class reverse_iterator : public iterator<typename Iterator::iterator_category, typename Iterator::value_type>
	{

	public:
		using iterator_type = Iterator;
		using iterator_category = typename Iterator::iterator_category;
		using value_type = typename Iterator::value_type;
		using difference_type = typename Iterator::difference_type;
		using pointer = typename Iterator::pointer;
		using reference = typename Iterator::reference;

	private:
		iterator_type m_it;

	public:
		reverse_iterator()
		{
		}

		reverse_iterator(iterator_type it)
		: m_it(it)
		{
		}

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it)
		: m_it(rev_it.m_it)
		{
		}

		iterator_type base() const
		{
			iterator_type base = m_it;
			base--;
			return base;
		}

		reference operator * () const
		{
			iterator_type tmp = m_it;
			--tmp;
			return *tmp;
		}

		pointer operator -> () const
		{
			return addressof(operator*());
		}

		reverse_iterator operator + (difference_type n) const
		{
			m_it += n;
			return *this;
		}

		reverse_iterator operator - (difference_type n) const
		{
			m_it -= n;
			return *this;
		}

		reverse_iterator &operator ++ ()
		{
			m_it--;
			return *this;
		}

		reverse_iterator operator ++ (int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		reverse_iterator &operator -- ()
		{
			m_it++;
			return *this;
		}

		reverse_iterator operator -- (int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return tmp;
		}

		reverse_iterator operator += (difference_type n)
		{
			m_it -= n;
			return *this;
		}

		reverse_iterator operator -= (difference_type n)
		{
			m_it += n;
			return *this;
		}

	};

	template <class Iterator1, class Iterator2>
	bool operator == (const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator != (const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator < (const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator <= (const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator > (const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator >= (const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

}

#endif
