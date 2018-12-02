#ifndef JKS_ALGORITHM_H
# define JKS_ALGORITHM_H

namespace jks
{

	template<class IIterator, class OIterator>
	OutputIterator copy(IIterator iter, IIterator end, OIterator out)
	{
		while (iter != end)
		{
			*out = *iter;
			++out;
			++iter;
		}
		return out;
	};

}

#endif
