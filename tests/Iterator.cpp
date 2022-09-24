#include <algorithm>
#include <iostream>

#include "../List.h"
#include "TestCommon.h"

using LinkedList::List;
using LinkedList::Node;
using Tests::Result;

int main(UNUSED int argc, UNUSED char** argv)
{
	List<f32> list;
	Tests::FillList(list, Tests::NUM_ITEMS);

	std::for_each(list.begin(), list.end(), [] (Node<f32> node)
	{
		std::cout << node << "\n";
	});

	return Result::Success;
}