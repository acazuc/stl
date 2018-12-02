#ifndef JKS_ARRAY_H
# define JKS_ARRAY_H

# include "array_iterator.h"

namespace jks
{

	template <class T, size_t N> class array
	{

	public:
		using value_type = T;
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;
		using iterator = array_iterator<T>;
		using const_iterator = array_iterator<const T>;
		using reverse_iterator = jks::reverse_iterator<iterator>;
		using const_reverse_iterator = jks::reverse_iterator<const_iterator>;
		using size_type = size_t;
		using difference_type = ptrdiff_t;

	private:
		value_type m_data[N];

	public:
		iterator begin()
		{
			return iterator(m_data);
		}

		iterator end()
		{
			return iterator(m_data + N);
		}

		const_iterator cbegin()
		{
			return const_iterator(m_data);
		}

		const_iterator cend()
		{
			return const_iterator(m_data + N);
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

		constexpr size_type size() noexcept
		{
			return N;
		}

		constexpr size_type max_size() noexcept
		{
			return 0x3FFFFFF;
		}

		constexpr bool empty() noexcept
		{
			return size() == 0;
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
			if (n > size())
				return out_of_range("Nope");
			return m_data[n];
		}

		const_reference at(size_type n) const
		{
			if (n > size())
				return out_of_range("nope");
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
			return m_data[N - 1];
		}

		const_reference back() const
		{
			return m_data[N - 1];
		}

		value_type *data() noexcept
		{
			return m_data;
		}

		const value_type *data() const noexcept
		{
			return m_data;
		}

		void fill(const value_type &val)
		{
			for (size_type i = 0; i < N; ++i)
				m_data[i] = val;
		}

	};

}

#endif
