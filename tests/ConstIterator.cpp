#include <iostream>

#include "../List.h"
#include "TestCommon.h"

using Tests::Result;

int main(UNUSED int argc, UNUSED char** argv)
{
	rstd::list<f32> list;
	// Fill list
	Tests::FillRand(list, 100);

	for (const auto& item : list)
	{
		std::cout << item << "\n";
	}

	return Result::Success;
}