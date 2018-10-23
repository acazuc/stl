template <typename T> class list_item
{

	private:
		list_item *next;
		list_item *prev;
		T data;

	public:

};

template <typename T> class list
{

	using value_type = T;
	using reference = T&;

	private:
		list_item<T> *first;
		list_item<T> *last;
		size_type m_size;

	public:
		list()
		: first(nullptr)
		, last(nullptr)
		, m_size(0)
		{
			//Empty
		}
		void push_back(T &val)
		{
			list_item<T> *item = new list_item<T>();
			item->val = val;
			item->prev = this->last;
			item->next = nullptr;
			if (this->last)
				this->last->next = item;
			this->last = item;
			this->m_size++;
		}
		void push_front(T &val)
		{
			list_item<T> *item = new list_item<T>();
			item->val = val;
			item->prev = nullptr;
			item->next = this->first;
			if (this->first)
				this->first->prev = item;
			this->first = item;
			this->m_size++;
		}
		void pop_back(T &val)
		{
			if (!this->last)
				return;
			list_item<T> *item = last;
			this->last = item->prev;
			if (this->first == item)
				this->first = nullptr;
			delete (item);
			this->m_size--;
		}
		void pop_front(T &val)
		{
			if (!this->first)
				return;
			list_item<T> *item = first;
			this->first = item->next;
			if (this->last == item)
				this->last = nullptr;
			delete (item);
			this->m_size--;
		}
		size_type size()
		{
			return this->m_size;
		}

};
