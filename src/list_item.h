#ifndef JKS_LIST_ITEM_H
# define JKS_LIST_ITEM_H

namespace jks
{

	template <class T> struct list_item
	{

		list_item *next;
		list_item *prev;
		T data;

		list_item(T data, list_item *next, list_item *prev)
		: next(next)
		, prev(prev)
		, data(data)
		{
		}

	};

}

#endif
