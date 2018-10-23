template <typename T> class vector_iterator;

template <typename T> class vector
{

	using value_type = T;
	using reference = T&;
	using size_type = size_t;
	using iterator = vector_iterator<T>;

	private:
		T *m_data;
		size_type m_size;
		size_type m_capacity;

	public:
		vector()
		{
			m_data = nullptr;
			m_size = 0;
			m_capacity = 0;
		}
		void reserve(size_type len)
		{
			if (len <= capacity())
				return;
			T *new_data = malloc(sizeof(*data()) * len); //avoid calling constructors
			if (!new_data)
				throw std::exception();
			memcpy(new_data, data(), size() * sizeof(*data()));
			free(data());
			this->m_data = new_data;
			this->m_capacity = len;
		}
		void resize(size_type len)
		{
			if (len == size())
				return;
			if (len < size())
			{
				m_size = len;
				return;
			}
			reserve(len);
			for (size_type i = size(); i < len; ++i)
				m_data[i] = T();
			this->m_size = len;
		}
		void push_back(T &val)
		{
			size_type tmp = size();
			resize(size() + 1);
			m_data[tmp] = val;
		}
		void pop_back()
		{
			if (!size())
				return;
			resize(size() - 1);
		}
		void clear()
		{
			resize(0);
		}
		T &operator [] (size_type idx)
		{
			return m_data[idx];
		}
		iterator<T> begin()
		{
			return iterator<T>(data());
		}
		iterator<T> end()
		{
			return iterator<T>(data() + size());
		}
		T *data() {return this->values;};
		size_type size() {return this->m_size;};
		size_type capacity() {return this->m_capacity;};

};
