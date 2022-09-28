#ifndef LIST_H
#define LIST_H

#include "Node.h"

// TODO: Add insertion

namespace LinkedList
{
	template<typename T>
	class List
	{
	public:
		using Iterator      = typename Node<T>::Iterator;
		using ConstIterator = typename Node<T>::ConstIterator;

		~List()
		{
			for (auto iter = begin(); iter != end(); ++iter)
			{
				delete iter.get();
			}
		}

		void push_back(Node<T>* node)
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

		template<typename ...Args>
		void emplace_back(Args&& ...args)
		{
			push_back(new Node<T>(args...));
		}

		void erase(Iterator iter)
		{
			// Front check
			if (iter.get() == m_front)
			{
				m_front = iter->next;
			}
			else
			{
				iter->prev->next = iter->next;
			}

			// Back check
			if (iter.get() == m_back)
			{
				m_back = iter->prev;
			}
			else
			{
				iter->next->prev = iter->prev;
			}

			delete iter.get();
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

		Node<T>& front()
		{
			return *m_front;
		}

		Node<T>& back()
		{
			return *m_back;
		}

	private:
		Node<T>* m_front = nullptr;
		Node<T>* m_back  = nullptr;
	};
}

#endif
