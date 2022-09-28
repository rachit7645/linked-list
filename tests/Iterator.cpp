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

	for (auto& item : list)
	{
		std::cout << item << "\n";
	}

	return Result::Success;
}