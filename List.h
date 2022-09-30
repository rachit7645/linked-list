#ifndef LIST_H
#define LIST_H

#include "Node.h"

// TODO: Add insertion

namespace rstd
{
	template<typename T>
	class list
	{
	public:
		using iterator      = typename node<T>::iterator;
		using const_iterator = typename node<T>::const_iterator;

		list() = default;

		list(list&& other)
			: m_front(std::move(other.m_front)),
			  m_back(std::move(other.m_back))
		{
		}

		~list()
		{
			for (auto iter = begin(); iter != end(); ++iter)
			{
				delete iter.get();
			}
		}

		list& operator=(list&& other)
		{
			m_front = std::move(other.m_front);
			m_back  = std::move(other.m_back);
		}

		void push_back(node<T>* node)
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
			push_back(new node<T>(args...));
		}

		void erase(iterator iter)
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

		iterator begin()
		{
			return iterator(m_front);
		}

		iterator rbegin()
		{
			return iterator(m_back);
		}

		const_iterator cbegin() const
		{
			return const_iterator(m_front);
		}

		const_iterator crbegin() const
		{
			return const_iterator(m_back);
		}

		iterator end()
		{
			return iterator(m_back->next);
		}

		iterator rend()
		{
			return iterator(m_front->prev);
		}

		const_iterator cend() const
		{
			return const_iterator(m_back->next);
		}

		const_iterator crend() const
		{
			return const_iterator(m_front->prev);
		}

		node<T>& front()
		{
			return *m_front;
		}

		node<T>& back()
		{
			return *m_back;
		}

	private:
		node<T>* m_front = nullptr;
		node<T>* m_back  = nullptr;
	};
}

#endif
