#include <iostream>

#include "../List.h"
#include "TestCommon.h"

using LinkedList::List;
using Tests::Result;

int main(UNUSED int argc, UNUSED char** argv)
{
	List<f32> list;
	// Fill the list
	Tests::FillRand(list, 100);

	for (auto iter = list.rbegin(); iter != list.rend(); --iter)
	{
		std::cout << *iter.get() << "\n";
	}

	return Result::Success;
}