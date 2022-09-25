#ifndef LIST_H
#define LIST_H

#include "Node.h"

// TODO: Add insertion and deletion

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
			for (auto iter = begin(); iter != end(); ++iter)
			{
				delete iter.get();
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

		Iterator rbegin()
		{
			return Iterator(m_back);
		}

		ConstIterator cbegin() const
		{
			return ConstIterator(m_front);
		}

		ConstIterator crbegin() const
		{
			return ConstIterator(m_back);
		}

		Iterator end()
		{
			return Iterator(m_back->next);
		}

		Iterator rend()
		{
			return Iterator(m_front->prev);
		}

		ConstIterator cend() const
		{
			return ConstIterator(m_back->next);
		}

		ConstIterator crend() const
		{
			return ConstIterator(m_front->prev);
		}

		Node& front()
		{
			return *m_front;
		}

		Node& back()
		{
			return *m_back;
		}

	private:
		Node* m_front = nullptr;
		Node* m_back  = nullptr;
	};
}

#endif
