#ifndef JKS_FUNCTIONAL_HASH_H
# define JKS_FUNCTIONAL_HASH_H

namespace jks
{

	template <class T> struct hash
	{
	};

	template <> struct hash <bool>
	{

		using result_type = size_t;
		using argument_type = bool;

		result_type operator () (argument_type argument)
		{
			return argument;
		}
	};

	template <> struct hash <char>
	{

		using result_type = size_t;
		using argument_type = char;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <signed char>
	{

		using result_type = size_t;
		using argument_type = signed char;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <unsigned char>
	{

		using result_type = size_t;
		using argument_type = unsigned char;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <char16_t>
	{

		using result_type = size_t;
		using argument_type = char16_t;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <char32_t>
	{

		using result_type = size_t;
		using argument_type = char32_t;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <wchar_t>
	{

		using result_type = size_t;
		using argument_type = wchar_t;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <short>
	{

		using result_type = size_t;
		using argument_type = short;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <unsigned short>
	{

		using result_type = size_t;
		using argument_type = unsigned short;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <int>
	{

		using result_type = size_t;
		using argument_type = int;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <unsigned int>
	{

		using result_type = size_t;
		using argument_type = unsigned int;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <long>
	{

		using result_type = size_t;
		using argument_type = long;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <unsigned long>
	{

		using result_type = size_t;
		using argument_type = unsigned long;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <long long>
	{

		using result_type = size_t;
		using argument_type = long long;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <unsigned long long>
	{

		using result_type = size_t;
		using argument_type = unsigned long long;

		result_type operator () (argument_type argument)
		{
			return argument;
		}

	};

	template <> struct hash <void*>
	{

		using result_type = size_t;
		using argument_type = void*;

		result_type operator () (argument_type argument)
		{
			return *reinterpret_cast<result_type*>(&argument);
		}

	};

}

#endif
