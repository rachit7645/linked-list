#ifndef NODE_H
#define NODE_H

#include <iterator>

namespace LinkedList
{
	template<typename T>
	struct Node
	{
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
				return reinterpret_cast<Iterator&>(m_node = m_node->next);
			}

			Iterator operator++(int)
			{
				Iterator tmp = *this;
				++(*this);
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

		Iterator begin()
		{
			return Iterator(this);
		}

		Iterator end()
		{
			// Assume that the end is the next item
			auto end = Iterator(next);
			// If not null, go to next
			while (end != nullptr)
			{
				end = Iterator(end->next);
			}
			// Return the end
			return end;
		}
	};
}

#endif