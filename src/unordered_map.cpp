#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <list>

template <typename K, typename V>
using unordered_map_bucket = std::list<std::pair<K, V>>;
template <typename K, typename V>
using unordered_map_buckets = std::vector<unordered_map_bucket<K, V>>;

template <typename K, typename V> class unordered_map
{

	public:
		unordered_map_buckets<K, V> buckets;
		std::hash<K> hasher;
		size_t items_count;
		float load_factor;
		bool place(unordered_map_buckets<K, V> &buckets, std::pair<K, V>value)
		{
			size_t hash = this->hasher(value.first);
			unordered_map_bucket<K, V> &bucket = buckets[hash & (buckets.size() - 1)];
			for (typename unordered_map_bucket<K, V>::iterator iter = bucket.begin(); iter != bucket.end(); ++iter)
			{
				if (iter->first == value.first)
					return false;
			}
			bucket.push_front(value);
			return true;
		}

	public:
		HashMap()
		: items_count(0)
		, load_factor(1)
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
		void reserve(size_t size)
		{
			size_t n = std::max(size_t(16), npot(size * this->load_factor));
			if (n == this->buckets.size())
				return;
			unordered_map_buckets<K, V> buckets_new(npot(size));
			for (typename unordered_map_buckets<K, V>::iterator iter = this->buckets.begin(); iter != this->buckets.end(); ++iter)
			{
				for (typename unordered_map_bucket<K, V>::iterator iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
					place(buckets_new, *iter2);
			}
			this->buckets.swap(buckets_new);
		}
		bool insert(K key, V value)
		{
			if (this->items_count + 1 > this->buckets.size() * this->load_factor)
				reserve(this->buckets.size() + 1);
			if (!place(this->buckets, std::pair<K, V>(key, value)))
				return false;
			this->items_count++;
			return true;
		}
		V *get(K key)
		{
			size_t hash = this->hasher(key);
			unordered_map_bucket<K, V> &bucket = buckets[hash & (buckets.size() - 1)];
			for (typename unordered_map_bucket<K, V>::iterator iter = bucket.begin(); iter != bucket.end(); ++iter)
			{
				if (iter->first == key)
					return &iter->second;
			}
			return nullptr;
		}
		void erase(K key)
		{
			size_t hash = this->hasher(key);
			unordered_map_bucket<K, V> &bucket = buckets[hash & (buckets.size() - 1)];
			for (typename unordered_map_bucket<K, V>::iterator iter = bucket.begin(); iter != bucket.end(); ++iter)
			{
				if (iter->first == key)
				{
					this->items_count--;
					bucket.erase(iter);
					return;
				}
			}
		}
		void clear()
		{
			this->buckets.clear();
			this->items_count = 0;
		}

};

#define FACTOR 56379237599435435
#define COUNT 10000000

uint64_t nanotime()
{
	return (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch()).count());
}

int main()
{
	HashMap<int, int> hm;
	hm.load_factor = 1;
	hm.reserve(COUNT);
	uint64_t started, ended;
	started = nanotime();
	srand(time(NULL));
	for (uint32_t i = 0; i < COUNT; ++i)
		hm.insert(i, rand() * i * FACTOR);
	ended = nanotime();
	std::cout << "HashMap insert:\t" << ended - started << "(" << (ended - started) / COUNT << " per elem)" << std::endl;
	started = nanotime();
	for (uint32_t i = 0; i < COUNT; ++i)
		hm.get(i);
	ended = nanotime();
	std::cout << "HashMap find:\t" << ended - started << "(" << (ended - started) / COUNT << " per elem)" << std::endl;
	started = nanotime();
	for (uint32_t i = 0; i < COUNT; ++i)
		hm.erase(i);
	ended = nanotime();
	std::cout << "HashMap erase:\t" << ended - started << "(" << (ended - started) / COUNT << " per elem)" << std::endl;
}
