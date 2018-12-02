#ifndef JKS_ALLOCATOR_H
# define JKS_ALLOCATOR_H

# include "stdexcept.h"
# include "utility.h"
# include <cstdlib>
# include <cstddef>

namespace jks
{

	template <class T> class allocator
	{

	public:
		using value_type = T;
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;
		using size_type = size_t;
		using difference_type = ptrdiff_t;

		allocator() noexcept
		{
		}

		allocator(allocator &alloc) noexcept
		{
		}

		~allocator()
		{
		}

		pointer allocate(size_type n, const void *hint = 0)
		{
			(void)hint;
			pointer p = reinterpret_cast<pointer>(malloc(sizeof(value_type) * n));
			if (!p)
				throw exception();
			return p;
		}

		void deallocate(pointer p, size_type n)
		{
			free(p);
		}

		template <class U, class... Args>
		void construct(U val, Args&&... args)
		{
			new ((void*)val) U(args...);
		}

		void destroy(pointer p)
		{
			p->~value_type();
		}

	};

}

#endif
