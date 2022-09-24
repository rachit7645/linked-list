#ifndef NODE_H
#define NODE_H

#include <iterator>
#include <iostream>

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
			using iterator_category = std::forward_iterator_tag;
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

		class ConstIterator
		{
		public:
			using iterator_category = std::forward_iterator_tag;
			using difference_type   = std::ptrdiff_t;
			using value_type        = const Node;
			using pointer           = const Node*;
			using reference         = const Node&;

			ConstIterator(Node* node)
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

			ConstIterator& operator++()
			{
				m_node = m_node->next;
				return *this;
			}

			ConstIterator operator++(int)
			{
				ConstIterator tmp = *this;
				++(*this);
				return tmp;
			}

			ConstIterator& operator--()
			{
				m_node = m_node->prev;
				return *this;
			}

			ConstIterator operator--(int)
			{
				ConstIterator tmp = *this;
				--(*this);
				return tmp;
			}

			friend bool operator==(const ConstIterator& a, const ConstIterator& b)
			{
				return a.m_node == b.m_node;
			}

			friend bool operator!=(const ConstIterator& a, const ConstIterator& b)
			{
				return a.m_node != b.m_node;
			}

		private:
			Node* m_node;
		};

		friend std::ostream& operator<<(std::ostream& os, const Node& node)
		{
			os << "Data: " << node.data << "\n";

			if (node.prev != nullptr)
			{
				os << "Prev: " << node.prev << "\n";
			}

			if (node.next != nullptr)
			{
				os << "Next: " << node.next << "\n";
			}

			return os;
		}
	};
}

#endif