#ifndef JKS_FUNCTIONAL_OPERATORS_H
# define JKS_FUNCTIONAL_OPERATORS_H

namespace jks
{

	template <class T> struct bit_and
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = T;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x & y;
		}

	};

	template <class T> struct bit_od
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = T;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x | y;
		}

	};

	template <class T> struct bit_xor
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = T;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x ^ y;
		}

	};

	template <class T> struct divides
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = T;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x / y;
		}

	};

	template <class T> struct equal_to
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = bool;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x == y;
		}

	};

	template <class T> struct greater
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = bool;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x > y;
		}

	};

	template <class T> struct greater_equal
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = bool;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x >= y;
		}

	};

	template <class T> struct less
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = bool;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x < y;
		}

	};

	template <class T> struct less_equal
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = bool;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x <= y;
		}

	};

	template <class T> struct logical_and
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = bool;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x && y;
		}


	};

	template <class T> struct logical_not
	{

		using argument_type = T;
		using result_type = bool;

		result_type operator () (const argument_type &x) const
		{
			return !x;
		}

	};

	template <class T> struct logical_or
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = bool;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x || y;
		}

	};

	template <class T> struct minus
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = T;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x - y;
		}

	};

	template <class T> struct modulus
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = T;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x % y;
		}

	};

	template <class T> struct multiplies
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = T;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x * y;
		}

	};

	template <class T> struct negate
	{

		using argument_type = T;
		using result_type = T;

		result_type operator () (const argument_type &x) const
		{
			return -x;
		}

	};

	template <class T> struct not_equal_to
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = bool;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x != y;
		}

	};

	template <class T> struct plus
	{

		using first_argument_type = T;
		using second_argument_type = T;
		using result_type = T;

		result_type operator () (const first_argument_type &x, const second_argument_type &y) const
		{
			return x + y;
		}

	};

}

#endif
