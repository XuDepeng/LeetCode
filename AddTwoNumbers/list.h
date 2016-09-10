#pragma once

#include <cassert>

template<class T>
class List {

public:
	struct Node {
		T val;
		Node* next;
		Node* prev;
	};

	class iterator
	{
	public:
		iterator() {}

		iterator & operator++()	{
			current = current->next;
			return *this;
		}
		iterator operator++(int) {
			iterator oldIter = *this;
			++(*this);
			return oldIter;
		}

		const T& operator*() const{
			return retrieve();
		}

		bool operator!=(iterator& rhs) const {
			return this->current != rhs.current;
		}

	protected:
		List<T> *l;
		Node *current;

		iterator(List<T>& lst, Node* p) : l(&lst), current(p) {}
		T& retrieve() const	{
			return current->val;
		}
		friend class List;
	};


	List() :tail(nullptr), head(nullptr), m_size(0) {
		init();
	}

	void push_back(const T& val) {
		Node* node = new Node{ val, nullptr, tail };
		tail->next = node;
		tail = node;

		++m_size;
	}

	void pop_back() {
		if (empty()) {
			return;
		}

		Node* tmp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete tmp;
		tmp = nullptr;

		--m_size;
	}

	int size() {
		return m_size;
	}

	bool empty() {
		return m_size == 0;
	}

	void clear() {
		while (!empty()) {
			pop_back();
		}
	}

	T at(int pos) {
		assert(pos < size());
;
		Node* cur = head->next;
		T val;

		while (pos>=0) {
			val = cur->val;
			cur = cur->next;
			pos--;
		}
		return val;
	}

	iterator begin(){
		iterator iter(*this, head->next);
		return iter;
	}
	iterator end(){
		iterator iter(*this, tail->next);
		return iter;
	}
private:
	void init() {
		head = tail = new Node;
		head->prev = nullptr;
	}

private:
	Node* tail;
	Node* head;

	int m_size;
};
