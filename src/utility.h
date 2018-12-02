#ifndef JKS_UTILITY_H
# define JKS_UTILITY_H

namespace jks
{

	template <class T1, class T2> struct pair
	{

		using first_type = T1;
		using second_type = T2;

		first_type first;
		second_type second;

	};

}

#endif
