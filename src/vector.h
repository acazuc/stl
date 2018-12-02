#ifndef JKS_VECTOR_H
# define JKS_VECTOR_H

# include "reverse_iterator.h"
# include "vector_iterator.h"
# include "allocator.h"
# include "stdexcept.h"

namespace jks
{

	template <class T, class Alloc = allocator<T>> class vector
	{

	public:
		using value_type = T;
		using allocator_type = Alloc;
		using reference = T&;
		using const_reference = const T&;
		using pointer = typename allocator_type::pointer;
		using const_pointer = typename allocator_type::const_pointer;
		using iterator = vector_iterator<value_type>;
		using const_iterator = vector_iterator<const value_type>;
		using reverse_iterator = jks::reverse_iterator<iterator>;
		using const_reverse_iterator = jks::reverse_iterator<const_iterator>;
		using size_type = size_t;

	private:
		allocator_type m_allocator;
		size_type m_capacity;
		size_type m_size;
		pointer m_data;

	public:
		vector()
		: m_data(nullptr)
		, m_capacity(0)
		, m_size(0)
		{
		}

		vector(size_type n)
		: m_data(nullptr)
		, m_capacity(0)
		, m_size(0)
		{
			resize(n);
		}

		void reserve(size_type n)
		{
			if (n <= capacity())
				return;
			pointer new_data = m_allocator.allocate(n);
			for (size_type i = 0; i < size() * sizeof(*data()); ++i)
				new_data[i] = data()[i];
			m_allocator.deallocate(data(), size());
			m_data = new_data;
			m_capacity = n;
		}

		void resize(size_type n)
		{
			if (n <= size())
			{
				for (size_type i = size(); i > n; --i)
					m_allocator.destroy(&data()[i]);
				m_size = n;
				return;
			}
			reserve(n);
			for (size_type i = size(); i < n; ++i)
				m_allocator.construct(&data()[i]);
			m_size = n;
		}

		void resize(size_type n, const value_type &val)
		{
			if (n <= size())
			{
				m_size = n;
				return;
			}
			reserve(n);
			for (size_type i = size(); i < n; ++i)
				m_data[i] = val;
			this->m_size = n;
		}

		void shrink_to_fit()
		{
			//TODO
		}

		void push_back(reference val)
		{
			size_type tmp = size();
			resize(size() + 1);
			m_data[tmp] = val;
		}

		void pop_back()
		{
			if (!size())
				return;
			resize(size() - 1);
		}

		void clear()
		{
			resize(0);
		}

		void swap(vector &v)
		{
			pointer *tmp_data = m_data;
			size_type tmp_size = m_size;
			size_type tmp_capacity = m_capacity;
			allocator_type tmp_allocator = m_allocator;
			m_data = v.m_data;
			m_size = v.m_size;
			m_capacity = v.m_capacity;
			m_allocator = v.m_allocator;
			v.m_data = tmp_data;
			v.m_size = tmp_size;
			v.m_capacity = tmp_capacity;
			v.m_allocator = tmp_allocator;
		}

		reference operator [] (size_type n)
		{
			return m_data[n];
		}

		const_reference operator [] (size_type n) const
		{
			return m_data[n];
		}

		reference at(size_type n)
		{
			if (n >= size())
				throw out_of_range("Nope");
			return m_data[n];
		}

		const_reference at(size_type n) const
		{
			if (n >= size())
				throw out_of_range("Nope");
			return m_data[n];
		}

		reference front()
		{
			return m_data[0];
		}

		const_reference front() const
		{
			return m_data[0];
		}

		reference back()
		{
			return m_data[size() - 1];
		}

		const_reference back() const
		{
			return m_data[size() - 1];
		}

		iterator begin()
		{
			return iterator(data());
		}

		iterator end()
		{
			return iterator(data() + size());
		}

		const_iterator cbegin()
		{
			return const_iterator(data());
		}

		const_iterator cend()
		{
			return const_iterator(data() + size());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator crbegin()
		{
			return const_reverse_iterator(cend());
		}

		const_reverse_iterator crend()
		{
			return const_reverse_iterator(cbegin());
		}

		pointer data()
		{
			return m_data;
		}

		size_type size() const noexcept
		{
			return m_size;
		}

		size_type max_size() const noexcept
		{
			return 0x3FFFFFFF;
		}

		size_type capacity() const noexcept
		{
			return m_capacity;
		}

		bool empty() const noexcept
		{
			return size() == 0;
		}

	};

}

#endif
