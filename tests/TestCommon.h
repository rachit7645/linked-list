#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <iostream>

#include "../Node.h"

#ifdef __CLION_IDE__
#define UNUSED [[maybe_unused]]
#else
#define UNUSED __attribute__((unused))
#endif

using f32 = float;
using f64 = double;

constexpr f64 PI = 22.0 / 7.0;

namespace Tests
{
	enum Result : int
	{
		Success = 0,
		Failure = -1
	};

	template<typename T>
	void PrintNode(LinkedList::Node<T>* node)
	{
		std::cout << "\nData: " << node->data << "\n";

		if (node->prev != nullptr)
		{
			std::cout << "Prev: " << node->prev << "\n";
		}

		if (node->next != nullptr)
		{
			std::cout << "Next: " << node->next << "\n";
		}
	}
}

#endif
