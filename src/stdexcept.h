#ifndef JKS_STDEXCEPT_H
# define JKS_STDEXCEPT_H

# include "string.h"

namespace jks
{

	class exception
	{

	public:
		exception() noexcept
		{
		}

		virtual ~exception()
		{
		}

		exception (const exception&) noexcept
		{
		}

		exception &operator = (const exception&) noexcept
		{
		}

		virtual const char *what() const noexcept
		{
			return "";
		}

	};

	class logic_error : public exception
	{

	private:
		std::string error;

	public:
		explicit logic_error(const string &error)
		: error(error)
		{
		}

		explicit logic_error(const char *error)
		: error(error)
		{
		}

		const char *what() const noexcept
		{
			return error.c_str();
		}

	};

	class out_of_range : public logic_error
	{

	public:
		explicit out_of_range(const string &error)
		: logic_error(error)
		{
		}

		explicit out_of_range(const char *error)
		: logic_error(error)
		{
		}

	};

}

#endif
