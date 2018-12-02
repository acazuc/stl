#ifndef JKS_LIST_ITERATOR_H
# define JKS_LIST_ITERATOR_H

# include "list_item.h"
# include "iterator.h"

namespace jks
{

	template <class T> class list_iterator : public iterator<bidirectional_iterator_tag, T>
	{

	private:
		list_item<T> *m_ptr;

	public:
		list_iterator(list_item<T> *ptr)
		: m_ptr(ptr)
		{
		}

		list_iterator(const list_iterator &it)
		: m_ptr(it.m_ptr)
		{
		}

		T &operator * ()
		{
			return m_ptr->data;
		}

		T *operator -> ()
		{
			return &m_ptr->data;
		}

		list_iterator<T> &operator ++ ()
		{
			m_ptr = m_ptr->next;
			return *this;
		}

		list_iterator<T> &operator -- ()
		{
			m_ptr = m_ptr->prev;
			return *this;
		}

		list_iterator<T> operator ++ (int n)
		{
			list_iterator<T> tmp = *this;
			++(*this);
			return tmp;
		}

		list_iterator<T> operator -- (int n)
		{
			list_iterator<T> tmp = *this;
			--(*this);
			return tmp;
		}

		bool operator == (list_iterator<T> it)
		{
			return m_ptr == it.m_ptr;
		}

		bool operator != (list_iterator<T> it)
		{
			return m_ptr != it.m_ptr;
		}

	};

}

#endif
