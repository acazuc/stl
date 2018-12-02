#ifndef JKS_UNORDERED_MAP_H
# define JKS_UNORDERED_MAP_H

# include "unordered_map_iterator.h"
# include "functional.h"
# include "vector.h"
# include "list.h"

namespace jks
{

	template <class Key, class T, class Hash = hash<Key>, class Pred = equal_to<Key>, class Alloc = allocator<pair<const Key, T>>> class unordered_map
	{

	public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = pair<const key_type, mapped_type>;
		using hasher = Hash;
		using key_equal = Pred;
		using allocator_type = Alloc;
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;
		using iterator = unordered_map_iterator<value_type>;
		using const_iterator = unordered_map_iterator<const value_type>;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using bucket_type = list<value_type>;

	public:
		vector<bucket_type> m_buckets;
		hasher m_hasher;
		size_t m_items_count;
		float m_load_factor;
		bool place(vector<bucket_type> &buckets, value_type value)
		{
			size_t hash = m_hasher(value.first);
			bucket_type &bucket = buckets[hash & (bucket_count() - 1)];
			for (typename bucket_type::iterator iter = bucket.begin(); iter != bucket.end(); ++iter)
			{
				if (iter->first == value.first)
					return false;
			}
			bucket.push_front(value);
			return true;
		}

	public:
		unordered_map()
		: m_items_count(0)
		, m_load_factor(1)
		{
			//Empty
		}

		size_t npot(size_t n)
		{
			n--;
			n |= n >> 1;
			n |= n >> 2;
			n |= n >> 4;
			n |= n >> 8;
			n |= n >> 16;
			if (sizeof(n) > 32)
				n |= n >> 32;
			return n + 1;
		}

		void rehash(size_type n)
		{
			vector<bucket_type> buckets_new(npot(n));
			for (typename vector<bucket_type>::iterator iter = m_buckets.begin(); iter != m_buckets.end(); ++iter)
			{
				for (typename bucket_type::iterator iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
					place(buckets_new, *iter2);
			}
			m_buckets.swap(buckets_new);
		}

		void reserve(size_type n)
		{
			size_t len = std::max(size_t(16), npot(n * m_load_factor));
			if (len <= m_buckets.size())
				return;
			rehash(len);
		}

		bool insert(key_type key, mapped_type value)
		{
			if (m_items_count + 1 > m_buckets.size() * m_load_factor)
				reserve(m_buckets.size() + 1);
			if (!place(m_buckets, value_type(key, value)))
				return false;
			m_items_count++;
			return true;
		}

		pair<iterator, bool> emplace(key_type key, mapped_type value)
		{
			//
		}

		iterator find(key_type key)
		{
			size_t hash = m_hasher(key);
			bucket_type &bucket = m_buckets[hash & (bucket_count() - 1)];
			for (typename bucket_type::iterator iter = bucket.begin(); iter != bucket.end(); ++iter)
			{
				if (key_equal(iter->first, key))
					return iterator(&iter->second);
			}
			return end();
		}

		void erase(key_type key)
		{
			size_t hash = m_hasher(key);
			bucket_type &bucket = m_buckets[hash & (bucket_count() - 1)];
			for (typename bucket_type::iterator iter = bucket.begin(); iter != bucket.end(); ++iter)
			{
				if (key_equal(iter->first, key))
				{
					m_items_count--;
					bucket.erase(iter);
					return;
				}
			}
		}

		void clear()
		{
			m_buckets.clear();
			m_items_count = 0;
		}

		iterator begin()
		{
			if (!m_buckets.size())
				return end();
			return iterator(m_buckets.begin());
		}

		iterator end()
		{
			return iterator(m_buckets.end(), typename bucket_type::iterator(nullptr));
		}

		const_iterator cbegin()
		{
			if (!m_buckets.size())
				return cend();
			return const_iterator(m_buckets.cbegin());
		}

		const_iterator cend()
		{
			return const_iterator(m_buckets.cend(), typename bucket_type::const_iterator(nullptr));
		}

		size_type bucket_count() const noexcept
		{
			return m_buckets.size();
		}

	};

}

#endif
