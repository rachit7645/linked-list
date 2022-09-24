#ifndef LIST_H
#define LIST_H

#include "Node.h"

namespace LinkedList
{
	template<typename T>
	class List
	{
	public:
		using Node     = Node<T>;
		using Iterator = typename Node::Iterator;

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

		Iterator end()
		{
			return Iterator(m_back)++;
		}

		Iterator rbegin()
		{
			return Iterator(m_back);
		}

		Iterator rend()
		{
			return Iterator(m_front)--;
		}

	private:
		Node* m_front = nullptr;
		Node* m_back  = nullptr;
	};
}

#endif
