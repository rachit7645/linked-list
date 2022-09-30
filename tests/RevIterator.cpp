#include <iostream>

#include "../List.h"
#include "TestCommon.h"

using Tests::Result;

int main(UNUSED int argc, UNUSED char** argv)
{
	rstd::list<f32> list;
	// Fill the list
	Tests::FillRand(list, 100);

	for (auto iter = list.rbegin(); iter != list.rend(); --iter)
	{
		std::cout << *iter << "\n";
	}

	return Result::Success;
}