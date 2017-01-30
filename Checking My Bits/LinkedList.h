#pragma once

template<typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node *prev, *next;
		Node() : prev(nullptr), next(nullptr) {}
	};

	Node *head, *tail;
	size_t count;
public:

	//RO5
	LinkedList() : head(nullptr), tail(nullptr), count(0) {};

	~LinkedList() { clear(); };
	//LinkedList(const LinkedList &);
	//LinkedList(LinkedList &&);
	//LinkedList &operator=(const LinkedList &);
	//LinkedList &operator=(LinkedList &&);

	struct iterator {
		Node *_Ptr;

		iterator &operator++(int) {
			_Ptr = _Ptr->next;
			return *this;
		}

		const T *operator->() { return &_Ptr->data; }
		const T &operator*() { return _Ptr->data; }

		bool operator!=(const iterator &o) { return _Ptr != o._Ptr; }
	};
	T &at(size_t idx) {
		assert(idx < count);
		auto t = head;
		for (int i = 0; i <= idx; ++i) {
			t = head->next;
		}
	}
	iterator begin() {
		iterator it;
		it._Ptr = head;
		return *this;
	}
	iterator end() {
		iterator it;
		it._Ptr = nullptr;
		return *this;
	}

	T &front() { return head->data; }
	T &back() { return tail->data; }

	T &operator[](size_t idx) { return T[idx]; }

	const T &operator[](size_t idx) const { return T[idx]; };

	const T &front() const { return head->data; }
	const T &back() const { return tail->data; }

	void add_front(const T &val) {
		auto new_node = new Node;
		new_node->data = val;

		if (count == 0) head = tail = new_node;
		else {
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		};
		count++;
	}

	void add_back(const T &val) {
		auto new_node = new Node;
		new_node->data = val;

		if (count == 0) head = tail = new_node;
		else {
			new_node->prev = tail;
			tail->next = new_node;
			tail = new_node;
		}
		count++;
	}

	void del_front() {
		if (count == 1) {
			delete head;
			head = tail = nullptr;

		}

		else if (count > 1) {
			auto toDelete = head;
			head = head->next;
			head->prev = nullptr;
			delete toDelete;
		}

	}

	void del_back() {
		if (count == 1) {
			delete head;
			head = tail = nullptr;
		}

		else if (count > 1) {
			auto toDelete = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete toDelete;
		}
	}

	void clear() {
		auto t = head;

		while (t != nullptr) {
			auto toDel = t;
			t = t->next;
			delete toDel;
		}
	}

	bool empty() const { return count > 0 };
	size_t size() const { return count; };

	

};