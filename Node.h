#ifndef NODE_H
#define NODE_H

#include <iterator>

namespace LinkedList
{
	template<typename T>
	struct Node
	{
		Node(const T& data, Node* next, Node* prev)
			: data(data),
			  prev(prev),
			  next(next)
		{
		}

		T     data;
		Node* prev;
		Node* next;

		class Iterator
		{
		public:
			using iterator_category = std::bidirectional_iterator_tag;
			using difference_type   = std::ptrdiff_t;
			using value_type        = Node;
			using pointer           = Node*;
			using reference         = Node&;

			Iterator(Node* node)
				: m_node(node)
			{
			}

			pointer get()
			{
				return m_node;
			}

			reference operator*() const
			{
				return *m_node;
			}

			pointer operator->()
			{
				return m_node;
			}

			Iterator& operator++()
			{
				m_node = m_node->next;
				return *this;
			}

			Iterator operator++(int)
			{
				Iterator tmp = *this;
				++(*this);
				return tmp;
			}

			Iterator& operator--()
			{
				m_node = m_node->prev;
				return *this;
			}

			Iterator operator--(int)
			{
				Iterator tmp = *this;
				--(*this);
				return tmp;
			}

			friend bool operator==(const Iterator& a, const Iterator& b)
			{
				return a.m_node == b.m_node;
			}

			friend bool operator!=(const Iterator& a, const Iterator& b)
			{
				return a.m_node != b.m_node;
			}

		private:
			Node* m_node;
		};
	};
}

#endif