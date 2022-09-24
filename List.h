#ifndef LIST_H
#define LIST_H

#include "Node.h"

namespace LinkedList
{
	template<typename T>
	class List
	{
	public:
		using Node          = Node<T>;
		using Iterator      = typename Node::Iterator;
		using ConstIterator = typename Node::ConstIterator;

		~List()
		{
			for (auto i = begin(); i != end(); ++i)
			{
				delete i.get();
			}
		}

		void push_back(Node* node)
		{
			if (m_back == nullptr || m_front == nullptr)
			{
				m_back = m_front = node;
				return;
			}

			m_back->next = node;
			node->prev   = m_back;
			m_back       = node;
		}

		void emplace_back(const T& data, Node* prev = nullptr, Node* next = nullptr)
		{
			push_back(new Node(data, prev, next));
		}

		Iterator begin()
		{
			return Iterator(m_front);
		}

		ConstIterator cbegin() const
		{
			return ConstIterator(m_front);
		}

		Iterator end()
		{
			return Iterator(m_back)++;
		}

		ConstIterator cend() const
		{
			return ConstIterator(m_back)++;
		}

		Node front()
		{
			return *m_front;
		}

		Node back()
		{
			return *m_back;
		}

	private:
		Node* m_front = nullptr;
		Node* m_back  = nullptr;
	};
}

#endif
