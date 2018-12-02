#ifndef JKS_ITERATOR_H
# define JKS_ITERATOR_H

#include <cstddef>

namespace jks
{

	struct input_iterator_tag
	{
	};

	struct forward_iterator_tag : public input_iterator_tag
	{
	};

	struct bidirectional_iterator_tag : public forward_iterator_tag
	{
	};

	struct random_access_iterator_tag : public bidirectional_iterator_tag
	{
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&> class iterator
	{

	public:
		using iterator_category = Category;
		using value_type = T;
		using difference_type = Distance;
		using pointer = Pointer;
		using reference = Reference;

	};

}

#endif
