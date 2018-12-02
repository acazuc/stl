#ifndef JKS_LIST_H
# define JKS_LIST_H

# include "reverse_iterator.h"
# include "list_iterator.h"
# include "allocator.h"

namespace jks
{

	template <class T, class Alloc = allocator<T>> class list
	{

	public:
		using value_type = T;
		using allocator_type = Alloc;
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;
		using iterator = list_iterator<T>;
		using const_iterator = list_iterator<const T>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;
		using size_type = size_t;

	private:
		allocator_type m_allocator;
		list_item<T> *m_first;
		list_item<T> *m_last;
		size_type m_size;

	public:
		list()
		: m_first(nullptr)
		, m_last(nullptr)
		, m_size(0)
		{
			//Empty
		}

		~list()
		{
			list_item<T> *item = m_first;
			while (item)
			{
				list_item<T> *tmp = item->next;
				m_allocator.destroy(item);
				m_allocator.deallocate(item);
				item = tmp;
			}
		}

		void push_back(reference val)
		{
			list_item<T> *item = m_allocator.allocate(1);
			m_allocator.construct(item, val, m_last, nullptr);
			if (m_last)
				m_last->next = item;
			m_last = item;
			if (!m_first)
				m_first = item;
			m_size++;
		}

		void push_front(reference val)
		{
			list_item<T> *item = m_allocator.allocate(1);
			m_allocator.construct(item, val, nullptr, m_first);
			if (m_first)
				m_first->prev = item;
			m_first = item;
			if (!m_last)
				m_last = item;
			m_size++;
		}

		void pop_back()
		{
			if (!m_last)
				return;
			list_item<T> *item = m_last;
			m_last = item->prev;
			if (m_first == item)
				m_first = nullptr;
			m_allocator.destroy(item);
			m_size--;
		}

		void pop_front()
		{
			if (!m_first)
				return;
			list_item<T> *item = m_first;
			m_first = item->next;
			if (m_last == item)
				m_last = nullptr;
			m_allocator.destroy(item);
			m_size--;
		}

		reference front()
		{
			return *m_first->data;
		}

		const_reference front() const
		{
			return *m_first->data;
		}

		reference back()
		{
			return *m_last->data;
		}

		const_reference back() const
		{
			return *m_last->data;
		}

		iterator begin()
		{
			return iterator(m_first);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

		const_iterator cbegin()
		{
			return const_iterator(m_first);
		}

		const_iterator cend()
		{
			return const_iterator(nullptr);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		reverse_iterator crbegin()
		{
			return reverse_iterator(cend());
		}

		reverse_iterator crend()
		{
			return reverse_iterator(cbegin());
		}

		bool empty() const noexcept
		{
			return size() == 0;
		}

		size_type size() const noexcept
		{
			return m_size;
		}

		size_type max_size() const noexcept
		{
			return 0x3FFFFFFF;
		}

		allocator_type get_allocator() const noexcept
		{
			return m_allocator;
		}

	};

}

#endif
