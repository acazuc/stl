#ifndef JKS_UNORDERED_MAP_ITERATOR_H
# define JKS_UNORDERED_MAP_ITERATOR_H

# include "iterator.h"
# include "vector.h"
# include "list.h"

namespace jks
{

	template <class T> class unordered_map_iterator : public iterator<forward_iterator_tag, T>
	{

	public:
		using vector_iterator = typename vector<list<T>>::iterator;
		using list_iterator = typename list<T>::iterator;

	private:
		vector_iterator m_vIt;
		list_iterator m_lIt;

	public:
		unordered_map_iterator(vector_iterator vIt, list_iterator lIt)
		: m_vIt(vIt)
		, m_lIt(lIt)
		{
		}

		unordered_map_iterator(vector_iterator vIt)
		: m_vIt(vIt)
		, m_lIt(nullptr)
		{
			//TODO handle m_vIt end()
			while (m_vIt->empty())
				++m_vIt;
			m_lIt = m_vIt->begin();
		}

		unordered_map_iterator(const unordered_map_iterator &it)
		: m_vIt(it.m_vIt)
		, m_lIt(it.m_lIt)
		{
		}

		T &operator * ()
		{
			return *m_lIt;
		}

		T *operator -> ()
		{
			return &(*m_lIt);
		}

		unordered_map_iterator<T> &operator ++ ()
		{
			++m_lIt;
			if (m_lIt == m_vIt->end())
			{
				do
				{
					++m_vIt;
				} while (m_vIt->empty());
				//TODO handle m_vIt end()
				m_lIt = m_vIt->begin();
			}
			return *this;
		}

		unordered_map_iterator<T> operator ++ (int n)
		{
			unordered_map_iterator tmp(*this);
			++(*this);
			return tmp;
		}

		bool operator == (unordered_map_iterator<T> it)
		{
			return m_vIt == it.m_vIt && m_lIt == it.m_lIt;
		}

		bool operator != (unordered_map_iterator<T> it)
		{
			return m_vIt != it.m_vIt || m_lIt != it.m_lIt;
		}

	};

}

#endif
