#include <algorithm>
#include <iostream>

#include "../List.h"
#include "TestCommon.h"

using LinkedList::Node;
using LinkedList::List;
using Tests::Result;

int main(UNUSED int argc, UNUSED char** argv)
{
	List<f32> list;
	// Fill list
	Tests::FillRand(list, 100);

	std::for_each(list.cbegin(), list.cend(), [] (const Node<f32>& node)
	{
		std::cout << node << "\n";
	});

	return Result::Success;
}