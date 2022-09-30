#ifndef NODE_H
#define NODE_H

#include <iterator>
#include <iostream>

namespace rstd
{
	template<typename T>
	struct node
	{
		node(const T& data, node* prev = nullptr, node* next = nullptr)
			: data(data),
			  prev(prev),
			  next(next)
		{
		}

		node(T&& data, node* prev = nullptr, node* next = nullptr)
			: data(std::move(data)),
		  	  prev(prev),
		  	  next(next)
		{
		}

		node(const node& other)
			: data(other.data),
			  prev(other.prev),
			  next(other.next)
		{
		}

		node(node&& other)
			: data(std::move(other.data)),
			  prev(std::move(other.prev)),
			  next(std::move(other.next))
		{
		}

		node& operator=(const node& other)
		{
			data = other.data;
			prev = other.prev;
			next = other.next;

			return *this;
		}

		node& operator=(node&& other)
		{
			data = std::move(other.data);
			prev = std::move(other.prev);
			next = std::move(other.next);

			return *this;
		}

		T     data = {};
		node* prev = nullptr;
		node* next = nullptr;

		class iterator
		{
		public:
			using iterator_category = std::bidirectional_iterator_tag;
			using difference_type   = std::ptrdiff_t;
			using value_type        = node;
			using pointer           = node*;
			using reference         = node&;

			iterator(node* node)
				: m_node(node)
			{
			}

			iterator(const iterator& other)
				: m_node(other.m_node)
			{
			}

			iterator(iterator&& other)
				: m_node(std::move(other.m_node))
			{
			}

			iterator& operator=(const iterator& other)
			{
				m_node = other.m_node;

				return *this;
			}

			iterator& operator=(iterator&& other)
			{
				m_node = std::move(other.m_node);

				return *this;
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

			iterator& operator++()
			{
				m_node = m_node->next;
				return *this;
			}

			iterator operator++(int)
			{
				iterator tmp = *this;
				++(*this);
				return tmp;
			}

			iterator& operator--()
			{
				m_node = m_node->prev;
				return *this;
			}

			iterator operator--(int)
			{
				iterator tmp = *this;
				--(*this);
				return tmp;
			}

			friend bool operator==(const iterator& a, const iterator& b)
			{
				return a.m_node == b.m_node;
			}

			friend bool operator!=(const iterator& a, const iterator& b)
			{
				return a.m_node != b.m_node;
			}

		private:
			node* m_node;
		};

		class const_iterator
		{
		public:
			using iterator_category = std::bidirectional_iterator_tag;
			using difference_type   = std::ptrdiff_t;
			using value_type        = const node;
			using pointer           = const node*;
			using reference         = const node&;

			const_iterator(node* node)
				: m_node(node)
			{
			}

			const_iterator(const const_iterator& other)
				: m_node(other.m_node)
			{
			}

			const_iterator(const_iterator&& other)
				: m_node(std::move(other.m_node))
			{
			}

			const_iterator& operator=(const const_iterator& other)
			{
				m_node = other.m_node;

				return *this;
			}

			const_iterator& operator=(const_iterator&& other)
			{
				m_node = std::move(other.m_node);

				return *this;
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

			const_iterator& operator++()
			{
				m_node = m_node->next;
				return *this;
			}

			const_iterator operator++(int)
			{
				const_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			const_iterator& operator--()
			{
				m_node = m_node->prev;
				return *this;
			}

			const_iterator operator--(int)
			{
				const_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			friend bool operator==(const const_iterator& a, const const_iterator& b)
			{
				return a.m_node == b.m_node;
			}

			friend bool operator!=(const const_iterator& a, const const_iterator& b)
			{
				return a.m_node != b.m_node;
			}

		private:
			node* m_node;
		};

		friend std::ostream& operator<<(std::ostream& os, const node& node)
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